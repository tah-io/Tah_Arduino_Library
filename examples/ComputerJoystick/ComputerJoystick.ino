
int LeftjoyX,LeftjoyY,RightjoyX,RightjoyY,Buttonpadtag, dPad;

char val;          // Store Value of Buttonpadtag
char mem = ' ';    // Store Value of Buttonpadtag till getting new Value


void setup() 
{
  // initialize serial:
  Serial.begin(9600);

  Serial1.begin(57600);
  // make the pins outputs:
  


  Keyboard.begin();
  Mouse.begin();
  
  Keyboard.releaseAll();

}

void loop() 
{
  // if there's any serial available, read it:
  if (Serial1.available()) 
  {
    
    ///// Parsing Value From Left Controller
    
    LeftjoyX = Serial1.parseInt(); 
    // do it again:
    LeftjoyY = Serial1.parseInt();
    // do it again:
    RightjoyX = Serial1.parseInt(); 
    // do it again:
    RightjoyY = Serial1.parseInt();
    // do it again:    
    Buttonpadtag = Serial1.parseInt();
    // do it again:    
    dPad = Serial1.parseInt();

    
    
     /// Mapping Values from ArduWheels Controller
     
     // Left Controller Mapping
     
     
     LeftjoyX = map(LeftjoyX, -9, 9, 0, 18);
     LeftjoyY = map(LeftjoyY, -9, 9, 0, 18);
     
     
     // Right Controller Mapping
     
     RightjoyX = map(RightjoyX, -9, 9, -25, 25);
     RightjoyY = map(RightjoyY, -9, 9, 25, -25);
     //RightButtonPad = constrain(RightButtonPad, 0000, 9999);

    

    // look for the newline. That's the end of your
    // sentence:
    if (Serial1.read() == 'C') 
    {
 
      
  
    Mouse.move(RightjoyX, RightjoyY, 0);    // Right Joystick mapped to Computer Mouse
     /* Serial.print("X:");
      Serial.print(RightjoyX);
      Serial.print(" , ");
      Serial.print("Y:");
      Serial.println(RightjoyY);
     */ 
/////////  Left Joystick mapped to Computer Arrow Keys  ////////////








  
//////////////////////////////////////////////////////////////////////




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

   
/*
       //print the three numbers in one string as hexadecimal:
     Serial.print(LeftjoyX, DEC);
     Serial.print(",");
     Serial.print(LeftjoyY, DEC);
     Serial.print(",");
     Serial.print(RightjoyX, DEC);
     Serial.print(",");
     Serial.print(RightjoyY, DEC);
     Serial.print(",");
     Serial.print(Buttonpadtag, DEC);
     Serial.print(",");
     Serial.print(dPad, DEC);
     Serial.print(",");
     Serial.println(val);
     
     
     Serial.flush(); 
 */    

    }
  }
}








