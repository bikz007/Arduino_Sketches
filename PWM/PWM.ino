void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=0;
  if(a==0){
    for(a=0;a<=255;a++){
      analogWrite(3,a);
      delay(10);
      if(a==255){
        for(a=254;a>=0;a--){
          analogWrite(3,a);
          delay(10);
        }
      }
  }}
  /*analogWrite(3,0);
  delay(1000);
  analogWrite(3,10);
  delay(1000);
  analogWrite(3,50);
  delay(1000);
  analogWrite(3,100);
  delay(1000);
  analogWrite(3,255);
  delay(1000);
  analogWrite(3,150);
  delay(1000);
  */
}
