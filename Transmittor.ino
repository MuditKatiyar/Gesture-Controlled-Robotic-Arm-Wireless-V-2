#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<Wire.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
const int MPU_addr=0x68;        //MPU6050 I2C Address
int16_t axis_X,axis_Y,axis_Z;
int minVal=265;
int maxVal=402;

const int flexPin=A0;
int flexValue;

//double x;
//double y;
double z;
double text[3];

void setup()
{
  Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  //radio.stopListening();
  
  
  Wire.begin();                      //Initilize I2C Communication
  Wire.beginTransmission(MPU_addr);  //Start communication with MPU6050
  Wire.write(0x6B);                  //Writes to Register 6B
  Wire.write(0);                     //Writes 0 into 6B Register to Reset
  Wire.endTransmission(true);        //Ends I2C transmission
}
void loop()
{
  


  //Data from MPU6050 for X,Y,Z cordinates
  
  Wire.beginTransmission(MPU_addr);    
  Wire.write(0x3B);                                 //Start with regsiter 0x3B 
  Wire.endTransmission(false);     
  Wire.requestFrom(MPU_addr,14,true);               //Read 14 Registers 
  
  axis_X=Wire.read()<<8|Wire.read();                //Reads the MPU6050 X,Y,Z AXIS Value
  axis_Y=Wire.read()<<8|Wire.read();
  axis_Z=Wire.read()<<8|Wire.read();
  
  int xAng = map(axis_X,minVal,maxVal,-90,90);     // Maps axis values in terms of -90 to +90  
  int yAng = map(axis_Y,minVal,maxVal,-90,90);
  int zAng = map(axis_Z,minVal,maxVal,-90,90);
       
  text[0]= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);         //Formula to convert into degree
  text[1]= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
  z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
  
  
  //Reading Flex Value from Arduino Nano
  
  flexValue= analogRead(flexPin);
  Serial.println("Flex Value is:");
  //Serial.println(flexValue);
  if(flexValue>=960){
    text[2]=1;
  }
  else{
    text[2]=0;
  }
  Serial.println(text[2]);

  //Sending Data over Nrf Module
  
  
  radio.write(text, sizeof(text));
  Serial.println("X value is ");
  Serial.println(text[0]);
  Serial.println("Y vlaue is ");
  Serial.println(text[1]);
  delay(500);
}
