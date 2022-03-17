#include "lib/SensorReader.h"
#include "lib/Wheel.h"

#define IN1 5
#define IN2 4
#define IN3 7
#define IN4 8

#define ENA 6
#define ENB 9

#define IN1 3
#define IN2 12
#define IN3 11
#define IN4 10

Wheel leftWheel(IN2, IN1, ENA);
Wheel rightWheel(IN4, IN3, ENB);

SensorReader sensorReader(IN1, IN2, IN3, IN4);

void setup() {
  Serial.begin(9600);
  Serial.println("Hello, World");

}

void loop() {
  Serial.println(sensorReader.readValue());
  delay(250);
}
