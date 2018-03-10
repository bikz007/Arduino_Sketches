int a=13;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  digitalWrite(a, HIGH);
  delay(50);
  digitalWrite(12, HIGH);
  delay(50);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(a, LOW);
  delay(50);
  digitalWrite(12, LOW);
  delay(50);
  digitalWrite(9, LOW);
  delay(50);
}
