/*
Author:         Robbie Brandrick
Date:           December 30, 2015
Description:    Code for the science fiction spacecraft interface built with an
                Arduino Uno. When the arduino starts up turn the green LED on and 
                when the push button is pressed turn off the green LED and blink the
                two red LEDs to make it seem like the spacecrafts hyperdrive has
                been engaged.
*/

const int pushButtonPinNum = 2;
const int greenLEDPinNum = 3;
const int redLED1PinNum = 4;
const int redLED2PinNum = 5;
const int redLEDBlinkDelay = 250;
int pushButtonState = 0;

/* Sets up the arduino's digital pins */
void setup(){
    
    pinMode(pushButtonPinNum, INPUT);
    pinMode(greenLEDPinNum, OUTPUT);
    pinMode(redLED1PinNum, OUTPUT);
    pinMode(redLED2PinNum, OUTPUT);
    
}

/*Continous loop which allows the user to engage hyperdrive*/
void loop(){
        
    if(PushButtonIsPressed()){
     
        TurnOffGreenLEDAndBlinkRedLEDs();
        
    } else {
        
        TurnOnGreenLEDAndTurnOffRedLEDs();
        
    }
    
}

/* Determines if the switch has been pressed */
boolean PushButtonIsPressed(){
    
    ReadSwitchSensor();
    
    return pushButtonState == HIGH;
    
}

/* Reads the push button sensor to determine whether is been pressed */
void ReadSwitchSensor(){
    
    pushButtonState = digitalRead(pushButtonPinNum);
    
}

/* Turn green LED off and blink red LEDs to make it seem like hyperdrive has been engaged */
void TurnOffGreenLEDAndBlinkRedLEDs(){
    
    digitalWrite(greenLEDPinNum, LOW);   // Turn off Green LED 1
    digitalWrite(redLED1PinNum, LOW);   // Turn off Red LED 1
    digitalWrite(redLED2PinNum, HIGH);  // Turn on Red LED 2

    delay(redLEDBlinkDelay);

    digitalWrite(redLED1PinNum, HIGH);  // Turn on Red LED 1
    digitalWrite(redLED2PinNum, LOW);   // Turn off Red LED 2

    delay(redLEDBlinkDelay);     
    
}

/* Turn on the green LED and turn off the red LEDs to make it seem like hyperdrive has been disengaged*/
void TurnOnGreenLEDAndTurnOffRedLEDs(){
    
    digitalWrite(greenLEDPinNum, HIGH);  // Turn on Green LED 1
    digitalWrite(redLED1PinNum, LOW);   // Turn off Red LED 1
    digitalWrite(redLED2PinNum, LOW);   // Turn off Red LED 2
    
}
