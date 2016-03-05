/*
 *Vary speeds of a 9v motor depending upon the light that hits the photoresistor.
 */
const int photoresistoryPin = A0;
const int motorPin = 9;
int highLight = 0;
int lowLight = 1023;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(13, OUTPUT);


  digitalWrite(13, HIGH);
  while(millis() < 4000){

    int photoresistorValue = analogRead(photoresistoryPin);
    
    if(photoresistorValue > highLight){
      highLight = photoresistorValue;
    } 

    if(photoresistorValue < lowLight){
      lowLight = photoresistorValue;
    } 
    
  }

  Serial.print("High Light: ");
  Serial.print(highLight);
  Serial.print(" Low Light: ");
  Serial.println(lowLight);
  
  
  digitalWrite(13, LOW);
}

void loop() {
  
  int photoresistorValue = analogRead(photoresistoryPin);
  int motorValue = map(photoresistorValue, lowLight, highLight, 0, 255);
  Serial.print("Photoresistor Value: ");
  Serial.print(photoresistorValue);
  Serial.print(" Motor Value: ");
  Serial.println(motorValue);
  
  analogWrite(motorPin, photoresistorValue);

}
