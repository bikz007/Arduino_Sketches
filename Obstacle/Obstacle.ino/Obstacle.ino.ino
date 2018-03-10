int lm = 8;
int rm = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(lm, OUTPUT);
  pinMode(rm, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
}
void Stop() {
  digitalWrite(lm, 0);
  digitalWrite(rm, 0);
}
void forward() {
  digitalWrite(lm, 1);
  digitalWrite(rm, 1);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  digitalWrite(6, 0);
  delayMicroseconds(3);
  digitalWrite(6, 1);
  delayMicroseconds(3);
  digitalWrite(6, 0);

  int b = pulseIn(5, HIGH);
  int y = ((.033 * b) / 2);
  if (y >50){
    forward();
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
  }
  else{
    Stop();
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
  }
}
