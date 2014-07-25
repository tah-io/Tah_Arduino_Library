
// pins for the LEDs:
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;

void setup() {
  // initialize serial:
   Serial.begin(9600);
   Serial1.begin(57600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 

}

void loop() {

   if (Serial1.available()) 
   {

    int red = Serial1.parseInt(); 
    // do it again:
    int green = Serial1.parseInt(); 
    // do it again:
    int blue = Serial1.parseInt(); 
    


    if (Serial1.read() == 'R') 
    {

      
      // fade the red, green, and blue legs of the LED: 
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
      
      Serial.print(red);
      Serial.print(",");
      Serial.print(green);
      Serial.print(",");
      Serial.println(blue);


    }
  }
}








