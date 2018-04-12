

/*  Connects to the home WiFi network
 *  Asks some network parameters
 *  Sends and receives message from the server in every 2 seconds
 *  Communicates: wifi_server_01.ino
 *  Author - Shubham Sinha
 */ 
#include <SPI.h>
#include <ESP8266WiFi.h>

int led = D4;
char ssid[] = "Shubham";           // SSID of your home WiFi
char pass[] = "123456789";            // password of your home WiFi

unsigned long askTimer = 0;

IPAddress server(192,168,43,111);       // the fix IP address of the server
WiFiClient client;

void setup() {

  Serial.begin(115200);               // only for debug
 // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
//  Serial.println("Connected to wifi");
//  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
//  Serial.print("IP: ");     Serial.println(WiFi.localIP());
//  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
//  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
//  Serial.print("SSID: "); Serial.println(WiFi.SSID());
//  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  pinMode(led, OUTPUT);

}

void loop () {
  client.connect(server, 80);   // Connection to the server
  digitalWrite(led, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  Serial.println("Hello server! Are you sleeping?\r");  // sends the message to the server
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: ");
  Serial.println(answer);
  client.flush();
  digitalWrite(led, HIGH);
  delay(1000);                  // client will trigger the communication after ome seconds
}
