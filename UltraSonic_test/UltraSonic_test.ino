void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  pinMode(5,INPUT); //echopin
  pinMode(6,OUTPUT); //trigpin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  digitalWrite(6,0);
  delayMicroseconds(3);
  digitalWrite(6,1);
  delayMicroseconds(3);
  digitalWrite(6,0);
  
  int b=pulseIn(5,HIGH);
  int y=((.033*b)/2);
  Serial.print("Left : ");
  Serial.println(y);
}
