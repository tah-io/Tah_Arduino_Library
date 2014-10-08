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
  
  if (myTAH.available())            //if data avaliable on BLE serial
  {
    int data = Serial.write(myTAH.read());    //read from BLE serial port and write to Arduino Serial port
    Serial.println(data);
    Serial.println("Data Received");
    for(int i=0; i <1;i++)
    {
      Serial.println("Blink");            // On data receive by Tah make the led ON for 1 Sec 
      digitalWrite(13,HIGH);
      delay(500);
      digitalWrite(13,LOW);
      delay(500);
    }
  }
  digitalWrite(13,LOW);
  
  if (Serial.available())              //if serial data is avaliable
  {

        myTAH.write(Serial.read());      // To Send the Commands from Arduino Serial port to BLE serial port
   }


 
}

