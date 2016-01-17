/*
 * Author:      Robbie Brandrick
 * Date:        January 17, 2016
 * Description: Time to make some noise! Using a photoresistor and a piezo \
 *              element, make a light based theremin.
 */
 

const int ledPin = 13;
const int piezoPin = 8;
const int photoresistorPin = A0;

int minLight = 1023;
int maxLight = 0;

void setup() {

  pinMode(ledPin, OUTPUT);

  calibrateSensor();

}

void loop() {

  int photoresistorValue = analogRead(photoresistorPin);

  int pitch = map(photoresistorValue, minLight, maxLight, 0, 4000);

  tone(piezoPin, pitch, 20);

}

/*
 * Sets up the min and max light variables so that they are calibrated with the environment.
 */
void calibrateSensor(){
  
  //Turn on the LED on the arduino to let the user know it is calibrating
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000){
    
    int photoresistorValue = analogRead(photoresistorPin);

    if(photoresistorValue > maxLight){
      maxLight = photoresistorValue;
    }

    if(photoresistorValue < minLight){
      minLight = photoresistorValue;
    }        
    
  }

  //Turn off the LED on the arduino to let the user know it is done calibrating
  digitalWrite(ledPin, LOW);

}

