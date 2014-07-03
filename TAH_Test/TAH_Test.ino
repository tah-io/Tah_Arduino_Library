
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial1.begin(57600);

}

void loop() // run over and over
{
  if (Serial1.available())
    Serial.write(Serial1.read());
  if (Serial.available())
    Serial1.write(Serial.read());
}

