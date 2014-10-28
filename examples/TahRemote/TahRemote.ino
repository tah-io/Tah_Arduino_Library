#include <TAH.h>
#include <IRLib.h>

TAH myTAH;

#define chan0  0x2FD00FF
#define chan1  0x2FD807F
#define chan2  0x2FD40BF 
#define chan3  0x2FDC03F
#define chan4  0x2FD20DF
#define chan5  0x2FDA05F
#define chan6  0x2FD609F 
#define chan7  0x2FDE01F
#define chan8  0x2FD10EF
#define chan9  0x2FD906F
#define power  0x2FD48B7        // Press 'p' power ON/OFF

unsigned long int channelNumber;

IRsend My_Number;      //My_Number  object of class IRsend
int count =0;
 
unsigned long int keyCodes[]= {chan0,chan1,chan2,chan3,chan4,chan5,chan6,chan7,chan8,chan9,power}; 

void Sendcode(unsigned long int channelNumber) {
      for(count =0;count<3;count++) {
      My_Number.send(NEC,keyCodes[channelNumber], 28);
      delay(40);
       Serial.println(keyCodes[channelNumber],HEX);  
    }
}
      

void setup()  
{
 
  Serial.begin(9600);                       // Open serial port
  myTAH.begin(9600);                        // Start TAH ble serial port
  
  myTAH.enterCommandMode();                 // Enters TAH command mode
 
 
 myTAH.setName("IRRemote"); 
 
 myTAH.setWorkRole(SLAVE);
 
 myTAH.setAuth(OPEN);
 myTAH.setiBeaconMode(ON);
 myTAH.setiBeaconMajorValue("0064");       // Input MAJOR Value in HEX
 myTAH.setiBeaconMinorValue("0001");       // Input MINOR Value in HEX

  
myTAH.exitCommandMode();                  // Saves changed settings and exit command mode
  
  
}

void loop() // run over and over
{
  if(myTAH.available())
  {
      int channelNo = myTAH.read()-'0';
      Serial.println(channelNo);
      //Serial.write(val);
      switch(channelNo)
    {
      /* Number of Channels */
      case(0) : Sendcode(0);
                break;
      case(1) : Sendcode(1);
                break;
      case(2) : Sendcode(2);
                break;
      case(3) : Sendcode(3);
                break;
      case(4) : Sendcode(4);
                break;
      case(5) : Sendcode(5);
                break;
      case(6) : Sendcode(6);
                break;
      case(7) : Sendcode(7);
                break;
      case(8) : Sendcode(8);
                break;
      case(9) : Sendcode(9);
                break;
      case(64) ://Serial.println("POWER KEY PRESSED"); 
                Serial.println("power");
                Sendcode(10);                // Power ON/OFF Button Press 'p'
                
                break;
     }
  
 }    
      
}     
