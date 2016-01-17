/*
 * Author:      Robbie Brandrick
 * Date:        January 16, 2016
 * Description: Using a potentiometer control a servo engine by retriving the values from the 
 *              potentiometer (0 to 1023) and convert it into an angle (0 to 179).
 */

#include <Servo.h>

const int potPin = A0;
const int servoPin = 9;

Servo myServo;

void setup() {
  
  Serial.begin(9600);

  myServo.attach(servoPin);  

}

void loop() {

  //Get the pot value and print it to the Serial Monitor
  int potValue = analogRead(potPin);

  delay(5);
  
  Serial.print("Pot Value: ");
  Serial.print(potValue);

  /*Get the angle we want the Servo to move to based on 
  the pot value and print it to the Serial Monitor*/
  int angle = map(potValue, 0, 1023, 0, 179);

  Serial.print(", Angle Value: ");
  Serial.println(angle);

  //Move the servo to the retrieved angle
  myServo.write(angle);

  delay(15);

}
