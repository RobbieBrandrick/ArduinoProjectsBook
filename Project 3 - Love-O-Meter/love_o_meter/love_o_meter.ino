/*
 * Author:      Robbie Brandrick
 * Date:        January 2, 2016
 * Description: Project two in the Arduino Projects Book: The Love-O-Meter. 
 *              Using a temperature sensor and three red LEDs. Get a baseline temperature then for each degree celsius above 
 *              the baseline temperature turn on one of the three red LEDs
 */

const int redLED1PinNum = 2;
const int redLED2PinNum = 3;
const int redLED3PinNum = 4;
const int temperatureSensorPinNum = A0;

bool isCalibrated = false;
float baselineTemperature = 14.00;

/*
   Sets up all the pins for the love-o-meter
*/
void setup() {

  //Set up communication with the computers serial monitor
  Serial.begin(9600);

  //Set up the red LEDs pins for output and turn them off
  pinMode(redLED1PinNum, OUTPUT);
  digitalWrite(redLED1PinNum, LOW);

  pinMode(redLED2PinNum, OUTPUT);
  digitalWrite(redLED2PinNum, LOW);

  pinMode(redLED3PinNum, OUTPUT);
  digitalWrite(redLED3PinNum, LOW);

}

/*
   Continuous input loop for the love-o-meter
*/
void loop() {

  int sensorsValue = getTemperatureSensorsValue();
  float voltage = getTemperatureSensorsVoltage(sensorsValue);
  float temperature = getTemperatureSensorsTemperature(voltage);

  if (!isCalibrated) {
    baselineTemperature = temperature;
    isCalibrated = true;
  }

  printTemperatureSensorsDetails(sensorsValue, voltage, temperature);

  turnOnRedLEDs(temperature);

}

/*
    Gets the value from the temperature sensor
*/
int getTemperatureSensorsValue() {

  return analogRead(temperatureSensorPinNum);

}

/*
    Gets the voltage from the temperature sensor value
*/
float getTemperatureSensorsVoltage(int temperatureSensorsValue) {

  float voltage = (temperatureSensorsValue / 1024.0) * 5.0;

  return voltage;

}

/*
    Gets the temperature in celsius from the temperature sensors voltage
*/
float getTemperatureSensorsTemperature(float temperatureSensorsVoltage) {

  float temperature = (temperatureSensorsVoltage - 0.5) * 100.0;

  return temperature;

}

/*
   Convert celsius to fahrenheit
*/
float ConvertCelsiusToFahrenheit(float celsius) {

  float fahrenheit = (celsius * 1.8) + 36.0;

  return fahrenheit;

}

/*
   Print the temperature sensor value's details (i.e., sensor value, voltage, temperature in celsius)
   to the serial monitor
*/
void printTemperatureSensorsDetails(int sensorValue, float voltage, float temperature) {

  Serial.print("Baseline Temperature: ");
  Serial.print(baselineTemperature);

  Serial.print(", Sensor value: ");
  Serial.print(sensorValue);

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", Degrees Celsius: ");
  Serial.print(temperature);

  Serial.print(", Degrees Fahrenheit: ");
  Serial.println(ConvertCelsiusToFahrenheit(temperature));

}

/*
   Turns on the red LEDs when the specified temperature becomes greater than the baseline temperature
*/
void turnOnRedLEDs(float temperature) {

  digitalWrite(redLED1PinNum, LOW);
  digitalWrite(redLED2PinNum, LOW);
  digitalWrite(redLED3PinNum, LOW);

  if (temperature >= baselineTemperature + 1) {
    digitalWrite(redLED3PinNum, HIGH);
  }

  if (temperature >= baselineTemperature + 0.5) {
    digitalWrite(redLED2PinNum, HIGH);
  }

  if (temperature >= baselineTemperature) {
    digitalWrite(redLED1PinNum, HIGH);
  }

}

