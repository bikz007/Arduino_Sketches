int lm=7;
int rm=8;

void setup() {
pinMode(lm,OUTPUT);
pinMode(rm,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
pinMode(13,OUTPUT);
digitalWrite(13,1);
}
  
void loop() {
  int leftval=analogRead(A0);
  int rightval=analogRead(A1);
  Serial.print(leftval);
  Serial.print("       ");
  Serial.println(rightval);
  if(leftval>400){
    left();
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,0);
    
    } else if(rightval>500){
      right();
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,1);
      } 
         else if(rightval<500 && leftval<500)
        {
          halt();
          digitalWrite(2,1);
        digitalWrite(3,1);
        digitalWrite(4,1);
          } else
          {
            forward();
            digitalWrite(2,0);
        digitalWrite(3,1);
        digitalWrite(4,0);
            }
}

void left(){
  digitalWrite(rm,1);
  digitalWrite(lm,0);
  }

void right(){
  digitalWrite(rm,0);
  digitalWrite(lm,1);
  }

  void halt(){
    digitalWrite(rm,0);
    digitalWrite(lm,0);
    }

  void forward(){
    digitalWrite(rm,1);
    digitalWrite(lm,1);
    }
