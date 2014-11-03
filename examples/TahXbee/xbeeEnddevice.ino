#include <TAH.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX
TAH myTAH;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  myTAH.begin(9600);
  mySerial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
  if(mySerial.available() > 0 )    // Read Commands from Xbee Coordinator
  {
    int data = mySerial.read();
    
    if(data == '1')    // 1 is received
    {
      Serial.println("Received 1 from Coordinator");
      digitalWrite(13,HIGH);
      delay(500);
      mySerial.write('1');      //send 1 to coordinator
      Serial.println("Sent 1 to Coordinator");
    }
    
   if(data == '0')              // 0 is received from coordinator
   {
       digitalWrite(13,LOW);      //off the LED
       mySerial.write('0');        //send 0 to coordinator
       Serial.println("Sent 0 to Coordinator");
   }
 }
}
