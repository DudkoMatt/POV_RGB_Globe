#include "GyverButton_Fixed.h"  // Original library: GyverButton.h - changed name of AUTO parameter due to conflict with library GyverMotor.h
#include "GyverMotor.h"
GMotor motor(DRIVER2WIRE, 2, 3, HIGH);

#define BUTTON_1_PIN 8
#define BUTTON_2_PIN 9
GButton butt1(BUTTON_1_PIN);
GButton butt2(BUTTON_2_PIN);

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);

  motor.setSmoothSpeed(15);
  motor.setMode(FORWARD);
  motor.setMinDuty(150);
}

int val = -112;

void loop() {
  butt1.tick();
  butt2.tick();

  if (butt1.isClick() && val > -255)
    val -= 1;
  if (butt2.isClick() && val < 255)
    val += 1;
  
  
  // motor speed:
  // * (-255..255) in auto mode (use: setMode(FORWARD))
  Serial.flush();
    
  motor.smoothTick(val);
  Serial.print("Current speed: ");
  Serial.println(val);

  delay(10);
}
