/*

 ArdSCL  
 ------
 This sketch demonstrates the use of Tah App with the board.
 Tah by default ships with this sketch pre-uploaded.
 Refer to Tah website for more details: http://tah.io

 
 Circuit:
 --------
 Just plug in your Tah in USB port or power it up with external 5V power supply.

   
 User Guide:
 ----------- 
   Tah protocol we use to communicate between the App and a Tah is basically a comma seprated string with end character "R".
   This protocol string is composed of 3 integer values with the end suffix "R" which represents end of string. 
 
   1st Integer represents--> Pin Type: 0 = DIGITAL,  1 = ANALOG,  2 = SERVO,  3 = Send Analog Status,  4 = Send Digital Status
   2nd Integer represents--> Pin No: From 2 to 13 for digital pins and 410 to 415 represents A0 to A5 analog pins
   3rd Integer represents--> Pin Value: 0 or 1 for Digital
                             0 to 255 for Analog
                             0 to 179 for Servo

   e.g:  So if we want to turn ON the default led attached to pin 13 then the protocol sting would be => 0,13,1R
      
  
 
 Created Sep 2014
 by Dhiraj Jadhao
 
 This example is in the public domain       
                                                                                                 
   
*/

#include <Servo.h> 
#include<TAH.h>

TAH myTAH;


int Pin_Type;    //  Stores Pin Type  
int Pin_No;      //  Stores Pin Number
int Pin_Value;   //  Stores Pin Value 



int D2state,D3state,D4state,D5state,D6state,D7state,D8state,D9state,D10state,D11state,D12state,D13state;  // Parameters for Holding Digital Pin Status;
int A0state,A1state,A2state,A3state,A4state,A5state; // Parameters for holding Analog Pin Status

int AppValueUpdateRate = 14;   // minimum value: 14 milliseconds

/////////////////



int Input_Buffer[11];
Servo servo[12];

void setup()
{

Serial.begin(9600);
myTAH.begin(9600);

myTAH.enterCommandMode();

myTAH.setName("Tah");
myTAH.setWorkRole(SLAVE);
myTAH.setAuth(OPEN);
myTAH.setWorkMode(REMOTE_CONTROL);
myTAH.setiBeaconMode(ON);

myTAH.exitCommandMode();

for(int i=2;i <= 13;i++)
{
pinMode(i,OUTPUT);
}

for(int i=2;i <= 13;i++)
{
digitalWrite(i,LOW);
}

pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);


}


void loop()
  {

    
    
         
     if(myTAH.available())
    {
     
      

      Pin_Type = myTAH.parseInt();
      Pin_No = myTAH.parseInt();
      Pin_Value = myTAH.parseInt();

      Serial.print(Pin_Type);
      Serial.print(",");
      Serial.print(Pin_No);
      Serial.print(",");
      Serial.println(Pin_Value);
      
      if(myTAH.read() == 'R')
      {
        

      
      //////////////Pin Type Digital ////////////
      if(Pin_Type == 0)
      {
         digitalWrite(Pin_No,Pin_Value);
      }
      //////////////////////////////////////////////
      
      
      //////////////Pin Type Analog ////////////
      else if(Pin_Type == 1 )
      {
        analogWrite(Pin_No,Pin_Value);
      }

      //////////////////////////////////////////////
      
      
       //////////////Pin Type Servo ////////////
      else if(Pin_Type == 2)
       {
         servo[Pin_No].attach(Pin_No);
         servo[Pin_No].write(Pin_Value);
       }

      ////////////////////////////////////////////// 
      
      else if(Pin_Type == 3)
      {
          updateAnalogstate();
      }
      
      else if(Pin_Type == 4)
      {
          updateDigitalstate();
      }
      


    }

  }

}

  




void updateAnalogstate()
{
  
 
  /////////// Check Analog Pin Status //////////////    
         
         A0state = analogRead(A0);
         A1state = analogRead(A1);
         A2state = analogRead(A2);
         A3state = analogRead(A3);
         A4state = analogRead(A4);
         A5state = analogRead(A5);
//////////////////////////////////////////////////

 
  /////////// Update Analog Values ///////////////      
        
        myTAH.print("A0:");
        myTAH.println(A0state);
        delay(AppValueUpdateRate);
        
        myTAH.print("A1:");
        myTAH.println(A1state);
        delay(AppValueUpdateRate);
        
        myTAH.print("A2:");
        myTAH.println(A2state);
        delay(AppValueUpdateRate);
        
        myTAH.print("A3:");
        myTAH.println(A3state);
        delay(AppValueUpdateRate);
        
        myTAH.print("A4:");
        myTAH.println(A4state);
        delay(AppValueUpdateRate);
        
        myTAH.print("A5:");
        myTAH.println(A5state);
        delay(AppValueUpdateRate);
      
////////////////////////////////////////////////// 
}




void updateDigitalstate()
{
     
 /////////// Check Digital Pin Status //////////////   
         D2state = digitalRead(2);
         D3state = digitalRead(3);
         D4state = digitalRead(4);
         D5state = digitalRead(5);
         D6state = digitalRead(6);
         D7state = digitalRead(7);
         D8state = digitalRead(8);
         D9state = digitalRead(9);
         D10state = digitalRead(10);
         D11state = digitalRead(11);
         D12state = digitalRead(12);
         D13state = digitalRead(13);
////////////////////////////////////////////////////  
 /*
      myTAH.print("D");
      myTAH.print(",");
      myTAH.print(D2state);
      myTAH.print(D3state);
      myTAH.print(D4state);
      myTAH.print(D5state);
      myTAH.print(D6state);
      myTAH.print(D7state);
      myTAH.print(D8state);
      myTAH.print(D9state);
      myTAH.print(D10state);
      myTAH.print(D11state);
      myTAH.print(D12state);
      myTAH.println(D13state);
   */   
      
  
  
 /////////// Update Digital Values ///////////////

        myTAH.print("D2:");
        myTAH.println(D2state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D3:");
        myTAH.println(D3state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D4:");
        myTAH.println(D4state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D5:");
        myTAH.println(D5state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D6:");
        myTAH.println(D6state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D7:");
        myTAH.println(D7state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D8:");
        myTAH.println(D8state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D9:");
        myTAH.println(D9state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D10:");
        myTAH.println(D10state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D11:");
        myTAH.println(D11state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D12:");
        myTAH.println(D12state);
        delay(AppValueUpdateRate);
        
        myTAH.print("D13:");
        myTAH.println(D13state);
        delay(AppValueUpdateRate);

        
//////////////////////////////////////////////////   
}


