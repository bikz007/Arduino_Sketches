********************************************
14CORE ULTRASONIC DISTANCE SENSOR CODE TEST
********************************************
*/
//5-D1
//4-D2
#define TRIGGER 5
#define ECHO    4

// NodeMCU Pin D1 > TRIGGER | Pin D2 > ECHO

void setup() {
  
  Serial.begin (115200);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGER, LOW);
  
  int duration = pulseIn(ECHO, HIGH);
  int distance = ((.033*duration)/2);
  
  Serial.print(distance);
  Serial.println(" Centimeters");
  delay(1000);
}
