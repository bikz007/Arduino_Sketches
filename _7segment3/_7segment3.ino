 const int A[10][7]={
  {1,1,1,1,0,1,1},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,0,1,1,1,1,1},
  {1,0,1,1,0,1,1},
  {0,1,1,0,0,1,1},
  {1,1,1,1,0,0,1},
  {1,1,0,1,1,0,1},
  {0,1,1,0,0,0,0},
  {1,1,1,1,1,1,0}
  };


void n(int num)
{
  int pin=2;
   for(int j=0;j<7;j++)
   {
    digitalWrite(pin,A[num][j]);
    pin++;
    }
  }
  
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
 for(int count=10;count>0;--count)
 {
  digitalWrite(13,1);
  delay(50);
  digitalWrite(13,0);
  delay(1000);
  n(count-1);
  }
    for(int count=0;count<9;count++)
 {
  digitalWrite(13,1);
  delay(50);
  digitalWrite(13,0);
  delay(1000);
  n(count+1);
  }
}

