#include<TAH.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(72, PIN, NEO_GRB + NEO_KHZ800);

TAH myTAH;

void setup() {
  // initialize serial:
   Serial.begin(9600);
   myTAH.begin(9600);
   
   myTAH.enterCommandMode();

   myTAH.setName("Mood Lamp");
   myTAH.setWorkRole(SLAVE);
   myTAH.setAuth(OPEN);
   myTAH.setWorkMode(REMOTE_CONTROL);
   myTAH.setiBeaconMode(ON);

   myTAH.exitCommandMode();

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'


}

void loop() {
  


   if (myTAH.available()) 
   {

     
     
    int red = myTAH.parseInt(); 
    // do it again:
    int green = myTAH.parseInt(); 
    // do it again:
    int blue = myTAH.parseInt(); 
    
    int pattern = myTAH.parseInt(); 
    
   
    if(myTAH.read() == 'R')
  {
    if ( pattern == 1) 
    {

      
      colorWipe(strip.Color(red, green,blue), 5);
      
      Serial.print(red);
      Serial.print(",");
      Serial.print(green);
      Serial.print(",");
      Serial.println(blue);


    }
    
     else if(pattern == 2)
     {
     //theaterChase(strip.Color(127, 127, 127), 50); // White
     //theaterChase(strip.Color(127, 0, 0), 50); // Red
     //theaterChase(strip.Color( 0, 0, 127), 50); // Blue
      rainbow(10);
      //rainbowCycle(20);
      //theaterChaseRainbow(50);
     }
   }
 }
}




// Neopixels Functions

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
for(uint16_t i=0; i<strip.numPixels(); i++) {
strip.setPixelColor(i, c);
strip.show();
delay(wait);
}
}
void rainbow(uint8_t wait) {
uint16_t i, j;
for(j=0; j<256; j++) {
for(i=0; i<strip.numPixels(); i++) {
strip.setPixelColor(i, Wheel((i+j) & 255));
}
strip.show();
delay(wait);
}
}
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
uint16_t i, j;
for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
for(i=0; i< strip.numPixels(); i++) {
strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
}
strip.show();
delay(wait);
}
}
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
for (int j=0; j<10; j++) { //do 10 cycles of chasing
for (int q=0; q < 3; q++) {
for (int i=0; i < strip.numPixels(); i=i+3) {
strip.setPixelColor(i+q, c); //turn every third pixel on
}
strip.show();
delay(wait);
for (int i=0; i < strip.numPixels(); i=i+3) {
strip.setPixelColor(i+q, 0); //turn every third pixel off
}
}
}
}
//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
for (int j=0; j < 256; j++) { // cycle all 256 colors in the wheel
for (int q=0; q < 3; q++) {
for (int i=0; i < strip.numPixels(); i=i+3) {
strip.setPixelColor(i+q, Wheel( (i+j) % 255)); //turn every third pixel on
}
strip.show();
delay(wait);
for (int i=0; i < strip.numPixels(); i=i+3) {
strip.setPixelColor(i+q, 0); //turn every third pixel off
}
}
}
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
if(WheelPos < 85) {
return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
} else if(WheelPos < 170) {
WheelPos -= 85;
return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
} else {
WheelPos -= 170;
return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
}
}
