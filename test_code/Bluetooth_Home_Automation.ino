//Voice control Project via Bluetooth connectivity..
//////////////////using Arduino Uno////////////////
////////////////////////// By////////////////////
/////////////////////EJ-Teach-Tech//////////////
///////////////////////////////////////////////////
#include <SoftwareSerial.h>//including the softwareserial library.

SoftwareSerial mySerial(2,3);//creating a bluetooth serial.
#define load1 4  //declaring variables.......
#define load2 5

String data; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
pinMode(load1,OUTPUT);
pinMode(load2,OUTPUT);

digitalWrite(load2,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
while(mySerial.available()){
  data=mySerial.readString();
  Serial.println(data);
}
if(data=="a"){
  digitalWrite(load1,HIGH);
  
  
  
}
if(data=="b"){
  digitalWrite(load1,LOW);
  
  
  
}
if(data=="c"){
  digitalWrite(load2,LOW);
 
  
}
if(data=="d"){
   digitalWrite(load2,HIGH);
  
}

}
