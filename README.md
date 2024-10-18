# Nidec_24H_motor_control
Introduction
The Nidec_24H_motor_control is an easy-to-use Arduino library designed for controlling Nidec 24H motors using PWM. It allows for seamless motor speed and direction control, with built-in functionality for braking and smooth operation at a 20kHz PWM frequency. This library abstracts the complexities of motor control, providing a user-friendly interface to set the motor’s speed, direction, and stop states.

With this library, you can easily control motor actions such as moving forward, backward, and stopping, using intuitive commands. It’s perfect for applications like robotics, automation, or any project that requires precise motor control.

Features
Forward, Backward, Stop Control: Intuitive commands using FORWARD, BACKWARD, and STOP for motor movement.
PWM Speed Control: Set motor speed using values from 0 to 255, mapped to a 20kHz PWM signal.
Brake Control: Automatically applies the brake when the motor is stopped for quick halting.
20kHz PWM Frequency: Operates at a high PWM frequency, making it suitable for noise-sensitive applications.
How It Works
This library provides simple methods to control the motor with minimal setup. Here's a quick overview of the main functions:

begin(): Initializes the motor control pins and sets up the PWM frequency (20kHz).
setPWM(dutyCycle): Applies the specified PWM duty cycle to control the motor speed.
motorControl(pwm, dir): Controls both the speed and direction of the motor. You can specify the speed using a PWM value (0-255) and direction with FORWARD, BACKWARD, or STOP.
Pin Definitions
The library works with the following default pin configuration:

BRAKE: Pin 8
PWM: Pin 9
DIRECTION: Pin 4
These can be adjusted as per your project’s needs when creating the NidecMotor object.

Example Code
Here’s a basic example of how to use the library:
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
}

void loop() {
    // Move the motor forward at half speed
    motor.motorControl(128, NidecMotor::FORWARD);
    delay(2000);

    // Move the motor backward at full speed
    motor.motorControl(255, NidecMotor::BACKWARD);
    delay(2000);

    // Stop the motor
    motor.motorControl(0, NidecMotor::STOP);
    delay(2000);
}

Installation
Download the library from the repository or clone it:
git clone https://github.com/gcharles81/Nidec_24H_motor_control.git

Copy the Nidec_24H_motor_control folder into your Arduino libraries folder (Documents/Arduino/libraries).

Restart the Arduino IDE and you will be able to access the library from the Sketch > Include Library menu.
License

This library is licensed under the MIT License, feel free to use and modify it for your projects.


