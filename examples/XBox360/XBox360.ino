

int LeftjoyX,LeftjoyY,RightjoyX,RightjoyY,Buttonpadtag;

void setup() 
{
  // initialize serial:
  Serial.begin(9600);

  Serial1.begin(57600);
  // make the pins outputs:
  


  Keyboard.begin();
  
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

   /*
    ///////Buttonpadtag Value Mapping/////////
   
   XBox Mapping:
   -------------
   
   5  = dPad Center
   2  = dPad Up
   8  = dPad Down
   6  = dPad Right
   4  = dPad Left
   
   10005 = Button A
   20005 = Button B
   30005 = Button X
   40005 = Button Y
   
   1005 = LB
   2005 = LT
   105  = RB
   205  = RT
   
   15 = Guide
   75 = Back
   85 = Start
   
      
   PlayStation COntroller Mapping:
   -------------------------------   
    
   5  = dPad Center
   2  = dPad Up
   8  = dPad Down
   6  = dPad Right
   4  = dPad Left
   
   10005 = Cross
   20005 = Circle
   30005 = Square
   40005 = Triangle
   
   1005 = L1
   2005 = L2
   105  = R1
   205  = R2
   
   15 = PSHome
   75 = Select
   85 = Start
    
   ////////////////////////////////////////// 
   */ 
    
    
     /// Mapping Values from ArduWheels Controller
     
     // Left Controller Mapping
     
     
     LeftjoyX = map(LeftjoyX, -9, 9, 1, 255);
     LeftjoyY = map(LeftjoyY, -9, 9, 255, 1);
     
     
     // Right Controller Mapping
     
     RightjoyX = map(RightjoyX, -9, 9, 1, 255);
     RightjoyY = map(RightjoyY, -9, 9, 1, 255);
     //RightButtonPad = constrain(RightButtonPad, 0000, 9999);

    

    // look for the newline. That's the end of your
    // sentence:
    if (Serial1.read() == 'X') 
    {

        // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  // Then send out the data over the USB connection
  // Joystick.set(controllerData) also works.
  Joystick.setControllerData(controllerData);
  
  Serial.println(Buttonpadtag);
      
    }
  }
}




dataForController_t getControllerData(void)
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
  if(Buttonpadtag == -25531 )
  {
  controllerData.triangleOn = 1;
  
  Serial.println(" Triangle");
  }
  if(Buttonpadtag == 20005)
  {
  controllerData.crossOn = 1;
  }
  if(Buttonpadtag == 30005)
  {
  controllerData.circleOn =1;
  }
  if(Buttonpadtag == 10005)
  {
  controllerData.squareOn =1;
  }
  if(Buttonpadtag == 2)
  {
  controllerData.dpadUpOn =1 ;
  }
  if(Buttonpadtag == 8)
  {
  controllerData.dpadDownOn = 1;
  }
  if(Buttonpadtag == 4)
  {
   controllerData.dpadLeftOn = 1;
  }
  if(Buttonpadtag == 6)
  {
  controllerData.dpadRightOn = 1;
  }
  if(Buttonpadtag == 1005)
  {
  controllerData.l1On = 1;
  }
  if(Buttonpadtag == 2005)
  {
  controllerData.l2On = 1;
  }
  if(Buttonpadtag == 105)
  {
  controllerData.r1On = 1;
  }
  if(Buttonpadtag == 205)
  {
  controllerData.r2On = 1;
  }
  if(Buttonpadtag == 75)
  {
  controllerData.selectOn = 1;
  }
  if(Buttonpadtag == 85)
  {
  controllerData.startOn = 1;
  }
  if(Buttonpadtag == 15)
  {
  controllerData.homeOn = 1;
  }
  
  
 // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
  controllerData.leftStickX = LeftjoyX;
  controllerData.leftStickY = LeftjoyY;
  controllerData.rightStickX = RightjoyX;
  controllerData.rightStickY = RightjoyY;
  // And return the data!
  return controllerData;
}



