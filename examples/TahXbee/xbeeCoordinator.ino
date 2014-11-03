#include <TAH.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX

TAH myTAH;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
myTAH.begin(9600);
mySerial.begin(9600);
delay(500);
myTAH.enterCommandMode();                 // Enters TAH command mode
  myTAH.setName("TahXbee"); 
 
 myTAH.setWorkRole(SLAVE);
 myTAH.setAuth(OPEN);
   
myTAH.exitCommandMode();                  // Saves changed settings and exit command mode
  
//Serial.println('K');
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
   
   if(myTAH.available())
   {
     int input = myTAH.read();
     
     if(input == '1')
     {
         
         mySerial.write('1');      //send input to Xbee
         delay(1000);
         Serial.println("Sent Cmd to ON Enddevice LED");
     }
     if(input == '0')
     {
       mySerial.write('0');            //send input to Xbee
       delay(1000);
       Serial.println("Sent Cmd to OFF Enddevice LED");   
     }
   }
   
   //Now Read Acknowlede from End Device Xbee 
   
   if(mySerial.available() >0)    //check for end device response
   {
      char data = mySerial.read();
      Serial.println(data);
      if(data =='1')              // 1 Received from end device
      {
         Serial.println("End device LED is ON");
         digitalWrite(13,HIGH);
         myTAH.println("ON");
         //delay(5000);
         //digitalWrite(13,LOW);
       }
      if(data =='0')              // 0 Received from end device
      {
          Serial.println("End Device LED is OFF");
          digitalWrite(13,LOW);
          myTAH.println("OFF");
      }
   }
      
}
