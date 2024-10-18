#include <Arduino.h>
#include <Nidec_24H_motor_control.h>

// Define motor control pins
#define BRAKE_PIN 8
#define PWM_PIN 9
#define DIRECTION_PIN 4
#define PWMVALUE 400

// Create a motor object
NidecMotor motor(BRAKE_PIN, PWM_PIN, DIRECTION_PIN, PWMVALUE);

void setup() {
    Serial.begin(115200);

    // Initialize the motor control
    motor.begin();

    Serial.print("PWM: ");
    Serial.println(PWMVALUE);
    Serial.print("CPU_FREQ: ");
    Serial.println(F_CPU);

    delay(1000);
}

void loop() {
    // Test motor control: speed 200, forward direction
    motor.motorControl(200, NidecMotor::FORWARD);
    delay(2000);

    // Test motor control: speed 150, backward direction
    motor.motorControl(150, NidecMotor::BACKWARD);
    delay(2000);

    // Stop motor
    motor.motorControl(0, NidecMotor::STOP);
    delay(2000);
}