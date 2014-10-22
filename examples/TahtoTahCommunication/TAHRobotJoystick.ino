#include <TAH.h>

int Xaxis = A1;
int Yaxis = A2;
int Zaxis = A0;

TAH myTAH;

int X,Y,Z;

void setup()
{
  Serial.begin(9600);
  myTAH.begin(9600); // Start TAH ble serial port
  
  pinMode(Xaxis,INPUT);
  pinMode(Yaxis,INPUT);
  pinMode(Zaxis,INPUT);

  myTAH.enterCommandMode(); // Enters TAH command mode
  myTAH.setName("Joystick");
  myTAH.setWorkRole(MASTER);
  myTAH.setWorkType(IMMEDIATELY);
  myTAH.setUARTNotification(ON);
  myTAH.setDeviceScanFilter(ALL_BLE);
  myTAH.setiBeaconDeployMode(BROADCAST_AND_SCAN);

  myTAH.setiBeaconMode(ON);
  myTAH.exitCommandMode(); // Saves changed settings and exit command mode
}

void loop()
{
  X = analogRead(Xaxis);
  Y = analogRead(Yaxis);
  Z = analogRead(Zaxis);
  
    if(Y >= 390)
    {
      myTAH.println("4");
      Serial.println("4");
    }
    else if(Y <= 300)
    {
      myTAH.println("3");
      Serial.println("3");
    }
    if(X >= 390)
    {
      myTAH.println("1");
      Serial.println("1");
    }
    else if(X <= 300)
    {
      myTAH.println("6");
      Serial.println("6");
    }
    if(Z >= 390)
    {
      myTAH.println("5");
      Serial.println("5");
    }
   /* else if(Z <= 300)
    {
      myTAH.println("2");
      Serial.println("2");
    }
   */
    delay(500);
}
