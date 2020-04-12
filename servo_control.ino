#include <Servo.h>

Servo left_ear;
Servo right_ear;

int BUTTON = 9;
const int HAPPY_LIGHT = 7;
const int SAD_LIGHT = 6;
const int SAD = 1;
const int HAPPY = 2;

int button_state;

void setup() {
  Serial.begin(9600);
  left_ear.attach(12);
  right_ear.attach(11);
  left_ear.write(0);
  right_ear.write(170);
  pinMode(BUTTON, INPUT);
  pinMode(HAPPY_LIGHT, OUTPUT);
  button_state = 1;
  
}

void loop() {
  Serial.println(button_state);
  if (digitalRead(BUTTON) == HIGH) {
    button_state++;
    if (button_state > 2) {
      button_state = 1;
    }
    delay(1000);
  }

  if (button_state == HAPPY) {
    left_ear.write(45);
    right_ear.write(135);
    digitalWrite(HAPPY_LIGHT, HIGH);
    digitalWrite(SAD_LIGHT, LOW);
  }
  else if (button_state == SAD) {
    left_ear.write(0);
    right_ear.write(170);
    digitalWrite(HAPPY_LIGHT, LOW);
    digitalWrite(SAD_LIGHT, HIGH);
  }
}
