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
   
   L1+Button:
   ----------
   
   L1+Cross = 11005
   L1+Circle = 21005
   L1+Square = 31005
   L1+Triangle = 41005
  
   L2+Button:
   ----------
   
   L2+Cross = 12005
   L2+Circle = 22005
   L2+Square = 32005
   L2+Triangle = 42005
   
   
   dPad+Button:
   ----------
   
   Up+Cross = 10002
   Up+Circle = 20002
   Up+Square = 30002
   Up+Triangle = -25534
   
   Down+Cross = 10008
   Down+Circle = 20008
   Down+Square = 30008
   Down+Triangle = -25528
   
   Right+Cross = 10006
   Right+Circle = 20006
   Right+Square = 30006
   Right+Triangle = -25530
   
   Left+Cross = 10004
   Left+Circle = 20004
   Left+Square = 30004
   Left+Triangle = -25532
    
////////////////////////////////////////// 

*/ 
    
int LeftjoyX,LeftjoyY,RightjoyX,RightjoyY,Buttonpadtag;



void setup() 
{
  // initialize serial:
   Serial.begin(9600);

   Serial1.begin(57600);


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


    
     
     
     // Left Joystick Mapping
     
     
     LeftjoyX = map(LeftjoyX, -9, 9, 1, 255);
     LeftjoyY = map(LeftjoyY, -9, 9, 255, 1);
     
     
     // Right Joystick Mapping
     
     RightjoyX = map(RightjoyX, -9, 9, 1, 255);
     RightjoyY = map(RightjoyY, -9, 9, 1, 255);
     

    

    
    
    if (Serial1.read() == 'S') // look for the Character 'S'. That's the end of your string:
    {

        // Always be getting fresh data
  dataForController_t SonycontrollerData = SonygetControllerData();
  // Then send out the data over the USB connection
  // Joystick.set(controllerData) also works.
  Joystick.setControllerData(SonycontrollerData);
  Serial.println(Buttonpadtag);
      
    }
  }
}




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
  if(Buttonpadtag == -25531 )
  {
  controllerData.triangleOn = 1;
  Serial.println(" Triangle");
  }
  if(Buttonpadtag == 20005)
  {
  controllerData.circleOn =1;
  Serial.println(" Circle");
  }
  if(Buttonpadtag == 30005)
  {
  controllerData.squareOn =1;
  Serial.println(" Square");
  }
  if(Buttonpadtag == 10005)
  {
  controllerData.crossOn = 1;

  Serial.println(" Cross");
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
  
  
  
  if(Buttonpadtag == 11005)
   {
   controllerData.l1On = 1;
   controllerData.crossOn =1;
   }
   if(Buttonpadtag == 21005)
   {
   controllerData.l1On = 1;
   controllerData.circleOn =1;
   }
   if(Buttonpadtag == 31005)
   {
   controllerData.l1On = 1;
   controllerData.squareOn =1;
   }
   if(Buttonpadtag == -24531)
   {
   controllerData.l1On = 1;
   controllerData.triangleOn =1;
   }
   if(Buttonpadtag == 12005)
   {
   controllerData.l2On = 1;
   controllerData.crossOn =1;
   }
   if(Buttonpadtag == 22005)
   {
   controllerData.l2On = 1;
   controllerData.circleOn =1;
   }
   if(Buttonpadtag == 32005)
   {
   controllerData.l2On = 1;
   controllerData.squareOn =1;
   }
   if(Buttonpadtag == -23531)
   {
   controllerData.l2On = 1;
   controllerData.triangleOn =1;
   }
   
   
   
   
   
   
if(Buttonpadtag == 10002)
{
controllerData.dpadUpOn =1 ;
controllerData.crossOn = 1;
}
if(Buttonpadtag == 20002)
{
controllerData.dpadUpOn =1 ;
controllerData.circleOn =1;
}
if(Buttonpadtag == 30002)
{
controllerData.dpadUpOn =1 ;
controllerData.squareOn =1;
}
if(Buttonpadtag == -25534)
{
controllerData.dpadUpOn =1 ;
controllerData.triangleOn = 1;
}



if(Buttonpadtag == 10008)
{
controllerData.dpadDownOn =1 ;
controllerData.crossOn = 1;
}
if(Buttonpadtag == 20008)
{
controllerData.dpadDownOn =1 ;
controllerData.circleOn =1;
}
if(Buttonpadtag == 30008)
{
controllerData.dpadDownOn =1 ;
controllerData.squareOn =1;
}
if(Buttonpadtag == -25528)
{
controllerData.dpadDownOn =1 ;
controllerData.triangleOn = 1;
}



if(Buttonpadtag == 10006)
{
controllerData.dpadRightOn =1 ;
controllerData.crossOn = 1;
}
if(Buttonpadtag == 20006)
{
controllerData.dpadRightOn =1 ;
controllerData.circleOn =1;
}
if(Buttonpadtag == 30006)
{
controllerData.dpadRightOn =1 ;
controllerData.squareOn =1;
}
if(Buttonpadtag == -25530)
{
controllerData.dpadRightOn =1 ;
controllerData.triangleOn = 1;
}



if(Buttonpadtag == 10004)
{
controllerData.dpadLeftOn =1 ;
controllerData.crossOn = 1;
}
if(Buttonpadtag == 20004)
{
controllerData.dpadLeftOn =1 ;
controllerData.circleOn =1;
}
if(Buttonpadtag == 30004)
{
controllerData.dpadLeftOn =1 ;
controllerData.squareOn =1;
}
if(Buttonpadtag == -25532)
{
controllerData.dpadLeftOn =1 ;
controllerData.triangleOn = 1;
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



