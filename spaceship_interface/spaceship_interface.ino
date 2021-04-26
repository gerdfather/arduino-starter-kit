int switchState = 0;

void setup() {
  // Define which pins are input / output
  pinMode(2, INPUT);
  pinMode(3, OUTPUT); // Green LED
  pinMode(4, OUTPUT); // Red LED #1
  pinMode(5, OUTPUT); // Red LED #2
}

void loop() { // Loops runs thousands of times each second
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2); // check the chosen PIN vor Voltage

  if(switchState == LOW){
    digitalWrite(3, HIGH); // Turn Green LED on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH); // Turn Red LED #2 on

    delay(500); // Note: Arduino stops doing anything for the given period of time

    digitalWrite(4, HIGH); // Turn Red LED #1 on
    digitalWrite(5, LOW); 

    delay(500);
  }
}
