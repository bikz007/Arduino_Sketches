void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A2,INPUT);
  pinMode(A4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=analogRead(A0);
  int b=analogRead(A2);
  int c=analogRead(A4);
  Serial.print("The value of LDR is = ");
  Serial.print(a);
  Serial.print("\tThe value of POT is = ");
  Serial.print(b);
  Serial.print("\tThe value of SWITCH is = ");
  Serial.println(c);
}
