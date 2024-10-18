#ifndef NIDEC_24H_MOTOR_CONTROL_H
#define NIDEC_24H_MOTOR_CONTROL_H

#include <Arduino.h>

class NidecMotor {
public:
    // Direction constants
    enum Direction {
        FORWARD = 1,
        BACKWARD = 2,
        STOP = 0
    };

    // Constructor
    NidecMotor(uint8_t brakePin, uint8_t pwmPin, uint8_t directionPin, uint16_t pwmValue);

    // Methods
    void begin();
    void setPWM(uint16_t dutyCycle);
    void motorControl(int pwm, Direction dir); // Use Direction enum here

private:
    uint8_t _brakePin;
    uint8_t _pwmPin;
    uint8_t _directionPin;
    uint16_t _pwmValue;
};

#endif