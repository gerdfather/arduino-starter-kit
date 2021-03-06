const int redLEDPin = 11;
const int greenLEDPin = 9;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redLEDValue = 0;
int greenLEDValue = 0;
int blueLEDValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;  

void setup() {
  Serial.begin(9600);

  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  // Reading the value of each light sensor
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  
  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue);

  redLEDValue = redSensorValue / 4;
  greenLEDValue = greenSensorValue / 4;
  blueLEDValue = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redLEDValue);
  Serial.print("\t green: ");
  Serial.print(greenLEDValue);
  Serial.print("\t blue: ");
  Serial.println(blueLEDValue);
  
  analogWrite(redLEDPin, redLEDValue);
  analogWrite(greenLEDPin, greenLEDValue);
  analogWrite(blueLEDPin, blueLEDValue);
}
