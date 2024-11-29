#include <Arduino.h>
#include <PID_v1.h>

// Motor 1
int ENA = 5;
int IN1 = 7;
int IN2 = 8;

// Motor 2
int ENB = 3;
int IN3 = 4;
int IN4 = 2;

// Sensor
int tempSensorPin = A0;

// PID Parameters
double Kp = 0;
double Ki = 10;
double Kd = 0;

double setPoint = 0;
double speed = 0;
double Temperature = 0;

PID fanSpeed(&Temperature, &speed, &setPoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Serial.begin(9600);
  setPoint = 75;

  // Set motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize motors off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // Set ENA and ENB as PWM output
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  fanSpeed.SetMode(AUTOMATIC);
  fanSpeed.SetOutputLimits(0, 255);
  fanSpeed.SetTunings(Kp, Ki, Kd);
}

void loop()
{
  Temperature = analogRead(tempSensorPin) * (5.0 / 1023.0) * 100; // Convert to °C
  Serial.print("Temperature: ");
  Serial.println(Temperature);
  Serial.print("Speed: ");
  Serial.println(speed);

  // Compute PID
  fanSpeed.Compute();

  // Apply PID output to motors
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  // Set motors directions
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(100);
}
