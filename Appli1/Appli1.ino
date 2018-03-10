void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sw=analogRead(A4);
  int ldr=analogRead(A0);
  /*Serial.print("\tLDr= ");
  Serial.print(ldr);
  Serial.print("\tSW= ");
  Serial.println(sw);*/
  if(ldr<200 and sw>=929)
  {
    Serial.print("\t=======***=======");
    Serial.print("\n\t Bro I'm Sleepy!!\n\t   GOOD NIGHT!!");
    Serial.print("\n\t=======***=======");
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
  }
  else if(ldr>=200 and sw>=929)
  {
    Serial.print("\t======***======");
    Serial.print("\n\t  HELLO BRO!!");
    Serial.print("\n\t======***======");
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
  }
  else
  {
    Serial.println();
  }
}
