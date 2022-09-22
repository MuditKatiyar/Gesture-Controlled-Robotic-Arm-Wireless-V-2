# Gesture-Controlled-Robotic-Arm-Wireless-V-2

In this version, The performance and accuracy of both the version is combined. Completely depending on either MPU6050 or flex sensor will causes more problem in controlling the servo motor. So the combination use of MPU6050 with the flex sensor to control the servo motor can give it more flexiblity. Also this time the connect is much more wireless with the use of NRF24L01 module which can be used to transmit the data from arduino nano to Arduino Uno. The Arduino nano is connect to collect the information from the flex and Mpu6050 sensor. This information is transmitted to the arduino uno which is connect to the servo motor for controlling the whole arm of the robot.

![image](https://user-images.githubusercontent.com/113198082/191373353-ddd22bfc-1d5f-45b5-9f48-4f1352f1313e.png)


 
Figure 1 Side View

Experimental Analysis
Coding this type of model will require pre requisite knowledge of servo rotation upto a desired angle well calibrated with flex and mpu6050 sensor. The coding part also require some knowledge of wireless communication and nrf R24 library which uses certain command “ radio.openWritingPipe( ) “ and “radio.openReadingPipe( )”.

![image](https://user-images.githubusercontent.com/113198082/191373615-fb89063b-5750-429b-b3e4-15343dae95e3.png)

Figure 2 Top View

![image](https://user-images.githubusercontent.com/113198082/191373655-e1e59456-11e9-482b-af14-2f52a310aeb3.png)

Figure 3 Glove View

Glove for wireless controlling with NRF24L01 module connected to Arduino Nano. An arduino Nano are connect with the MPU6050 & transmittor (NRF24L01) for taking the value as an input from MPU6050 about the position of MPU6050 in space and at the same time transmitting it to the reciver part as a command to move the Robotic arm in accordance to the MPU6050 location value in space.

## Vedio LINK
  https://drive.google.com/file/d/10_TR2ELHgleZ9YeFJvPEgeQyZtxV6Q7w/view?usp=sharing
  https://drive.google.com/file/d/18Fwr5JfYXEmdJc8MkJiGaLrcwjv00q08/view?usp=sharing

