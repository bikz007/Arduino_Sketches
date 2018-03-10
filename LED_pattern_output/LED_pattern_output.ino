void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(1,OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  digitalWrite(1,HIGH);
  delay(10);
  digitalWrite(12, HIGH);
  delay(10);
  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(10);
  digitalWrite(12, LOW);
  delay(10);
  digitalWrite(9, LOW);
  delay(10);
}
