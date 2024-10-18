#include "Nidec_24H_motor_control.h"

// Constructor to initialize motor control pins and PWM value
NidecMotor::NidecMotor(uint8_t brakePin, uint8_t pwmPin, uint8_t directionPin, uint16_t pwmValue) {
    _brakePin = brakePin;
    _pwmPin = pwmPin;
    _directionPin = directionPin;
    _pwmValue = pwmValue;
}

// Initialize the motor control pins and PWM frequency
void NidecMotor::begin() {
    // Set up PWM Phase and Frequency Correct on Timer1 (Pin 9 and Pin 10)
    TCCR1B = (1 << WGM13) | (1 << CS10);  // PWM Phase and Frequency Correct, no prescaling
    ICR1 = _pwmValue;                      // Set ICR1 for 20kHz frequency

    // Configure OC1A/OC1B on compare match
    TCCR1A = (1 << COM1A1) | (1 << COM1B1);

    // Set pin modes
    pinMode(_pwmPin, OUTPUT);
    pinMode(_brakePin, OUTPUT);
    pinMode(_directionPin, OUTPUT);
    digitalWrite(_brakePin, HIGH);
}

// Set the PWM value for speed control
void NidecMotor::setPWM(uint16_t dutyCycle) {
    OCR1A = dutyCycle;  // Set the PWM duty cycle
}

// Control the motor's speed and direction
void NidecMotor::motorControl(int pwm, Direction dir) {
    if (dir == STOP || pwm == 0) {
        // Apply brake when direction is STOP or PWM is 0
        digitalWrite(_brakePin, LOW);
    } else {
        // Release brake when motor should move
        digitalWrite(_brakePin, HIGH);

        // Set the motor direction
        if (dir == FORWARD) {
            digitalWrite(_directionPin, HIGH);
        } else if (dir == BACKWARD) {
            digitalWrite(_directionPin, LOW);
        }

        // Apply the PWM value to control speed
        pwm = constrain(pwm, 0, 255);
        setPWM(map(pwm, 0, 255, _pwmValue, 0));
    }
}