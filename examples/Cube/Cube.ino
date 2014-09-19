#include <TAH.h>

int Xaxis = A4;
int Yaxis = A3;
int Zaxis = A2;

TAH myTAH;

int X,Y,Z;

void setup()
{
  Serial.begin(9600);
  myTAH.begin(9600);                        // Start TAH ble serial port

  pinMode(Xaxis,INPUT);
  pinMode(Yaxis,INPUT);
  pinMode(Zaxis,INPUT);
  
  myTAH.enterCommandMode();                 // Enters TAH command mode
 
  myTAH.setName("Cube"); 
 
  myTAH.setWorkRole(SLAVE);
  myTAH.setAuth(OPEN);
  myTAH.setiBeaconMode(ON);


  
  myTAH.exitCommandMode();                  // Saves changed settings and exit command mode



}

void loop()
{
   X = analogRead(Xaxis);
   Y = analogRead(Yaxis);
   Z = analogRead(Zaxis);
  /*
  Serial.print("X: ");
  Serial.print(X);
  
  Serial.print("  ");
  
  Serial.print("Y: ");
  Serial.print(Y);
  
  Serial.print("  ");
  
  Serial.print("Z: ");
  Serial.println(Z);
  */
  
 
  if(Y >= 270)
    {
      myTAH.println("1");
      Serial.println("1");
    }
   else if(Y <= 210)
    {
     myTAH.println("6");
     Serial.println("6");
    }
    
      if(X >= 270)
    {
      myTAH.println("3");
      Serial.println("3");
    }
   else if(X <= 210)
    {
     myTAH.println("4");
     Serial.println("4");
    }
    
    
      if(Z >= 270)
    {
      myTAH.println("5");
      Serial.println("5");
    }
   else if(Z <= 210)
    {
     myTAH.println("2");
     Serial.println("2");
    }
    
    
    
  
     
 delay(700);
}
