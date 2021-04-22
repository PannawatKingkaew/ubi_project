#include <ESP8266WiFi.h>
#define LED 13
const char* ssid = "ST-APARTMENT 3";
const char* password = "0988549374";
unsigned char status_led = 0;
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}
void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  while (!client.available())
  {
    delay(1);
  }
  String req = client.readStringUntil('\r');
  client.flush();
  if (req.indexOf("/darkred") != -1)
  {
    
    Serial.print("139,0,0");
  }
  else if (req.indexOf("/darkblue") != -1)
  {
    Serial.print("0,0,139");
  }
  else if (req.indexOf("/darkgreen") != -1)
  {
    Serial.print("0,100,0");
  }
  else if (req.indexOf("/darkyellow") != -1)
  {
    Serial.print("204,204,0");
  }
  else if (req.indexOf("/deeppink") != -1)
  {
    Serial.print("255,20,147");
  }
  else if (req.indexOf("/darkviolet") != -1)
  {
    Serial.print("148,0,211");
  }
  String web = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r \n\r\n";
  web += "<html>\r\n";
  web += "<body>\r\n";
  web += "<h1 style='text-align: center'>LED through Wifi</h1>\r\n";
  web += "<a href=\"/darkred\">\r\n";
  web += "<button style='background-color:rgb(139,0,0);width:49.7%;height:500px;'></button>\r\n";
  web += "</a>\r\n";
  web += "<a href=\"/darkblue\">\r\n";
  web += "<button style='background-color:rgb(0,0,139);width:49.7%;height:500px;'></button>\r\n";
  web += "</a>\r\n";
  web += "<a href=\"/darkgreen\">\r\n";
  web += "<button style='background-color:rgb(0,100,0);width:49.7%;height:500px;'></button>\r\n";
  web += "</a>\r\n";
  web += "<a href=\"/darkyellow\">\r\n";
  web += "<button style='background-color:rgb(204,204,0);width:49.7%;height:500px;'></button>\r\n";
  web += "</a>\r\n";
  web += "<a href=\"/deeppink\">\r\n";
  web += "<button style='background-color:rgb(255,20,147);width:49.7%;height:500px;'></button>\r\n";
  web += "</a>\r\n";
  web += "<a href=\"/darkviolet\">\r\n";
  web += "<button style='background-color:rgb(148,0,211);width:49.7%;height:500px;'></button>\r\n";
  web += "</a>\r\n";
  web += "</body>\r\n";
  web += "</html>\r\n";
  client.print(web);
}
