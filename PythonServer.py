# Simple Python Web Server (howCode):
# https://www.youtube.com/watch?v=hFNZ6kdBgO0

# Extract Data from Database using MySQL-Connector and XAMPP in Python (sravankumar_171fa07058, GeeksforGeeks) : 
# https://www.geeksforgeeks.org/extract-data-from-database-using-mysql-connector-and-xampp-in-python/

# Retrieving parameters from a URL (Alan W. Smith, systempuntoout):
# https://stackoverflow.com/a/5075477

from http.server import HTTPServer, BaseHTTPRequestHandler
import mysql.connector
from urllib.parse import urlparse, parse_qs

class Serv(BaseHTTPRequestHandler):
    
    def do_GET(self):    # when get the requesyt
        print(self.path)    # for debugging
        
        if self.path[0] == '/':        # start with / of the path
            print("Pass")   # for debugging
            
            try:                       # handling the error
                # take the values from the request
                parsed_url = urlparse(self.path)
                print(parsed_url)   # for debugging
                captured_value = parse_qs(parsed_url.query)['query'][0]
                print(captured_value)   # fr debugging
                
                # connect to the MySQL server
                conn_object = mysql.connector.connect(          # you can customize it
                    host = "localhost", user="root",
                    password = "", database = "30Mar2024"
                )

                cursor = conn_object.cursor()
                
                # insert the values to the table (esp32dht)
                query1 = "INSERT INTO esp32dht (humidity, celsius, fahrenheit) VALUES (%s, %s, %s)"
                val = captured_value.split(',') # seperate the values be an array
                
                # collect to the table
                cursor.execute(query1, val) 
                conn_object.commit()
                
                print("Pass")   # for debugging

                self.send_response(200)
                print("Successfully")   # for debugging

            except mysql.connector.Error as err:
                print("Something went wrong: {}".format(err))
                print("Error")
                self.send_response(404) 
            
            self.end_headers()

mylocalhost = "192.168.1.37" # PC's IP address
port = 8080                  # any port you like

httpd = HTTPServer((mylocalhost, port), Serv)
httpd.serve_forever()