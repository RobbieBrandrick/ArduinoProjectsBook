/*
 *Turn on a 9V motor when the momentary switch has been pressed
 */
const int swtichPin = 2;
const int motorPin = 9;
int switchState = 0;


void setup() {
  pinMode(swtichPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  
  switchState = digitalRead(swtichPin);

  if(switchState == HIGH){
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

}
