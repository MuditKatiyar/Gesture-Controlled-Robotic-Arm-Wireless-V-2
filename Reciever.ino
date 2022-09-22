//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<Servo.h>               //Servo Motor Library

Servo servo_1;      
Servo servo_2;
Servo servo_3;
int x;
int y;
int Flex;

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
double text[3];

void setup()
{
 
  Serial.begin(9600);
  
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  
  //set the address
  radio.openReadingPipe(1, address);
  
  //Set module as receiver
  radio.startListening();
  
  servo_1.attach(3);   // Forward/Reverse_Motor
  servo_2.attach(5);   // Gripper_Motor
  servo_3.attach(6);   // Left/Right_Motor
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    
    radio.read(text, sizeof(text));
    x=text[0];
    y=text[1];
    Flex=text[2];
    Serial.println(text[0]);
    Serial.println(text[1]);
    Serial.println(text[2]);
    
  // MPU6050 Code
    if(x >=0 && x <= 60) 
  {
     int mov1 = map(x,0,60,60,0);
     Serial.print("Movement in F/R = ");
     Serial.print(mov1);
     Serial.println((char)176);
     servo_1.write(mov1);
  }
 

  if(y >=0 && y <= 45) 
  {
     int mov3 = map(y,45,0,90,0);
     Serial.print("Movement in Right = ");
     Serial.print(mov3);
     Serial.println((char)176);
     servo_3.write(y);
  } 
 
 else if(y >=300 && y <= 345) 
  {
     int mov3 = map(y,345,300,90,180);
     Serial.print("Movement in left = ");
     Serial.print(mov3);
     Serial.println((char)176);
     servo_3.write(mov3);
  }

  // flex sensor
  
  if(Flex==1){
      servo_2.write(180);
    }
  else{
      servo_2.write(150);
     }
     
  }
  else{
    Serial.println("No radio available");
  }
  delay(500);
}
