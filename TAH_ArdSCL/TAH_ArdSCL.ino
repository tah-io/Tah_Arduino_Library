/*

   
   Pin Type: 0 = DIGITAL,  1 = ANALOG,  2 = SERVO,  3 = Send Pin Status
   Pin No: From 2 to 13 and 410 to 415 represents A0 to A5 pins
   Pin Value: 0 or 1 for Digital
              0 to 255 for Analog
              0 to 180 for Servo

   e.g: Turn on Led 13- 0,13,1R

   
*/

#include <Servo.h> 


int Pin_Type;      //  Stores Pin Type  D:Digital, A:Analog ,S:Servo Function  // 
int Pin_No;               //  Stores Pin Number starting either from 000 to 999 OR from A00 to A999
int Pin_Value;            //  Stores Pin Value 0001 or 0000 for digital, 0000 to 1023 for Analog, 0000 to 0180 for Servo Function



int D2state,D3state,D4state,D5state,D6state,D7state,D8state,D9state,D10state,D11state,D12state,D13state;  // Parameters for Holding Digital Pin Status;
int A0state,A1state,A2state,A3state,A4state,A5state; // Parameters for holding Analog Pin Status

int AppValueUpdateRate = 14;

/////////////////



int Input_Buffer[11];
Servo servo[30];

void setup()
{
Serial1.begin(57600);
Serial.begin(9600);

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
    
         
     if(Serial1.available())
    {
     
      

      Pin_Type = Serial1.parseInt();
      Pin_No = Serial1.parseInt();
      Pin_Value = Serial1.parseInt();

      Serial.print(Pin_Type);
      Serial.print(",");
      Serial.print(Pin_No);
      Serial.print(",");
      Serial.println(Pin_Value);
      
      if(Serial1.read() == 'R')
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
        
        Serial1.print("A0:");
        Serial1.println(A0state);
        delay(AppValueUpdateRate);
        
        Serial1.print("A1:");
        Serial1.println(A1state);
        delay(AppValueUpdateRate);
        
        Serial1.print("A2:");
        Serial1.println(A2state);
        delay(AppValueUpdateRate);
        
        Serial1.print("A3:");
        Serial1.println(A3state);
        delay(AppValueUpdateRate);
        
        Serial1.print("A4:");
        Serial1.println(A4state);
        delay(AppValueUpdateRate);
        
        Serial1.print("A5:");
        Serial1.println(A5state);
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
 
  
  
 /////////// Update Digital Values ///////////////

        Serial1.print("D2:");
        Serial1.println(D2state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D3:");
        Serial1.println(D3state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D4:");
        Serial1.println(D4state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D5:");
        Serial1.println(D5state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D6:");
        Serial1.println(D6state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D7:");
        Serial1.println(D7state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D8:");
        Serial1.println(D8state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D9:");
        Serial1.println(D9state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D10:");
        Serial1.println(D10state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D11:");
        Serial1.println(D11state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D12:");
        Serial1.println(D12state);
        delay(AppValueUpdateRate);
        
        Serial1.print("D13:");
        Serial1.println(D13state);
        delay(AppValueUpdateRate);
        
      /*  Serial.print(D2state);
        Serial.print(D3state);
        Serial.print(D4state);
        Serial.print(D5state);
        Serial.print(D6state);
        Serial.print(D7state);
        Serial.print(D8state);
        Serial.print(D9state);
        Serial.print(D10state);
        Serial.print(D11state);
        Serial.print(D12state);
        Serial.println(D13state); */
        
//////////////////////////////////////////////////   
}


