#include <ESP8266WiFi.h>
#include "DHT.h"
#define DHTPIN D2     // what pin we're connected to
#define DHTTYPE DHT11   // define type of sensor DHT 11
DHT dht (DHTPIN, DHTTYPE);

const char* ssid     = "xxxxxxxxx";//Enter the ssid of your router
const char* password = "yyyyyyyyyy";//Enter the password of your router

const char* host = "api.thingspeak.com";
const char* privateKey = "zzzzzzzz"; //place your write api key
float h,t;


void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() 
{
  delay(15000);
  h = dht.readHumidity();
  t = dht.readTemperature();

   if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Upload_to_Cloud();  
}


/*.....................................Uploading to Cloud...............................*/

void Upload_to_Cloud()
{
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/update";
  url += "?api_key=";
  url += privateKey;
  url += "&field1=";
  url += t;
  url += "&field2=";
  url += h;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(1000);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
}


