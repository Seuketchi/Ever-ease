#include <Arduino.h>
#include <PID_v1.h>

// Constants
#define TEMP_PIN A0
#define ENA 5
#define IN1 4
#define IN2 7
#define ENB 9
#define IN3 8
#define IN4 2

// PID Parameters
double input = 0, output = 0, setpoint = 30;
double kp = 10.0, ki = 2.0, kd = 5.0;

// Smoothing Parameters
const int numSamples = 10;
float tempSamples[numSamples];
int sampleIndex = 0;

// PID Object
PID myPID(&input, &output, &setpoint, kp, ki, kd, REVERSE);

// Function Declarations
void setupMotors();
void controlMotors(double speed);
void setupTemperatureSensor();
float readSmoothedTemperature();
void initializePID();
void logData(double temperature, double speed, double error);

void setup()
{
  Serial.begin(115200);

  // Setup hardware and PID
  setupMotors();
  setupTemperatureSensor();
  initializePID();
}

void loop()
{
  // Read temperature
  input = readSmoothedTemperature();

  // Check for valid temperature range
  if (input < -40 || input > 125)
  {
    Serial.println("Error: Invalid temperature reading!");
    return;
  }

  // Compute PID output
  myPID.Compute();

  // Control motors with PID output
  controlMotors(output);

  // Log data for debugging
  logData(input, output, setpoint - input);

  delay(10);
}

// Function Definitions
void setupMotors()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void controlMotors(double speed)
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void setupTemperatureSensor()
{
  for (int i = 0; i < numSamples; i++)
  {
    tempSamples[i] = 0;
  }
}

float readSmoothedTemperature()
{
  int analogValue = analogRead(TEMP_PIN);
  float rawTemp = (analogValue * 5.0 / 1023.0) * 100.0;
  tempSamples[sampleIndex] = rawTemp;
  sampleIndex = (sampleIndex + 1) % numSamples;

  float sum = 0;
  for (int i = 0; i < numSamples; i++)
  {
    sum += tempSamples[i];
  }
  return sum / numSamples;
}

void initializePID()
{
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(30, 255);
  myPID.SetTunings(kp, ki, kd);
}

void logData(double temperature, double speed, double error)
{
  Serial.print(">temperature:");
  Serial.print(temperature);
  Serial.print(",setpoint:");
  Serial.print(setpoint);
  Serial.print(",speed:");
  Serial.print(speed);
  Serial.print(",error:");
  Serial.print(error);
  Serial.println();
}
