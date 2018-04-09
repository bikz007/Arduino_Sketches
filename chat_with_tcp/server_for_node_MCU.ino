
/*  Connects to the home WiFi network
 *  Asks some network parameters
 *  Starts WiFi server with fix IP and listens
 *  Receives and sends messages to the client
 *  Communicates: client for node MCU.ino
 *  Author - Shubham Sinha
 */

#include <SPI.h>
#include <ESP8266WiFi.h>
int led = D4;
char ssid[] = "Shubham";               // SSID of your home WiFi
char pass[] = "123456789";               // password of your home WiFi

WiFiServer server(80);      

void setup() {
  Serial.begin(115200);                   // only for debug
  //WiFi.config(ip, gateway, subnet); // forces to use the fix IP

   //Connect to WiFi network
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
//   Start the server
  server.begin();
  Serial.println("Server started");
// 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  pinMode(led, OUTPUT);
//   WiFiManager wifiManager;
//  //1wifiManager.resetSettings(); 
//  wifiManager.autoConnect("NodeMCU");
}

void loop () {
  WiFiClient client = server.available();

  if (client) {  //boolean
    if (client.connected()) {
      digitalWrite(led, LOW);        
      Serial.println(".");
      String request = client.readStringUntil('\r');    // receives the message from the client
      Serial.print("From client: "); 
      Serial.println(request);
      client.flush();
      Serial.println("Hi client! No, I am listening.\r"); // sends the answer to the client
      digitalWrite(led, HIGH);
    }
    client.stop();                // terminates the connection with the client
  }
}
