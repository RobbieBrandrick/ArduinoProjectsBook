#include "pitches.h"

int notes[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5}; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyValue = analogRead(A0);
  Serial.println(keyValue);

  if (keyValue >= 1000 && keyValue <= 1023) {
    tone(8, notes[0]);
  } else if (keyValue >= 505 && keyValue <= 512) {
    tone(8, notes[1]);
  } else if (keyValue >= 170 && keyValue <= 190) {
    tone(8, notes[2]);
  } else if (keyValue > 0 && keyValue <= 25) {
    tone(8, notes[3]);
  } else if (keyValue > 190 && keyValue <= 205) {
    tone(8, notes[4]);    
  } else if (keyValue > 513 && keyValue <= 520) {
    tone(8, notes[5]);        
  } else if (keyValue > 550 && keyValue <= 565) {
    tone(8, notes[6]);       
  } else {
    noTone(8);
  }

}
