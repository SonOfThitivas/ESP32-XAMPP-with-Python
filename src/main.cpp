/*ArduinoGetStarted
    ESP32 - MySQL:
        https://esp32io.com/tutorials/esp32-mysql
    Arduino - DHT22
        https://arduinogetstarted.com/tutorials/arduino-dht22
*/

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT22_PIN 23 // any pin

DHT dht22(DHT22_PIN, DHT22);

// connect the wifi
const char WIFI_SSID[] = "YOUR_WIFI_SSID";
const char WIFI_PASSWORD[] = "YOUR_WIFI_PASSWORD";

String HOST_NAME = "http://192.168.1.37:8080"; // change to your PC's IP address that deploys with python server
String PATH_NAME   = "/";                      // any path
String queryString;                            // contain the values from the DHT22 to request

void request(String QueryString){              // request function, parameter is the query string contains the values
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  HTTPClient http;
  String temp = HOST_NAME + PATH_NAME + QueryString; // the request
  Serial.println(temp);

  http.begin(temp); //HTTP
  int httpCode = http.GET();
  Serial.println(httpCode);

  // httpCode will be negative on error
  if(httpCode > 0) {
    // file found at server
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

void setup()
{
  Serial.begin(115200);
  
  dht22.begin(); // initialize the DHT22 sensor

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Connecting the wifi
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

}

void loop()
{

  delay(2000); // every 2 seconds

  // read humidity
  float humi = dht22.readHumidity();
  // read temperature as Celsius
  float tempC = dht22.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht22.readTemperature(true);

  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(tempF))
  {
    Serial.println("Failed to read from DHT22 sensor!");
  }
  else
  {
    queryString = "?query=" + String(humi) + "%," + String(tempC) + "," + String(tempF); // contain the values
    request(queryString); // call request function
  }
}
