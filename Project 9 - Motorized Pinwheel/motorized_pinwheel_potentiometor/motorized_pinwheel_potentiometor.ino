/*
 * Controls a 9v motor via a potentiometer
 */
 
const int motorPin = 9;
const int potentiometerPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {

  int potentiometerValue = analogRead(potentiometerPin);
  int motorValue = map(potentiometerValue, 0, 1023, 0, 255);

  Serial.print("Potentiometer Value: ");
  Serial.print(potentiometerValue);
  Serial.print(" Motor Value: ");
  Serial.println(motorValue);

  analogWrite(motorPin, motorValue); 
  
}
