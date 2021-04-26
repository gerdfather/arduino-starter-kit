const int controlPin2 = 2;
const int controlPin3 = 3;
const int directionSwitchPin = 4;
const int onOffSwitchPin = 5;
const int enablePin = 9;

const int potPin = A0;

int onOffSwitchState = 0;
int prevOnOffSwitchState = 0;
int directionSwitchState = 0;
int prevDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 0;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchPin, INPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(controlPin3, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/16;

  if(onOffSwitchState != prevOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  if(directionSwitchState != prevDirectionSwitchState){
    if(directionSwitchState == HIGH){
      motorDirection = !motorDirection;
    }
  }

  if(motorDirection == 1){
    digitalWrite(controlPin2, HIGH);
    digitalWrite(controlPin3, LOW);
  } else {
    digitalWrite(controlPin2, LOW);
    digitalWrite(controlPin3, HIGH);  
  }

  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);  
  }

  prevDirectionSwitchState = directionSwitchState;
  prevOnOffSwitchState = onOffSwitchState;
}
