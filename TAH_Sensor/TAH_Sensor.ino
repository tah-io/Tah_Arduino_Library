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


int Sensor_Type; // Tells type of sensor
int Pin_No; // Tells to which pin sensor is attached



int D2state,D3state,D4state,D5state,D6state,D7state,D8state,D9state,D10state,D11state,D12state,D13state;  // Parameters for Holding Digital Pin Status;


/////////////////



int Input_Buffer[11];


void setup()
{
Serial1.begin(57600);
Serial.begin(9600);

}


void loop()
{
    
         
   if(Serial1.available())
   {
     
      

      Sensor_Type = Serial1.parseInt();
      Pin_No = Serial1.parseInt();

      
      if(Serial1.read() == 'S')
      {
        

      ////////////// Sonar Sensor ////////////
      if(Sensor_Type == 0)
      {
         updateSonarSensor(Pin_No);
      }
      //////////////////////////////////////////////
      
      
      //////////////Pin Type Analog ////////////
      else if(Sensor_Type == 1 )
      {
         updateTemperatureSensor(Pin_No);
      }

      //////////////////////////////////////////////
      
      
       //////////////Pin Type Servo ////////////
      else if(Sensor_Type == 2)
       {

       }

      ////////////////////////////////////////////// 
      
      else if(Sensor_Type == 3)
      {

      }

     
   
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
  
  
  Serial1.print("D");
  Serial1.print(Pin_No);
  Serial1.print(":");
  Serial1.println(duration);
  
  
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
  
  Serial1.print("D");
  Serial1.print(Pin_No);
  Serial1.print(":");
  Serial1.println(temp);
  
  
}

