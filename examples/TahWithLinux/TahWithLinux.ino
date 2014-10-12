#include <TAH.h>

TAH myTAH;

void setup()  
{
 
  Serial.begin(9600);                       // Open serial port
  myTAH.begin(9600);                        // Start TAH ble serial port
  
  myTAH.enterCommandMode();                 // Enters TAH command mode
 
 
 myTAH.setName("TAH"); 
 
 myTAH.setWorkRole(SLAVE);
 
 myTAH.setAuth(OPEN);
 myTAH.setiBeaconMode(ON);
 myTAH.setiBeaconMajorValue("0064");       // Input MAJOR Value in HEX
 myTAH.setiBeaconMinorValue("0001");       // Input MINOR Value in HEX

  
myTAH.exitCommandMode();                  // Saves changed settings and exit command mode
  
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
  
}

void loop() // run over and over
{
  if(myTAH.available())
  {
      int val = myTAH.read();
      
      Serial.write(val);
      if(val =='1')
      {
        digitalWrite(13,HIGH);
      }
      if(val =='0')
     {
        digitalWrite(13,LOW);
     } 
 
  }
  
  if(Serial.available())
  {
      int data = Serial.read();
      
      myTAH.write(data);
      Serial.println(data);
  }
  
}
