char data;
int speed=50;
int point[]={0,0};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(34,OUTPUT);
  pinMode(35,OUTPUT);
  pinMode(12,OUTPUT);//s
  pinMode(36,OUTPUT);
  pinMode(37,OUTPUT);
  pinMode(8,OUTPUT);//s
  pinMode(42,OUTPUT);
  pinMode(43,OUTPUT);
  pinMode(6,OUTPUT);//s
  pinMode(58,OUTPUT);
  pinMode(59,OUTPUT);
  pinMode(5,OUTPUT);//s
  pinMode(24, OUTPUT);//Tf
  pinMode(22, INPUT);//Ef
  pinMode(25,OUTPUT);//Tr
  pinMode(28,INPUT);//Er
  pinMode(29,OUTPUT);//Tl
  pinMode(30,INPUT);//El
  SpeedSet(speed, speed, speed, speed);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial2.available())
  {
    data=Serial2.read();
    if(data == 'X')
    {
      point[0]=Serial2.parseInt();
    }
    else if(data=='Y')
    {
      point[1]=Serial2.parseInt();
    }
    Serial.print("x : ");
    Serial.println(point[0]);
    Serial.print("y : ");
    Serial.println(point[1]);
    if(point[0]>180 && point[1]>170){
      RightDown();
    }
    else if(point[0]>180 && point[1]<110){
      RightUp();
    }
    else if(point[0]>180){
      Right();
    }
    else if(point[0]<90 && point[1]>170){
      LeftDown();
    }
    else if(point[0]<90 && point[1]<110){
      LeftUp();
    }
    else if(point[0]<90){
      Left();
    }
    else if(point[1]<110){
      ForWard();
    }
    else if(point[1]>170){
      Back();
    }
    else{
      Stop();
    }
  }
}

void SpeedSet(int M1,int M2,int M3,int M4)
{
  analogWrite(12,M1);
  analogWrite(6,M2);
  analogWrite(8,M3);
  analogWrite(5,M4);
}
void ForWard()
{
  digitalWrite(34,0);
  digitalWrite(35,1);//1
  digitalWrite(36,0);
  digitalWrite(37,1);//3
  digitalWrite(42,1);
  digitalWrite(43,0);//2
  digitalWrite(58,1);
  digitalWrite(59,0);//4
}
void Back()
{
  digitalWrite(34,1);
  digitalWrite(35,0);//1
  digitalWrite(36,1);
  digitalWrite(37,0);//3
  digitalWrite(42,0);
  digitalWrite(43,1);//2
  digitalWrite(58,0);
  digitalWrite(59,1);//4
}
void Right()
{
  digitalWrite(34,0);
  digitalWrite(35,1);//1
  digitalWrite(36,1);
  digitalWrite(37,0);//3
  digitalWrite(42,0);
  digitalWrite(43,1);//2
  digitalWrite(58,1);
  digitalWrite(59,0);//4
}
void Left()
{
  digitalWrite(34,1);
  digitalWrite(35,0);//1
  digitalWrite(36,0);
  digitalWrite(37,1);//3
  digitalWrite(42,1);
  digitalWrite(43,0);//2
  digitalWrite(58,0);
  digitalWrite(59,1);//4
}
void RightUp()
{
  digitalWrite(34,0);
  digitalWrite(35,1);//1
  digitalWrite(36,0);
  digitalWrite(37,0);//3
  digitalWrite(42,0);
  digitalWrite(43,0);//2
  digitalWrite(58,1);
  digitalWrite(59,0);//4
}
void RightDown()
{
  digitalWrite(34,0);
  digitalWrite(35,0);//1
  digitalWrite(36,1);
  digitalWrite(37,0);//3
  digitalWrite(42,0);
  digitalWrite(43,1);//2
  digitalWrite(58,0);
  digitalWrite(59,0);//4
}
void LeftUp()
{
  digitalWrite(34,0);
  digitalWrite(35,0);//1
  digitalWrite(36,0);
  digitalWrite(37,1);//3
  digitalWrite(42,1);
  digitalWrite(43,0);//2
  digitalWrite(58,0);
  digitalWrite(59,0);//4
}
void LeftDown()
{
  digitalWrite(34,1);
  digitalWrite(35,0);//1
  digitalWrite(36,0);
  digitalWrite(37,0);//3
  digitalWrite(42,0);
  digitalWrite(43,0);//2
  digitalWrite(58,0);
  digitalWrite(59,1);//4
}
void Stop()
{
  digitalWrite(34,0);
  digitalWrite(35,0);//1
  digitalWrite(36,0);
  digitalWrite(37,0);//3
  digitalWrite(42,0);
  digitalWrite(43,0);//2
  digitalWrite(58,0);
  digitalWrite(59,0);//4
}
