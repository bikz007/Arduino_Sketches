#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
WiFiUDP Udp;
char ReceivingBuffer[40];
unsigned int localport=49999;
const char * ssid="use-your-own";
const char * passwd="monideep";
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  delay(100);

  
  WiFi.begin(ssid,passwd);
  
  Serial.println(WiFi.status());
  Serial.print("Ip :");
  Serial.println(WiFi.localIP());
  
  Udp.begin(localport);
}

void loop() {
  int ps=Udp.parsePacket();
  if(ps > 0)
  {
    IPAddress remote=Udp.remoteIP();
    unsigned int port =Udp.remotePort();
    Udp.read(ReceivingBuffer,40);

    
    String logic=String(ReceivingBuffer);
    Serial.println(logic);
    if(logic.equals("ON"))
    {
      digitalWrite(13,1);  
    }
    if(logic.equals("OFF"))
    {
      digitalWrite(13,0);  
    }
    for(int i=0;i<40;i++)
      ReceivingBuffer[i]=0;
  }

}
