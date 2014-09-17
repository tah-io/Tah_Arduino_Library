void setup() 
{
  
  // initialize serial:
  Serial.begin(9600);
  Serial1.begin(9600);

 delay(1000);

Serial1.write("AT+NAMETAH");
delay(1000);\
Serial1.write("AT+BAUD3");
delay(1000);
Serial1.write("AT+MODE2");
delay(1000);
Serial1.write("AT+IBEA1");
delay(1000);
Serial1.write("AT+RESET");
delay(1000);


}


void loop()
{


}
