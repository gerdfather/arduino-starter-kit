#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Stelle Mentalo");
  lcd.setCursor(0, 1);
  lcd.print("deine Frage!");
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Das Orakel sagt:");
      lcd.setCursor(0, 1);

      switch(reply){
        case 0:
          lcd.print("Mach weiter!");
          break;
        case 1:
          lcd.print("Ja!");
          break;
        case 2:
          lcd.print("Nein!");
          break;
        case 3:
          lcd.print("Kannste knicken!");
          break;
        case 4:
          lcd.print("Wer weiss?!");
          break;
        case 5:
          lcd.print("Gerade so!");
          break;
        case 6:
          lcd.print("!");
          break;
        case 7:
          lcd.print("Viel Glueck!");
          break;
      }
    }
  }
  prevSwitchState = switchState;
}
