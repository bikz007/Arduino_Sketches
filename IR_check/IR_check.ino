int left=A0;
int right=A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=analogRead(left);
  int b=analogRead(right);
  Serial.print(a);
  Serial.print("\t");
  Serial.println(b);
}
