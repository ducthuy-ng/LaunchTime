#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
 private:
  int forwardPin, backwardPin, speedPin;

 public:
  Wheel(int IN1, int IN2, int ENA) {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);

    forwardPin = IN1;
    backwardPin = IN2;
    speedPin = ENA;
  }

  void rotateForward(int speed) {
    Serial.println("forward");
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);

    analogWrite(speedPin, speed);
  }

  void rotateBackward(int speed) {
    Serial.println("backward");
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);

    analogWrite(speedPin, speed);
  }

  void stop() {
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);

    analogWrite(speedPin, 0);
  }
};

#endif
