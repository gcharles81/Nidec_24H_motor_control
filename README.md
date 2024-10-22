Nidec_24H_motor_control
Introduction
The Nidec_24H_motor_control is an easy-to-use Arduino library designed for controlling Nidec 24H motors using PWM. It allows for seamless motor speed and direction control, with built-in functionality for braking and smooth operation at a high PWM frequency. This library abstracts the complexities of motor control, providing a user-friendly interface to set the motor’s speed, direction, and stop states.

With this library, you can easily control motor actions such as moving forward, backward, and stopping, using intuitive commands. It’s perfect for applications like robotics, automation, or any project that requires precise motor control.
Features
- Forward, Backward, Stop Control: Intuitive commands using FORWARD, BACKWARD, and STOP for motor movement.
- PWM Speed Control: Set motor speed using values from 0 to 255, mapped to a PWM signal operating in the range of 1,000Hz to 26,000Hz.
- Brake Control: Automatically applies the brake when the motor is stopped for quick halting.
- Smooth Soft Start: Implement gradual ramp-up of motor speed for both forward and backward directions.
Motor Speeds and Current Characteristics
Pulse Frequency (Hz)	Speed (RPM)	Current (mA)
1000	150	40
10000	1500	68
12000	1800	75
18000	2700	96
22000	3300	108
26000	3900	122
How It Works
This library provides simple methods to control the motor with minimal setup. Here's a quick overview of the main functions:

- begin(): Initializes the motor control pins and sets up the PWM frequency.
- setPWM(dutyCycle): Applies the specified PWM duty cycle to control the motor speed.
- motorControl(pwm, dir): Controls both the speed and direction of the motor. You can specify the speed using a PWM value (0-255) and direction with FORWARD, BACKWARD, or STOP.
- softStart(targetPWM, dir, rampTime): Gradually increases the motor speed from 0 to the specified target PWM value over a defined ramp time.
Pin Definitions
The library works with the following default pin configuration:
- BRAKE: Pin 8
- PWM: Pin 9
- DIRECTION: Pin 4

These can be adjusted as per your project’s needs when creating the NidecMotor object.
Example Code
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
1. Download the library from the repository or clone it:
   ```
   git clone https://github.com/gcharles81/Nidec_24H_motor_control.git
   ```

2. Copy the Nidec_24H_motor_control folder into your Arduino libraries folder (Documents/Arduino/libraries).

3. Restart the Arduino IDE, and you will be able to access the library from the Sketch > Include Library menu.
License
This library is licensed under the MIT License. Feel free to use and modify it for your projects.


