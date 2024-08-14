
#include <SoftwareSerial.h>//including the softwareserial library.
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial mySerial(2,3);//creating a bluetooth serial.
#define FAN 4  //declaring variables.......
#define TV  5
#define RoomLight 6
#define KitchenLight 7
#define led1 8
#define led2 9
#define led3 10
#define led4 11
String data; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.init();
lcd.backlight();
mySerial.begin(9600);
pinMode(FAN,OUTPUT);
pinMode(TV,OUTPUT);
pinMode(RoomLight,OUTPUT);
pinMode(KitchenLight,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
digitalWrite(FAN,LOW);
  digitalWrite(TV,LOW);
  digitalWrite(RoomLight,LOW);
  digitalWrite(KitchenLight,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
lcd.setCursor(0,0);
lcd.print("    Welcome    ");
delay(3000);
lcd.setCursor(0,0);
lcd.print("Home Asisstance");
delay(2000);
lcd.setCursor(0,1);
lcd.print("    System    ");
delay(2000);
lcd.clear();
lcd.print("Bluetooth ");
delay(3000);
lcd.setCursor(0,1);
lcd.print("Connecting");
delay(2000);
lcd.setCursor(10,1);
lcd.print(".");
delay(2000);
lcd.setCursor(11,1);
lcd.print(".");
delay(2000);
lcd.setCursor(12,1);
lcd.print(".");
delay(2000);
lcd.setCursor(13,1);
lcd.print(".");
delay(2000);
lcd.clear();
 lcd.setCursor(0,0);
lcd.print("******Say****** ");
lcd.setCursor(0,1);
lcd.print("*****Hello***** ");
}

void loop() {
  // put your main code here, to run repeatedly:
  
while(mySerial.available()){
  data=mySerial.readString();
  Serial.println(data);
  lcd.setCursor(0,0);
lcd.print(" Home Asisstance");
lcd.setCursor(0,1);
lcd.print("  Speak Command ");
}
if(data=="all devices on"){
   lcd.setCursor(0,0); 
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print(" All devices on ");
  digitalWrite(FAN,HIGH);
  digitalWrite(TV,HIGH);
  digitalWrite(RoomLight,HIGH);
  digitalWrite(KitchenLight,HIGH);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
    

}

else if(data=="all devices off"){
   lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
lcd.print(" All devices off");
  digitalWrite(FAN,LOW);
  digitalWrite(TV,LOW);
  digitalWrite(RoomLight,LOW);
  digitalWrite(KitchenLight,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
 

}
else if(data=="turn on the fan"){
  lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print(" Fan turned on  ");
  digitalWrite(FAN,HIGH);
  digitalWrite(led1,HIGH);
   

  
}
else if(data=="turn off the fan"){
  lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print(" Fan turned off ");
   digitalWrite(FAN,LOW);
  digitalWrite(led1,LOW);
   

}
else if(data=="turn on the TV"){
    lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print(" TV turned on   ");
  digitalWrite(TV,HIGH);
  digitalWrite(led2,HIGH);
  
  
}
else if(data=="turn off the TV"){
    lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print(" TV turned off  ");
   digitalWrite(TV,LOW);
  digitalWrite(led2,LOW);
}
else if(data=="turn on the room light"){
    lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print("  RoomLight  on ");
  digitalWrite(RoomLight,HIGH);
  digitalWrite(led3,HIGH);
  
}

else if(data=="turn off the room light"){
   lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print("  RoomLight  off");
   digitalWrite(RoomLight,LOW);
  digitalWrite(led3,LOW);
}
else if(data=="turn on the kitchen light"){
   lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print("Kitchen Light on");
  digitalWrite(KitchenLight,HIGH);
  digitalWrite(led4,HIGH);
  
}
else if(data=="turn off the kitchen light"){
   lcd.setCursor(0,0);
  lcd.print("Command Recieved");
lcd.setCursor(0,1);
  lcd.print("KitchenLight off");
   digitalWrite(KitchenLight,LOW);
  digitalWrite(led4,LOW);
}

}
