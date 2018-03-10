#include <dht.h>
#define dht_pin 4
dht DHT;
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  Serial.println("Humidity and temp");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Humidity");
  Serial.println(DHT.humidity);
  Serial.print("%");
  Serial.print(" Temp ");
  Serial.println(DHT.temperature);
  Serial.println("C");
  delay(2000);
  if(DHT.temperature <=22) digitalWrite(7,HIGH);
  else digitalWrite(7,LOW);
  if(DHT.temperature >=23) digitalWrite(8,HIGH);
  else digitalWrite(8,LOW);
}
