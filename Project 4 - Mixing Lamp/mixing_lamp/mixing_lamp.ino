/*
 * Author:      Robbie Brandrick
 * Date:        January 2, 2016
 * Description: Using a tri-colour LED and three photoresistors create a lamp that smoothly changes colors 
 *              depending on external lighting conditions.
 */
 
const int redLEDPin = 11;
const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {

  Serial.begin(9600);

  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

}

void loop() {
  
  //Read photoresistor sensors for RGB values
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  //Print photoresistor sensors values
  Serial.print("Raw sensor values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);

  //Set up the new RGB values
  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;    

  //Print new RGB values
  Serial.print("Mapped sensor values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);  

  //Show new RGB values
  analogWrite(redLEDPin, 128);
  analogWrite(greenLEDPin, 255);
  analogWrite(blueLEDPin, 128);
  
}
