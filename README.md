# ESP32-XAMPP-with-Python
## 🤔 **Overview**

This project demonstrates how to use an ESP32 to send data to a MySQL server using XAMPP and Python. In the following example, a program is used to measure temperature and humidity using a DHT22 sensor.

## 🧰 **Tools**

- [XAMPP](https://www.apachefriends.org/) for MySQL Server
- 💻 Editor
    - This example uses [Visual Studio Code](https://code.visualstudio.com/) (you can also use [Arduino IDE](https://www.arduino.cc/en/software))
    - VScode must have [PlatformIO IDE](https://docs.platformio.org/en/latest/) installed for ESP32 programming
- 🔨 Hardware
    - ESP32 board
    - DHT22 sensor

## ⏰ **Operation**

1. Start MySQL Server and create a database to store data
2. Run [PythonServer.py](../blob/main/PythonServer.py) to receive values from the sensor by receiving requests and sending data to the MySQL server
3. Upload the ESP32 program to measure temperature and humidity and send a request with the measured values

## 🖼️ **Images**

<div align="center">
  <img src="https://github.com/SonOfThitivas/ESP32-XAMPP-with-Python/assets/83740933/02e1f0b7-b060-449d-bc39-57dd6a7194ab" width="500"/>
</div>

![image](https://github.com/SonOfThitivas/ESP32-XAMPP-with-Python/assets/83740933/8aeb10a5-8b4b-4522-bd02-75cc977e4fd8)


## 📖 **Conclusion**

The sources of information are commented in the code.

**Thank you for the equipment from the stores:**

1. <img src="https://th.bing.com/th?id=ODLS.89188d41-8c11-42e9-9942-842f77220682&amp;w=32&amp;h=32&amp;qlt=93&amp;pcl=fffffa&amp;o=6&amp;pid=1.2" height="32" width="32" alt="Global web icon" class="rms_img" data-bm="44"> ARDUINO in Thailand: [http://www.arduino.in.th/](http://www.arduino.in.th/)
2. <img src="https://th.bing.com/th?id=ODLS.414a449b-7b4c-4c7b-a96f-33c7a91e102e&amp;w=32&amp;h=32&amp;qlt=90&amp;pcl=fffffa&amp;o=6&amp;pid=1.2" height="32" width="32" alt="Global web icon" class="rms_img" data-bm="41"> Arduitronics: [https://www.arduitronics.com/](https://www.arduitronics.com/)
