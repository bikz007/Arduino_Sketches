void setup() {
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop() {
  int a=digitalRead(3);
  if (a==0){
    digitalWrite(13,0);
  }
  else{
    digitalWrite(13,1);
  }
}
