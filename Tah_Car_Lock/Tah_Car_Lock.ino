
String sensor;
int interval = 1000;

void setup()
{

pinMode(11,OUTPUT);
pinMode(12,OUTPUT);


digitalWrite(11,LOW);
digitalWrite(12,LOW);

Serial.begin(9600);
Serial1.begin(9600);

delay(interval);

Serial1.write("AT+START");

/*
Serial.print("Setting up Tah, Plase Wait....");
Serial1.write("AT+RENEW");
delay(interval);
Serial1.write("AT+RESET");
delay(interval);
Serial1.write("AT+ROLE1");
delay(interval);
Serial1.write("AT+IMME1");
delay(interval);
Serial1.write("AT+FILT0");
delay(interval);
Serial1.write("AT+SHOW1");
delay(interval);
Serial1.write("AT+POWE3");
delay(interval);
Serial1.write("AT+NOTI1");
delay(interval);
Serial1.write("AT+RESET");
delay(interval);
Serial1.write("AT+DISC?");
delay(2*interval);
Serial1.write("AT+CONN1");
delay(interval);
Serial1.write("AT+START");
delay(interval);

Serial.print("Initialization Completed");
*/

}


void loop()
{

while( Serial1.available() == 0);

  char state = Serial1.read();
  
  sensor+=state;

if(state == 'N')
{
unlock();
}

else if(state == 'T')
{
lock();
}

else
{
digitalWrite(11,LOW);
digitalWrite(12,LOW);
}



Serial.print(state);
//Serial.println("");
Serial1.flush(); 


}


void unlock()
{
  digitalWrite(12,HIGH);
  delay(50);
  digitalWrite(12,LOW);
}


void lock()
{
  digitalWrite(11,HIGH);
  delay(50);
  digitalWrite(11,LOW);
}
