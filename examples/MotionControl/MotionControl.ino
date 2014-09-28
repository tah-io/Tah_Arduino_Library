 #include<TAH.h>

TAH myTAH; 
 
 
int LeftjoyX;
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
    
    LeftjoyX = myTAH.parseInt(); 
 
  //////////////Motion Controller ///////////////


  if(myTAH.read() == 'M')
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
    
    Serial.println("Right Arrow");

    }
    
    else if(LeftjoyX == 20)
    {
          
      
    Keyboard.press(KEY_LEFT_ARROW);
    delay(interval);
    Keyboard.release(KEY_LEFT_ARROW);
    Serial.println("Left Arrow");
    }
    
    
    else if(LeftjoyX == 30)
    {
    Keyboard.press(32);
    delay(interval);
    Keyboard.release(32);
    
    Serial.println("Space Bar");
    }
    
    else if(LeftjoyX == 40)
    {
    
    Keyboard.press(KEY_UP_ARROW);
    delay(interval);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("Up Arrow");
    }
    
    
    else if(LeftjoyX == 50)
    {
    
    Keyboard.press(KEY_DOWN_ARROW);
    delay(interval);
    Keyboard.release(KEY_DOWN_ARROW);
    Serial.println("Down Arrow");
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
    
    else if(LeftjoyX == 75) 
    {
    Mouse.press(MOUSE_LEFT);
    delay(interval);
    Mouse.release(MOUSE_LEFT);
    Serial.println("Left Mouse Click");
    }
    
    
    

    }

  }
  
}

