#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "xxxxxxxx"; // place wifi ssid
const char* password = "yyyyyyyyyy";// place wifi password

const char* host = "api.msg91.com";
const int httpsPort = 443;

const char* fingerprint = "CF 05 98 89 CA FF 8E D8 5E 5C E0 C2 E4 F7 E6 C3 C7 50 DD 5C"; // replace fingerprint if avaialble

String data;
String url;
String line;

// note: replace url1 with working url path of msg91
//replace mobiles variable with your mobile number for testing
 
String url1="/api/sendhttp.php?sender=MSGIND&route=4&mobiles=7702602236&authkey=191733AzlOSig9aM5a507740&country=91&message=testing";


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
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


void loop() {
  url=url1;
  cloud();
 
}

void cloud(){
   WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  if (client.verify(fingerprint, host)) {
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate doesn't match");
  }

  
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266 CI successfull!");
  } else {
    Serial.println("esp8266 CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}
 


