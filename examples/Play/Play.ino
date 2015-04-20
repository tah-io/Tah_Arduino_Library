#include<TAH.h>
TAH myTAH;


int mode, joyX, joyY, dPad, Buttonpadtag;

char val;          // Store Value of Buttonpadtag
char mem = ' ';    // Store Value of Buttonpadtag till getting new Value


void setup() 
{
  
 Keyboard.begin();
 Mouse.begin();
 Keyboard.releaseAll();  
  
Serial.begin(9600);
myTAH.begin(9600);

myTAH.enterCommandMode();

myTAH.setName("Play");
myTAH.setWorkRole(SLAVE);
myTAH.setAuth(OPEN);
myTAH.setWorkMode(REMOTE_CONTROL);
myTAH.setiBeaconMode(ON);

myTAH.exitCommandMode();
}


void loop() 
{
  // if there's any serial available, read it:
  if (myTAH.available()) 
  {
    
    ///// Parsing Value From Left Controller
    
    mode = myTAH.parseInt();
    
    joyX = myTAH.parseInt(); 
  
    joyY = myTAH.parseInt();
  
    dPad = myTAH.parseInt();   
      
    Buttonpadtag = myTAH.parseInt();

    

     
     // joystick value mapping
     joyX = map(joyX, -128,128, 0, 255);
     joyY = map(joyY, 128, -128, 0, 255);


    

    // look for the newline. That's the end of your
    // sentence:
    if (myTAH.read() == 'P') 
    {
    
      if(mode == 0) // App is in PS mode
      {
      
        // Always be getting fresh data
         dataForController_t SonycontrollerData = SonygetControllerData();
        // Then send out the data over the USB connection
         // Joystick.set(controllerData) also works.
        Joystick.setControllerData(SonycontrollerData);
      }
      
      else if(mode == 1) // App is in Computer Joystick Mode
      {
     
        /////////  Button Pad mapped to User Defined Computer Keys  ////////////
     if(Buttonpadtag >> 0  && Buttonpadtag != 5 && Buttonpadtag != 6)
     { 
       val = Buttonpadtag;
       mem = val;
       Keyboard.press(val);
  
     }

else
{
val = mem;
Keyboard.release(val);
}




if(Buttonpadtag == 5)
{
Keyboard.press(KEY_ESC);
}
else
{
Keyboard.release(KEY_ESC);
}


if(Buttonpadtag == 6)
{
Mouse.press(MOUSE_LEFT);
}
else
{
Mouse.release(MOUSE_LEFT);
}

//////////////////////////////////////////////////////////////////////




/////////  dPad mapped to Computer Arrow Keys  ////////////

if(dPad == 2 )
{
Keyboard.press(KEY_UP_ARROW);
Keyboard.release(KEY_DOWN_ARROW);
Keyboard.release(KEY_RIGHT_ARROW);
Keyboard.release(KEY_LEFT_ARROW);
}


if(dPad == 8 )
{
Keyboard.press(KEY_DOWN_ARROW);
Keyboard.release(KEY_UP_ARROW);
Keyboard.release(KEY_RIGHT_ARROW);
Keyboard.release(KEY_LEFT_ARROW);
}



if(dPad == 6 )
{
Keyboard.press(KEY_RIGHT_ARROW);
Keyboard.release(KEY_UP_ARROW);
Keyboard.release(KEY_DOWN_ARROW);
Keyboard.release(KEY_LEFT_ARROW);
}


if(dPad == 4 )
{
Keyboard.press(KEY_LEFT_ARROW);
Keyboard.release(KEY_UP_ARROW);
Keyboard.release(KEY_DOWN_ARROW);
Keyboard.release(KEY_RIGHT_ARROW);
}


if(dPad == 3 )
{
Keyboard.press(KEY_UP_ARROW);
Keyboard.press(KEY_RIGHT_ARROW);
Keyboard.release(KEY_DOWN_ARROW);
Keyboard.release(KEY_LEFT_ARROW);
}


if(dPad == 9 )
{
Keyboard.press(KEY_DOWN_ARROW);
Keyboard.press(KEY_RIGHT_ARROW);
Keyboard.release(KEY_UP_ARROW);
Keyboard.release(KEY_LEFT_ARROW);
}


if(dPad == 7 )
{
Keyboard.press(KEY_DOWN_ARROW);
Keyboard.press(KEY_LEFT_ARROW);
Keyboard.release(KEY_UP_ARROW);
Keyboard.release(KEY_RIGHT_ARROW);

}


if(dPad == 1 )
{
Keyboard.press(KEY_UP_ARROW);
Keyboard.press(KEY_LEFT_ARROW);
Keyboard.release(KEY_DOWN_ARROW);
Keyboard.release(KEY_RIGHT_ARROW);
}


if(dPad == 5)
{
Keyboard.release(KEY_UP_ARROW);
Keyboard.release(KEY_DOWN_ARROW);
Keyboard.release(KEY_RIGHT_ARROW);
Keyboard.release(KEY_LEFT_ARROW);
}

//////////////////////////////////////////////////////////////////////
   
}




   

     //print the three numbers in one string as hexadecimal:
     Serial.print(mode, DEC);
     Serial.print(",");
     Serial.print(joyX, DEC);
     Serial.print(",");
     Serial.print(joyY, DEC);
     Serial.print(",");
     Serial.print(dPad, DEC);
     Serial.print(",");
     Serial.println(Buttonpadtag, DEC);

     Serial.flush(); 
     
    

    }
  }
}


///////////// Play Station Data Structure /////////////

dataForController_t SonygetControllerData(void)
{  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins
  
  
    if(Buttonpadtag == 1)
  {
  controllerData.crossOn = 1;
  Serial.println(" Cross");
  }

  else if(Buttonpadtag == 2)
  {
  controllerData.circleOn = 1;
  Serial.println(" Circle");
  }
  
  else if(Buttonpadtag == 3)
  {
  controllerData.squareOn = 1;
  Serial.println(" Square");
  }
  
  else if(Buttonpadtag == 4 )
  {
  controllerData.triangleOn = 1;
  Serial.println(" Triangle");
  }
  
  else if(Buttonpadtag == 7 )
  {
  controllerData.selectOn = 1;
  Serial.println(" Select");
  }
  
  else if(Buttonpadtag == 8 )
  {
  controllerData.startOn = 1;
  Serial.println(" Start");
  }
  

  
  


  // Set the analog sticks

  controllerData.leftStickX = joyX;
  controllerData.leftStickY = joyY;

  // And return the data!
  return controllerData;
}




