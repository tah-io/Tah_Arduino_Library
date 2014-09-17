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


  
myTAH.exitCommandMode();                  // Saves changed settings and exit command mode
  


  
}

void loop() // run over and over
{
  
  if (myTAH.available())
  {
    Serial.write(myTAH.read());
  }
  
  
  if (Serial.available())
  {

        myTAH.write(Serial.read());
  }





  
}

