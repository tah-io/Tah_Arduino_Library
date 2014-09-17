
int LeftjoyX,LeftjoyY,RightjoyX,RightjoyY,Buttonpadtag, dPad;

char val;          // Store Value of Buttonpadtag
char mem = ' ';    // Store Value of Buttonpadtag till getting new Value
int use;
int interval = 40;

void setup() 
{
  // initialize serial:
  Serial.begin(9600);
  Serial1.begin(57600);
 
 Keyboard.begin();
  Mouse.begin();
  Keyboard.releaseAll();

}

void loop() 
{
  
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

    
    if (Serial1.read() == 'C') 
    {
     /// Mapping Values from ArduWheels Controller
     
     // Left Controller Mapping
     
     
     LeftjoyX = map(LeftjoyX, -9, 9, 0, 18);
     LeftjoyY = map(LeftjoyY, -9, 9, 0, 18);
     
     
     // Right Controller Mapping
     
     RightjoyX = map(RightjoyX, -9, 9, -25, 25);
     RightjoyY = map(RightjoyY, -9, 9, 25, -25);
     //RightButtonPad = constrain(RightButtonPad, 0000, 9999);
      
  
    Mouse.move(RightjoyX, RightjoyY, 0);    // Right Joystick mapped to Computer Mouse
     /* Serial.print("X:");
      Serial.print(RightjoyX);
      Serial.print(" , ");
      Serial.print("Y:");
      Serial.println(RightjoyY);
     */ 



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
   
   
   else if(Serial1.read() == 'M')
{
    Serial.println(LeftjoyX);
    if(LeftjoyX == 56)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ARROW);
    
    Serial.println("Right to Left");
   
    
    }
     
     else if(LeftjoyX == 65)
    {
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_RIGHT_ARROW);
    
    Serial.println("Left to Right");
    }
    
    else if(LeftjoyX == 34)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_DOWN_ARROW);
    
    
    Serial.println("Up to Down");
    }
    
    else if(LeftjoyX == 43)
    {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_UP_ARROW);
    
    Serial.println("Down to Up");
    }
    

    else if(LeftjoyX == 98)
    {
    
    Mouse.move(0, 0, 15);
      
    Serial.println("Scoll Up");
    }

    else if(LeftjoyX == 99)
    {
    
    Mouse.move(0, 0, -15);
    Serial.println("Scoll Down");
    }
    
    else if(LeftjoyX == 10)
    {
    
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(interval);
    Keyboard.release(KEY_RIGHT_ARROW);
    
    Serial.println("Left Arrow");

    }
    
    else if(LeftjoyX == 20)
    {
          
      
    Keyboard.press(KEY_LEFT_ARROW);   
    delay(interval);
    Keyboard.release(KEY_LEFT_ARROW);
    Serial.println("Right Arrow");
    }
    
    
    else if(LeftjoyX == 30)
    {
    Keyboard.press(32);
    delay(interval);
    Keyboard.release(32);
    
    Serial.println("Space Bar");
    }
    
    
    else if(LeftjoyX == 96)
    {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("Volume Up");
    }
    
    
    
    else if(LeftjoyX == 97)
    {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("Volume Down");
    }
    
    
    else if(LeftjoyX == 61)
    {
    
    Keyboard.press(KEY_LEFT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_ARROW);
    Serial.println("Left Arrow");
    }
    
    
    else if(LeftjoyX == 62)
    {
    
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(interval);
    Keyboard.release(KEY_RIGHT_ARROW);
    Serial.println("Left Arrow");
    }
    
    
    else if(LeftjoyX == 63)
    {
    
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("Left Arrow");
    }
    
    
    else if(LeftjoyX == 64)
    {
    
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("Left Arrow");
    }
    
    
    else if(LeftjoyX == 75) // tap gesture
    {
    
    Mouse.press(MOUSE_LEFT);
    delay(interval);
    Mouse.release(MOUSE_LEFT);
    Serial.println("Left Mouse Click");
    }
    
    
    

    }
  
    
    
  
  }
  
}
