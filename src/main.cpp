#include <Arduino.h>

int pin1 = 10;
int pin2 = 11;
int pin3 = 5;
int pin4 = 6;
// int ENB = 6;
int speed = 255;

void setup()
{
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  // pinMode(IN2, OUTPUT);
  pinMode(pin2, OUTPUT); // pinMode(IN2, OUTPUT);

  // digitalWrite(IN2, LOW);

  //(Optional)
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  // Controlling speed (0 = off and 255 = max speed):
  //(Optional)
  // analogWrite(ENA, speed);
  // analogWrite(ENB, speed);
  //(Optional)
}
