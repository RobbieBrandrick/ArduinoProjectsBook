/*
 * Controls a 9V motor in three ways: a momentary switch to toggle between motor on/off, a momentary 
 * switch to toggle the direction that the motor spins, and a potentiometer to change the speed of the motor.
 */

const int motorDirectionalPin = 4;
const int motorOnOffStateSwitchPin = 5;
const int controlPin1 = 2; //Used with the HBridge to turn motor on/off and switch directions
const int controlPin2 = 3; //Used with the HBridge to turn motor on/off and switch directions
const int motorSpeedPin = A0;
const int motorPin = 9;

int motorOnOffState = 0;
int previousMotorOnOffState = 0;
int motorDirectionalState = 0;
int previousMotorDirectionalState = 0;
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {

  Serial.begin(9600);
  
  pinMode(motorDirectionalPin, INPUT);
  pinMode(motorOnOffStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(motorPin, OUTPUT);

  //Turn of the motor immediately.
  digitalWrite(motorPin, LOW);

}

void loop() {
  
  motorOnOffState = digitalRead(motorOnOffStateSwitchPin);  
  delay(1); //Determine why this delay is necessary.
  motorDirectionalState = digitalRead(motorDirectionalPin);
  motorSpeed = analogRead(motorSpeedPin) / 4;

  if(motorOnOffState != previousMotorOnOffState && motorOnOffState == HIGH){
    motorEnabled = !motorEnabled;
    Serial.println("Changing on/off state");
  }
  
  if(motorDirectionalState != previousMotorDirectionalState && motorDirectionalState == HIGH){
    motorDirection = !motorDirection;
    Serial.println("Changing motor direction");
  }

  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } 
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);    
  }

  if(motorEnabled == 1){
    analogWrite(motorPin, motorSpeed);
  } else {
    analogWrite(motorPin, 0);
  }

  previousMotorOnOffState = motorOnOffState;
  previousMotorDirectionalState = motorDirectionalState;
  
}
