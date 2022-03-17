#ifndef SENSOR_READER_H
#define SENSOR_READER_H

class SensorReader {
 private:
  static const int SENSOR_READ_VALUE = HIGH;

  int leftMostPin, leftPin, rightPin, rightMostPin;

 public:
  SensorReader(int IN1, int IN2, int IN3, int IN4) {
    leftMostPin = IN4;
    leftPin = IN3;
    rightPin = IN2;
    rightMostPin = IN1;

    pinMode(IN1, INPUT);
    pinMode(IN2, INPUT);
    pinMode(IN3, INPUT);
    pinMode(IN4, INPUT);
  }

  int readValue() {
    // TODO: Test this function

    if (digitalRead(leftMostPin) == SENSOR_READ_VALUE) {
      if (digitalRead(leftPin) == SENSOR_READ_VALUE)
        return -2;
      else
        return -3;
    } else if (digitalRead(leftPin) == SENSOR_READ_VALUE) {
      if (digitalRead(rightPin) == SENSOR_READ_VALUE)
        return 0;
      else
        return -1;
    } else if (digitalRead(rightPin) == SENSOR_READ_VALUE) {
      if (digitalRead(rightMostPin) == SENSOR_READ_VALUE)
        return 2;
      else
        return 1;

    } else if (digitalRead(rightMostPin) == SENSOR_READ_VALUE)
      return 3;
    else
      return 0;   
  }

};


#endif