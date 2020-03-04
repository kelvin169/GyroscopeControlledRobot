/*
ARDUINO BASED GYROSCOPE CONTROLLED ROBOT BY ENGINEER KID
THIS PROJECT WILL HELP YOU TO UNDERSTAND THE ARDUINO MICROCONTROLLER
, MOTOR DRIVER MODULE AND GY-521 GYROSCOPE MODULE IN AN EASY WAY.
WORKING OF THIS PROJECT :-
THE GYROSCOPE SENSOR IS ALSO KNOWN AS THE TILT SENSOR. IT SENSES ITS 
MOVEMENTS AND PROVIDES THE VALUES TO THE ARDUINO. THE GYROSCOPE MODULE 
WORKS ON ALL THE THREE AXIS NAMELY THE X,Y AND Z. WHEN THE ARDUINO RECEIVES 
THESE VALUES IT USES THEM WITH THE IF ELSE STATEMENTS TO DRIVE THE MOTORS ACCORDINGLY.
THE CONNECTIONS BETWWEN THE GYROSCOPE MODULE AND THE ARDUINO ARE GIVEN BELOW. 
GYRO<<ARDUINO
VCC<<VCC
GND<<GND
SCL<<A5
SDA<<A4
AD0<<GND
INT<<D2
*****************************************************************************************
                              ***ALL THE BEST***
*****************************************************************************************
IF YOU COME ACROSS ANY PROBLEM REGARDING THE PROJECT FEEL FREE TO
CONTACT ME AT - engineerkid1@gmail.com
You can contact me at :-
Facebook page - https://www.facebook.com/engineerkid1/

Instagram - https://www.instagram.com/engineerkid1/

Twitter - https://mobile.twitter.com/Engineerkid01?s=09

Website - http://electronickida.wordpress.com 
*/
#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
 const int trigPin=13;
 //Motor A
const int motorPin1  = 5;  
const int motorPin2  = 6;  
//Motor B
const int motorPin3  = 10; 
const int motorPin4  = 9;  
void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(motorPin1, OUTPUT); 
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); 
  Wire.write(0);     
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  
  AcX=Wire.read()<<8|Wire.read();     
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  Tmp=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read(); 
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  if(AcX<-6000&&-11000)
  {
    digitalWrite(trigPin,HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);//FORWARD
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
  }
  else if(AcX>4000&&6000)
  {
   digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);//REVERSE
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
  }
   else if(AcY<-7000&&-5000)
  {
   digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);//LEFT
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
  }
  else if(AcY>5000&&12000)
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);//RIGHT
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
}
  else
  {
    digitalWrite(trigPin,LOW);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);//STOP
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
  delay(333);
}
