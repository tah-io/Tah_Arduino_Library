/*

Tah As Beacon  
 ------------------
 This sketch demonstrates the use of Tah board acting as a Beacon.
 By default Tah ships with following beacon parameters:
 
 UUID: 74278BDA-B6444520-8F0C720E-AF059935
 Major: 0xFFE0
 Minor: 0xFFE1
 
 Refer to Tah website for more details: http://tah.io

*/
#include <TAH.h>

TAH myTAH;

void setup()  
{
 
  Serial.begin(9600);                       
  myTAH.begin(9600);                        // Start Tah ble serial port
  
  myTAH.enterCommandMode();                 // Enters Tah command mode
 
 
 myTAH.setName("Tah Beacon"); 
 
 myTAH.setWorkRole(SLAVE); // Set Tah board in Slave mode
 myTAH.setAuth(OPEN); // Set Tah authentication type to Open
 myTAH.setiBeaconMode(ON); // Turn on Tah Beacon mode
 
 myTAH.setiBeaconUUIDstring1("CEAFC879"); // Sets 1st string of proximity UUID
 myTAH.setiBeaconUUIDstring2("F37A48D1"); // Sets 2nd string of proximity UUID
 myTAH.setiBeaconUUIDstring3("BBA2B870"); // Sets 3rd string of proximity UUID
 myTAH.setiBeaconUUIDstring4("363597A3"); // Sets 4th string of proximity UUID
 
 myTAH.setiBeaconMajorValue("63B5"); // Sets Major parameter of Tah beacon. Input hex value.
 myTAH.setiBeaconMinorValue("CD46"); // Sets Minor parameter of Tah beacon. Input hex value.


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

