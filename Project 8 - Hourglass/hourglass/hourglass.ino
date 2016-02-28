/*
 *Every ten minutes turn an LED on until all 6 have been turned on. Once they are all on, then
 *make the LEDs blink on and off in a pattern. If the tilt switch state has changed then restart
 *the 'Hourglass' timer.
 */
const unsigned long interval = 600000;
const int switchPin = 9;
unsigned long lastIntervalsTime = 0;
int lastSwitchState = 0;
int led = 2;
int patternNumber = 0;

void setup() {

  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(switchPin, INPUT);

  lastSwitchState = digitalRead(switchPin);
}

void loop() {
  int switchState = digitalRead(switchPin);
  unsigned long currentTime = millis();

  if (switchState != lastSwitchState) {

    lastSwitchState = switchState;
    led = 2;
    for (int i = 2; i <= 8; i++) {
      digitalWrite(i, LOW);
    }

    lastIntervalsTime = currentTime;


  }

  if (currentTime > (lastIntervalsTime + interval) && led < 8) {
    lastIntervalsTime += interval;

    digitalWrite(led, HIGH);

    led++;

  }

  if (led == 8) {

    if (patternNumber == 7) {
      patternNumber = 0;
    }

    for (int i = 8; i >= 8 - patternNumber; i--) {
      digitalWrite(i, LOW);
      delay(100);
      digitalWrite(i, HIGH);
    }

    patternNumber++;

  }

}
