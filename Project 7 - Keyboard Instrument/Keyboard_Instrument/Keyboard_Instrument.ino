int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyValue = analogRead(A0);
  Serial.println(keyValue);

  if (keyValue >= 990 && keyValue <= 1023) {
    tone(8, notes[0]);
  } else if (keyValue >= 505 && keyValue <= 515) {
    tone(8, notes[1]);
  } else if (keyValue >= 150 && keyValue <= 200) {
    tone(8, notes[2]);
  } else if (keyValue > 0 && keyValue <= 100) {
    tone(8, notes[3]);
  } else {
    noTone(8);
  }

}
