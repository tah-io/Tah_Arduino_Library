/*

 Tah Motion Control  
 ------------------
 This sketch demonstrates the use of Tah Motion App with Tah board.
 Refer to Tah website for more details: http://tah.io


 
 Circuit:
 --------
 Just plug in your Tah in USB port or power it up with external 5V power supply.

   
 User Guide:
 -----------  
   Tah protocol we use to communicate between the App and a Tah is basically a comma seprated string with end character "R".
   This protocol string is composed of 3 integer values with the end suffix "R" which represents end of string. 
 
   1st Integer represents--> Pin Type: 0 = DIGITAL,  1 = ANALOG,  2 = SERVO,  3 = Send Analog Status,  4 = Send Digital Status
   2nd Integer represents--> Pin No: From 2 to 13 for digital pins and 410 to 415 represents A0 to A5 analog pins
   3rd Integer represents--> Pin Value: 0 or 1 for Digital
                             0 to 255 for Analog
                             0 to 179 for Servo

   e.g:  So if we want to turn ON the default led attached to pin 13 then the protocol sting would be => 0,13,1R
      
  
 
 Created Sep 2014
 by Dhiraj Jadhao
 
 This example is in the public domain       
                                                                                                 
   
*/


#include<TAH.h>

TAH myTAH; 
 
 
int mouseX,mouseY,scroll,keypress;
int interval = 40;
char val;          // Store Value of Buttonpadtag
char mem = ' ';    // Store Value of Buttonpadtag till getting new Value



void setup() 
{
  
  // initialize serial:
  Serial.begin(9600);
  myTAH.begin(9600);

 myTAH.enterCommandMode();

 myTAH.setName("Tah Motion");
 myTAH.setWorkRole(SLAVE);
 myTAH.setAuth(OPEN);
 myTAH.setWorkMode(REMOTE_CONTROL);
 myTAH.setiBeaconMode(ON);

myTAH.exitCommandMode();

  Keyboard.begin();
  Mouse.begin();
  Keyboard.releaseAll();

}

void loop() 
{
  
  if (myTAH.available()) 
  {

    ///// Parsing Value From Left Controller
    
    mouseX = myTAH.parseInt();
   
    mouseY = myTAH.parseInt();
  
    scroll = myTAH.parseInt();
 
    keypress = myTAH.parseInt(); 
    
    

 
  //////////////Motion Controller ///////////////


  if(myTAH.read() == 'M')
{
   
    Serial.print(mouseX);Serial.print(",");
    Serial.print(mouseY);Serial.print(",");
    Serial.print(scroll);Serial.print(",");
    Serial.println(keypress);
    
    if(keypress > 255)
    {
    if(keypress == 258)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ARROW);
    
    Serial.println("Right to Left");
   
    
    }
     
     else if(keypress == 259)
    {
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_RIGHT_ARROW);
    Serial.println("Left to Right");
    }
    
    
    else if(keypress == 257)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("Up to Down");
    }
    
    
    else if(keypress == 256)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("Down to Up");
    }
    
        else if(keypress == 260)
    {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("Volume Up");
    }
    
    
    
    else if(keypress == 261)
    {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("Volume Down");
    }
    

    
 }
   
   
    else if(keypress<=255)
    {
    Keyboard.press(keypress);
    delay(interval);
    Keyboard.release(keypress);
    }
    else
    {
    Keyboard.releaseAll();
    }
    
    
  /*
    if(keypress == 263)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ARROW);
    
    Serial.println("Right to Left");
   
    
    }
     
     else if(keypress == 262)
    {
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_RIGHT_ARROW);
    
    Serial.println("Left to Right");
    }
    
    else if(keypress == 261)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_DOWN_ARROW);
    
    
    Serial.println("Up to Down");
    }
    
    else if(keypress == 260)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_UP_ARROW);
    
    Serial.println("Down to Up");
    }
    

    else if(keypress == 98)
    {
    
    Mouse.move(0, 0, 15);
      
    Serial.println("Scoll Up");
    }

    else if(keypress == 99)
    {
    
    Mouse.move(0, 0, -15);
    Serial.println("Scoll Down");
    }
    
    else if(keypress == 10)
    {
    
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(interval);
    Keyboard.release(KEY_RIGHT_ARROW);
    
    Serial.println("Right Arrow");

    }
    
    else if(keypress == 20)
    {
          
      
    Keyboard.press(KEY_LEFT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_ARROW);
    Serial.println("Left Arrow");
    }
    
    
    else if(keypress == 30)
    {
    Keyboard.press(32);
    delay(interval);
    Keyboard.release(32);
    
    Serial.println("Space Bar");
    }
    
    else if(keypress == 40)
    {
    
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("Up Arrow");
    }
    
    
    else if(keypress == 50)
    {
    
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("Down Arrow");
    }
    
    
    else if(keypress == 96)
    {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("Volume Up");
    }
    
    
    
    else if(keypress == 97)
    {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("Volume Down");
    }
    
*/
    
    
    

    }

  }
  
}

