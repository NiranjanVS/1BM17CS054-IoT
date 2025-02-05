#include "SoftwareSerial.h"
SoftwareSerial MyBlue(6, 7); // RX | TX 
void setup() 
{ 
  Serial.begin(9600); 
  MyBlue.begin(38400);  //Baud Rate for AT-command Mode.  
  Serial.println("***AT commands mode***"); 
} 
void loop() 
{ 
  //from bluetooth to Terminal. 
  if (MyBlue.available()) 
    Serial.write(MyBlue.read()); 
  //from termial to bluetooth 
  if (Serial.available()) 
    MyBlue.write(Serial.read());
}
