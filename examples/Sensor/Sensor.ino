/*
   
   Sensor Type: 
       0 = Sonar,  
       1 = Temperature,  
       2 = Touch,  
       3 = LDR,  
       4 = Rain,  
       5 = Wind,  
       6 = PIR Motion,  
       7 = Soil Moisture 
       
   Pin No: 
       From 2 to 13 and 
       410 to 415 represents A0 to A5 pins


   e.g: 0,2S: Updates the Sonar Sensor value in App coonected to Digital Pin 2. And "S" is the end line character for TAH sensor app.

   
*/
#include<TAH.h>

TAH myTAH;

int Sensor_Type; // Tells type of sensor
int Pin_No; // Tells to which pin sensor is attached



int D2state,D3state,D4state,D5state,D6state,D7state,D8state,D9state,D10state,D11state,D12state,D13state;  // Parameters for Holding Digital Pin Status;


/////////////////



int Input_Buffer[11];


void setup()
{

Serial.begin(9600);
myTAH.begin(9600);


myTAH.enterCommandMode();

myTAH.setName("Tah sensor");
myTAH.setWorkRole(SLAVE);
myTAH.setAuth(OPEN);
myTAH.setWorkMode(REMOTE_CONTROL);
myTAH.setiBeaconMode(ON);

myTAH.exitCommandMode();

}


void loop()
{
    
         
   if(myTAH.available())
   {
     
      

      Sensor_Type = myTAH.parseInt();
      Pin_No = myTAH.parseInt();

      Serial.print(Sensor_Type);
      Serial.print(",");
      Serial.println(Pin_No);
       

      
      if(myTAH.read() == 'S')
      {
        

      ////////////// Sonar Sensor ////////////
      if(Sensor_Type == 0)
      {
         updateSonarSensor(Pin_No);
      }
      //////////////////////////////////////////////
      
      
      ////////////// Temperature Sensor ////////////
      else if(Sensor_Type == 1 )
      {
         updateTemperatureSensor(Pin_No);
      }

      //////////////////////////////////////////////
      
      
       ////////////// Touch Sensor ////////////////
      else if(Sensor_Type == 2)
       {
          updateTouchSensor(Pin_No);
       }

      ////////////////////////////////////////////// 
      
     
     ////////////// Light Sensor //////////////////
      else if(Sensor_Type == 3)
      {
          updateLightSensor(Pin_No);
      }
     
     //////////////////////////////////////////////
     
     
     ////////////// Rain Sensor //////////////////
      else if(Sensor_Type == 4)
      {
          updateRainSensor(Pin_No);
      }
     
     //////////////////////////////////////////////
     
     
     ////////////// Wind Sensor //////////////////
      else if(Sensor_Type == 5)
      {
          updateWindSensor(Pin_No);
      }
     
     //////////////////////////////////////////////
     
     
     ////////////// PIR Motion Sensor ////////////
      else if(Sensor_Type == 6)
      {
          updatePIRMotionSensor(Pin_No);
      }
     
     //////////////////////////////////////////////
     
     
     ////////////// Soil Moisture Sensor /////////
      else if(Sensor_Type == 7)
      {
          updateSoilMoistureSensor(Pin_No);
      }
     
     //////////////////////////////////////////////
     
   
      }
   }
}





// 0: Sonar Sensor Data Read Function
void updateSonarSensor(int Pin_No)
{

  long duration;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(Pin_No, OUTPUT);
  digitalWrite(Pin_No, LOW);
  delayMicroseconds(2);
  digitalWrite(Pin_No, HIGH);
  delayMicroseconds(5);
  digitalWrite(Pin_No, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(Pin_No, INPUT);
  duration = pulseIn(Pin_No, HIGH);
  
  
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(duration);
  
  
}




// 1: Temperature Sensor Data Read Function
void updateTemperatureSensor(int Pin_No)
{

  int temp;
  
  if(Pin_No == 410)
  {
    pinMode(A0, INPUT);
    temp = analogRead(A0);
  }
  else if(Pin_No == 411)
  {
    pinMode(A1, INPUT);
    temp = analogRead(A1);
  }
  else if(Pin_No == 412)
  {
    pinMode(A2, INPUT);
    temp = analogRead(A2);
  }
  else if(Pin_No == 413)
  {
    pinMode(A3, INPUT);
    temp = analogRead(A3);
  }
  else if(Pin_No == 414)
  {
    pinMode(A4, INPUT);
    temp = analogRead(A4);
  }
  else if(Pin_No == 415)
  {
    pinMode(A5, INPUT);
    temp = analogRead(A5);
  }
  
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(temp);
  
  
}




// 2: Touch Sensor Data Read Function
void updateTouchSensor(int Pin_No)
{
  int touch;
   
  touch = digitalRead(Pin_No);
  
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(touch);
  
  
}



// 3: Light Sensor Data Read Function
void updateLightSensor(int Pin_No)
{
  int light;
  
  
    if(Pin_No == 410)
  {
    pinMode(A0, INPUT);
    light = analogRead(A0);
  }
  else if(Pin_No == 411)
  {
    pinMode(A1, INPUT);
    light = analogRead(A1);
  }
  else if(Pin_No == 412)
  {
    pinMode(A2, INPUT);
    light = analogRead(A2);
  }
  else if(Pin_No == 413)
  {
    pinMode(A3, INPUT);
    light = analogRead(A3);
  }
  else if(Pin_No == 414)
  {
    pinMode(A4, INPUT);
    light = analogRead(A4);
  }
  else if(Pin_No == 415)
  {
    pinMode(A5, INPUT);
    light = analogRead(A5);
  }
  
  light = map(light,0,1023,0,100);
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(light);
  
  
}



// 4: Rain Sensor Data Read Function
void updateRainSensor(int Pin_No)
{
  int rain;
  
    if(Pin_No == 410)
  {
    pinMode(A0, INPUT);
    rain = analogRead(A0);
  }
  else if(Pin_No == 411)
  {
    pinMode(A1, INPUT);
    rain = analogRead(A1);
  }
  else if(Pin_No == 412)
  {
    pinMode(A2, INPUT);
    rain = analogRead(A2);
  }
  else if(Pin_No == 413)
  {
    pinMode(A3, INPUT);
    rain = analogRead(A3);
  }
  else if(Pin_No == 414)
  {
    pinMode(A4, INPUT);
    rain = analogRead(A4);
  }
  else if(Pin_No == 415)
  {
    pinMode(A5, INPUT);
    rain = analogRead(A5);
  }
   
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(rain);
  
  
}



// 5: Wind Sensor Data Read Function
void updateWindSensor(int Pin_No)
{
  int wind;
  
    if(Pin_No == 410)
  {
    pinMode(A0, INPUT);
    wind = analogRead(A0);
  }
  else if(Pin_No == 411)
  {
    pinMode(A1, INPUT);
    wind = analogRead(A1);
  }
  else if(Pin_No == 412)
  {
    pinMode(A2, INPUT);
    wind = analogRead(A2);
  }
  else if(Pin_No == 413)
  {
    pinMode(A3, INPUT);
    wind = analogRead(A3);
  }
  else if(Pin_No == 414)
  {
    pinMode(A4, INPUT);
    wind = analogRead(A4);
  }
  else if(Pin_No == 415)
  {
    pinMode(A5, INPUT);
    wind = analogRead(A5);
  }
   
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(wind);
  
  
}



// 6: PIR Motion Sensor Data Read Function
void updatePIRMotionSensor(int Pin_No)
{
  int motion;
  
  motion = digitalRead(Pin_No);
   
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(motion);
  
  
}



// 7: Soil Moisture Sensor Data Read Function
void updateSoilMoistureSensor(int Pin_No)
{
  int moisture;
  
    if(Pin_No == 410)
  {
    pinMode(A0, INPUT);
    moisture = analogRead(A0);
  }
  else if(Pin_No == 411)
  {
    pinMode(A1, INPUT);
    moisture = analogRead(A1);
  }
  else if(Pin_No == 412)
  {
    pinMode(A2, INPUT);
    moisture = analogRead(A2);
  }
  else if(Pin_No == 413)
  {
    pinMode(A3, INPUT);
    moisture = analogRead(A3);
  }
  else if(Pin_No == 414)
  {
    pinMode(A4, INPUT);
    moisture = analogRead(A4);
  }
  else if(Pin_No == 415)
  {
    pinMode(A5, INPUT);
    moisture = analogRead(A5);
  }
   
  moisture = map(moisture,0,1023,0,100); 
   
  myTAH.print("D");
  myTAH.print(Pin_No);
  myTAH.print(":");
  myTAH.println(moisture);
  
  
}
