#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
int data[2];
char textbuff[10];
int locationbuff[2];
char colorbuff[1];
int fontsizebuff[2];

String txtMsg ="";

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();

  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
  
  
  Serial.println(F("Done!"));

}
void Clear_Screen()
{
  tft.fillScreen(ILI9341_WHITE);
}

void loop()
{
  
  
  if(Serial.available())
  { 
     char no = Serial.read();
     Serial.println(no);
   
     if( no == 'F')                        // press F to Flush the Screen
     {
      Clear_Screen();
     }
      
    else if(txtMsg.length() < 20)
   {
     char inChar = Serial.read();
     txtMsg += inChar;                      //Msg format
                                           //txtMsg = "NameXYCS\0"  
    for(int i=0;i<5;i++)
    {
      tft.println(txtMsg);
      delay(250);
    } 

     //Serial.println(txtMsg);
     for(int x=4;x< 6;x++)                //Set Locations,Rotation,Color
     { 
       for(int y=7;y< 9;y++)
        {
          tft.setCursor(80,80);            // need to pass the X ,Y Co-ordinates here
          tft.setRotation(1);
          tft.setTextColor(ILI9341_BLUE); tft.setTextSize(5);      //To Change the color & Font Size
        }
     }   
         
 }
   
}
}



