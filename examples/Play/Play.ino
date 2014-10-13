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
     joyX = map(joyX, -9, 9, 0, 18);
     joyY = map(joyY, -9, 9, 0, 18);


    

    // look for the newline. That's the end of your
    // sentence:
    if (myTAH.read() == 'P') 
    {
 
      if(mode == 0)
      {
      
      }
      
      else if(mode == 1)
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




   /*

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
     
   */  

    }
  }
}








