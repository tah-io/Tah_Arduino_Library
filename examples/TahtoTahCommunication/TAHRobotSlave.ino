#include <TAH.h>

///motor pins
#define  motorA_1  12
#define  motorA_2  11
#define  motorB_1  10
#define  motorB_2  9

#define  Lights   4 
#define  LDRpin   A5


void Forward()
{
    digitalWrite(motorA_1,HIGH);
    digitalWrite(motorA_2,LOW);
    digitalWrite(motorB_1,LOW);
    digitalWrite(motorB_2,HIGH);
    
}
void Reverse()
{
    digitalWrite(motorA_1,LOW);
    digitalWrite(motorA_2,HIGH);
    digitalWrite(motorB_1,HIGH);
    digitalWrite(motorB_2,LOW);
    
}
void Stop()
{
    digitalWrite(motorA_1,LOW);
    digitalWrite(motorA_2,LOW);
    digitalWrite(motorB_1,LOW);
    digitalWrite(motorB_2,LOW);
    
}

void TurnLeft(int t)
{
    digitalWrite(motorA_1,LOW);
    digitalWrite(motorA_2,HIGH);
    
    digitalWrite(motorB_1,LOW);
    digitalWrite(motorB_2,HIGH);
    delay(t);
}
void TurnRight(int t)
{
    digitalWrite(motorA_1,HIGH);
    digitalWrite(motorA_2,LOW);
    
    digitalWrite(motorB_1,HIGH);
    digitalWrite(motorB_2,LOW);
    delay(t);
}

void headLights()
{
    int darkness = analogRead(LDRpin);
    //Serial.println(darkness);
    
    if(darkness > 1000)
    {
        digitalWrite(Lights,HIGH);
    } 
    else digitalWrite(Lights,LOW);
}

TAH myTAH;

void setup()  
{
 
  Serial.begin(9600);                       // Open serial port
  myTAH.begin(9600);                        // Start TAH ble serial port
  
  myTAH.enterCommandMode();                 // Enters TAH command mode
 
 
 myTAH.setName("ROBOT"); 
 
 myTAH.setWorkRole(SLAVE);
 myTAH.setAuth(OPEN);
 myTAH.setiBeaconMode(ON);
 myTAH.setiBeaconMajorValue("0064");       // Input MAJOR Value in HEX
 myTAH.setiBeaconMinorValue("0001");       // Input MINOR Value in HEX

  
 myTAH.exitCommandMode();                  // Saves changed settings and exit command mode
  
///Motor Connections
  pinMode(motorA_1,OUTPUT);
  pinMode(motorA_2,OUTPUT);
  pinMode(motorB_1,OUTPUT);
  pinMode(motorB_2,OUTPUT);
  pinMode(LDRpin,INPUT);
  pinMode(Lights,OUTPUT);       //Digital IO  4
  
  
  digitalWrite(motorA_1,LOW);
  digitalWrite(motorA_2,LOW);
  digitalWrite(motorB_1,LOW);
  digitalWrite(motorB_2,LOW);
  
  
}

void loop() // run over and over
{
  
  if (myTAH.available() > 0)            //if data avaliable on BLE serial
  {
   
   //Serial.write(myTAH.read());    //read from BLE serial port and write to Arduino Serial port
     
    int val = myTAH.read();
    
    if(val == '1')              // Forward
    {
      Serial.println("Stop");
      Reverse();      
    }
     else if(val == '3')            //Left Turn
    {
      Serial.println("Right Turn");
      TurnRight(500);
    }
    else if(val == '4')          // Right Turn 
    {  
      Serial.println("Left Turn");
      TurnLeft(500);  
     }

    else if(val == '5')
    {
      Serial.println("Stop");
      Stop();
    }
    else if(val == '6')
    {
      Serial.println("Forward");
      Forward();
      
    }    
  }
  
  if (Serial.available())          //if serial data is avaliable
  {
    
        myTAH.write(Serial.read());
   }

  headLights();  
 
}

