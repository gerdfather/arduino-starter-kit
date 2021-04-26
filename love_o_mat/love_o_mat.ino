const int sensorPin = A0;
const float baselineTemp = 26.0; // Reference temperature

void setup() {
  Serial.begin(9600); //open a serial port

  // Declare pins 2-4 as OUTPUT pins and initialize them as LOW
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // Read the values from the sensor at pin A0
  int sensorVal = analogRead(sensorPin);

  // Output sensor values to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // Convert measured sensor value to voltage and 
  // output the value on the Serial Monitor
  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts:  ");
  Serial.print(voltage);

  // Convert the voltage to temperature and 
  // output the value on the Serial MOnitor
  Serial.print(" , Degrees C°: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if(
      temperature < baselineTemp + 2
    ){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(
      temperature >= baselineTemp + 2 &&
      temperature < baselineTemp + 4
    ){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);    
  } else if(
      temperature >= baselineTemp + 4 &&
      temperature < baselineTemp + 6
    ){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);      
  } else if(
      temperature >= baselineTemp + 6
    ){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);     
  }
  delay(1);
}
