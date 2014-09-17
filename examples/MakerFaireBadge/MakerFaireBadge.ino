#include <TAH.h>
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  // Arduino LCD library


TAH myTAH;
// pin definitions
#define sd_cs  8
#define lcd_cs 7
#define dc     2
#define rst    3  

TFT TFTscreen = TFT(lcd_cs, dc, rst);

// this variable represents the image to be drawn on screen
PImage logo1;




void setup() {
  
  
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
  
  // initialize the GLCD and show a message
  // asking the user to open the serial line
  
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);

  TFTscreen.stroke(0, 0, 0);
  TFTscreen.println(" ");
  TFTscreen.println(" ");
  TFTscreen.println("     TAH Personal Badge");
  TFTscreen.println("        Designed By:");
  TFTscreen.println(" ");
  TFTscreen.println("       Dhiraj Jadhao");
  delay(2000);

  // initialize the serial port: it will be used to 
  // print some diagnostic info  
  Serial.begin(9600);

  // clear the GLCD screen before starting
  TFTscreen.background(255, 255, 255);
  
  // try to access the SD card. If that fails (e.g.
  // no card present), the setup process will stop.
  TFTscreen.println("   Initializing SD card..");
  if (!SD.begin(sd_cs)) 
  {
    TFTscreen.println("failed!");
    return;
  }
  TFTscreen.println(" ");
  TFTscreen.println("        All Good!");

  
  // initialize and clear the GLCD screen
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);

}

void loop() {
  
    // draw the image to the screen
  
  logo1 = TFTscreen.loadImage("1.bmp");  
  TFTscreen.image(logo1, 32, 15);

  
}
