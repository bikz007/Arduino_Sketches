void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float a=analogRead(A0);
  Serial.print("The value of temperature is = ");
  Serial.println((a*500)/1024);
}
