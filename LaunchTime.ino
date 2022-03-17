#include <PID_v1.h>

#include "lib/SensorReader.h"
#include "lib/Wheel.h"

#define IN1 5
#define IN2 4
#define IN3 7
#define IN4 8

#define ENA 6
#define ENB 9

#define D1 3
#define D2 12
#define D3 11
#define D4 10

Wheel leftWheel(IN2, IN1, ENA);
Wheel rightWheel(IN4, IN3, ENB);

SensorReader sensorReader(D1, D2, D3, D4);

double sensorInput, sensorTarget;
double leftWheelSpeed, rightWheelSpeed;

int KpLeft = 10;
int KiLeft = 0;
int KdLeft = 0;

int KpRight = 10;
int KiRight = 0;
int KdRight = 0;

PID pidLeft(&sensorInput, &leftWheelSpeed, &sensorTarget, KpLeft, KiLeft, KdLeft, DIRECT);
PID pidRight(&sensorInput, &rightWheelSpeed, &sensorTarget, KpRight, KiRight, KdRight, REVERSE);

void setup() {
  Serial.begin(9600);
  Serial.println("Hello, World");

  pidLeft.SetOutputLimits(0, 255);
  pidRight.SetOutputLimits(0, 255);

  sensorTarget = 3;

  pidLeft.SetMode(AUTOMATIC);
  pidRight.SetMode(AUTOMATIC);
  
}

void loop() {
  sensorInput = sensorReader.readValue();

  // Serial.println(sensorInput);
  
  // pidLeft.Compute();
  // pidRight.Compute();

  // leftWheel.rotateForward(leftWheelSpeed);
  // rightWheel.rotateForward(rightWheelSpeed);

  delay(500);
}
