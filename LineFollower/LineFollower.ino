int lm=9;
int rm=10;
int leftAvg=500;
int rightAvg=500;
int leftSensor=A0;
int rightSensor=A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(lm,OUTPUT);
  pinMode(rm,OUTPUT);
  pinMode(leftSensor,INPUT);
  pinMode(rightSensor,INPUT);
}
void lt(){
  digitalWrite(rm,1);
  digitalWrite(lm,0);
}
void rt(){
  digitalWrite(lm,1);
  digitalWrite(rm,0);
}
void Stop(){
  digitalWrite(lm,0);
  digitalWrite(rm,0);
}
void forward(){
  digitalWrite(lm,1);
  digitalWrite(rm,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,1);
  int leftVal=analogRead(leftSensor);
  int rightVal=analogRead(rightSensor);

  if(leftVal>leftAvg)
    lt();
  else if(rightVal > rightAvg)
    rt();
  else if(leftVal < leftAvg && rightVal < rightAvg)
    forward();
  else 
    Stop();
}
