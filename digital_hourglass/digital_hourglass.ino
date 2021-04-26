const int switchPin = 8;

unsigned long prevTime = 0;

int switchState = 0;
int prevSwitchState = 0;

// The LED that is turned on next
int led = 2;

// Time interval to transiution to next state is 5min
long interval = 1000;

void turnAllLEDsOff() {
  led = 2;
  for(int j = 2; j < 8; j++){
    digitalWrite(j, LOW); 
  }
  return;
}

void blinkLED(int ledToBlink) {
  for(int k = 0; k < 6; k++){
    digitalWrite(ledToBlink, HIGH);
    delay(500);
    digitalWrite(ledToBlink, LOW);
    delay(500);
  }
  return;
}

void setup() {
  // Declare Pins 2-7 as OUTPUT
  for(int i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }
  // Declare Pin of the switch as INPUT
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState){
    prevTime = currentTime;
    blinkLED(7);
    turnAllLEDsOff();
  }

  if(currentTime - prevTime > interval){
    prevTime = currentTime;

    if(led == 8){
      blinkLED(7);
      turnAllLEDsOff();
    } else {
      digitalWrite(led, HIGH);
      led++;
    }
  }

  switchState = 0;
  prevSwitchState = 0;
}
