/*
Author:         Robbie Brandrick
Date:           December 30, 2015
Description:    Code for the science fiction spacecraft interface built with an
                Arduino Uno. When the arduino starts up turn the green LED on and 
                when the push button is pressed turn off the green LED and blink the
                two red LEDs to make it seem like the spacecrafts hyperdrive has
                been engaged.
*/

void ReadSwitchSensor();
boolean SwitchIsPressed();
void TurnGreenLEDOffAndBlinkRedLEDs();
void TurnOnGreenLEDAndTurnOffRedLEDs();

const int redLEDBlinkDelay = 250;
int pushButtonState = 0;

/* Sets up the arduino's digital pins */
void setup(){
    
    pinMode(2, INPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    
}

/*Continous loop which allows the user to engage hyperdrive*/
void loop(){
    
    ReadSwitchSensor();
    
    if(SwitchIsPressed()){
     
        TurnGreenLEDOffAndBlinkRedLEDs();
        
    } else {
        
        TurnOnGreenLEDAndTurnOffRedLEDs();
        
    }
    
}

/* Reads the push button sensor to determine whether is been pressed */
void ReadSwitchSensor(){
    
    pushButtonState = digitalRead(2);
    
}

/* Determines if the switch has been pressed */
boolean SwitchIsPressed(){
    
    return pushButtonState == HIGH;
    
}


/* Turn green LED off and blink red LEDs to make it seem like hyperdrive has been engaged */
void TurnGreenLEDOffAndBlinkRedLEDs(){
    
    digitalWrite(3, LOW);   // Turn off Green LED 1
    digitalWrite(4, LOW);   // Turn off Red LED 1
    digitalWrite(5, HIGH);  // Turn on Red LED 2

    delay(redLEDBlinkDelay);

    digitalWrite(4, HIGH);  // Turn on Red LED 1
    digitalWrite(5, LOW);   // Turn off Red LED 2

    delay(redLEDBlinkDelay);     
    
}

/* Turn on the green LED and turn off the red LEDs to make it seem like hyperdrive has been disengaged*/
void TurnOnGreenLEDAndTurnOffRedLEDs(){
    
    digitalWrite(3, HIGH);  // Turn on Green LED 1
    digitalWrite(4, LOW);   // Turn off Red LED 1
    digitalWrite(5, LOW);   // Turn off Red LED 2
    
}