#include <TAH.h>

TAH myTAH;

void setup()  
{
 
  Serial.begin(9600);                       // Open serial port
  myTAH.begin(9600);                        // Start TAH ble serial port
  
  myTAH.enterCommandMode();                 // Enters TAH command mode
 
  myTAH.setName("DHIRAJ");                  // Sets TAH name
  myTAH.setWorkMode(REMOTE_CONTROL);        // set TAH in Remote control mode
  
  myTAH.setiBeaconMode(ON);                 // set TAH in iBeacon Mode
  myTAH.setiBeaconMajorValue("0001");       // Sets TAH iBeacons Major parameter value
  myTAH.setiBeaconMinorValue("0100");       // Sets TAH iBeacons Minor parameter value
  
  myTAH.setUARTNotification(ON);            // send TAH connection status notification on UART
  
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

