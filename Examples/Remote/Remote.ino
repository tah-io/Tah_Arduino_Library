/*
 UNKNOWN 0
 NEC 1
 SONY 2
 RC5 3
 RC6 4
 PANASONIC_OLD 5
 JVC 6
 NECX 7

*/

#include <IRLib.h>
#include <TAH.h>

TAH myTAH;

int RECV_PIN = 11;

IRrecv My_Receiver(RECV_PIN);
IRsend My_Sender;

IRdecode My_Decoder;



void setup()
{
  Serial.begin(9600);
  myTAH.begin(9600);
  delay(500);
  My_Receiver.enableIRIn(); // Start the receiver
  
  myTAH.enterCommandMode();

  myTAH.setName("Remote");
  myTAH.setWorkRole(SLAVE);
  myTAH.setAuth(OPEN);
  myTAH.setWorkMode(REMOTE_CONTROL);
  myTAH.setiBeaconMode(ON);

  myTAH.exitCommandMode();


}

void loop() 

{
 
  
  if (myTAH.available() > 0)
  {
    
    unsigned long protocol = myTAH.parseInt();
    unsigned long value = myTAH.parseInt();
    unsigned long bits = myTAH.parseInt();
    
            
    Serial.print(protocol); Serial.print(",");
    Serial.print(value); Serial.print(",");
    Serial.println(bits);
    
    if(myTAH.read() == 'R')
    {
    
      if(protocol == NEC)
      {
        for(int i=0;i<=2;i++)
        {
        My_Sender.send(NEC,value,bits);
        }
      }
      
      else if(protocol == SONY)
      {
        My_Sender.send(SONY,value,bits);
      }
      
      else if(protocol == RC5)
      {
        for(int i=0;i<=2;i++)
        {
        My_Sender.send(RC5,value,bits);
        }
      }
      
      else if(protocol == RC6)
      {
        for(int i=0;i<=2;i++)
        {
       My_Sender.send(RC6,value,bits);
        }
      }
      
      else if(protocol == PANASONIC_OLD)
      {
        My_Sender.send(PANASONIC_OLD,value,bits);
      }
      
      else if(protocol == JVC)
      {
       My_Sender.send(JVC,value,bits);
      }
      
      else if(protocol == NECX)
      {
       My_Sender.send(NECX,value,bits);
      }
      
      
      }
      
      My_Receiver.enableIRIn();
      
    }
  
  
  
  
   if(My_Receiver.GetResults(&My_Decoder)) 
  {
    //Restart the receiver so it can be capturing another code
    //while we are working on decoding this one.
    
    My_Decoder.decode();
    My_Receiver.resume(); 
    
    int rxtype,rxbits;
   unsigned long rxvalue;
   
   rxtype = My_Decoder.decode_type;
   rxvalue = My_Decoder.value;
   rxbits = My_Decoder.bits;

 if(rxvalue == REPEAT)
 {
 Serial.println("Repeat Values Received: Ignoring...");
 }
 
 else
 {
    myTAH.print(rxtype);
    myTAH.print(",");
    myTAH.print(rxvalue);
    myTAH.print(",");
    myTAH.print(rxbits);
    
    Serial.print(rxtype);
    Serial.print(",");
    Serial.print(rxvalue);
    Serial.print(",");
    Serial.println(rxbits);
 }  

 
 }
  
  
  
  
}
  
  
  
  
 
  





  
  








