# GyroscopeControlledRobot
Speed control using Gyroscope
So speed control using gyroscope and using several factors including ultrasonic sensors 
The tilt angle from the MPU-6050 is mapped linearly to a target PWM duty cycle — leaning forward increases speed, level = stop. Three things can then reduce that value before it reaches the motor:

Obstacle braking — if the ultrasonic sensor reads under 30 cm, speed is capped; under 15 cm, the system stops entirely.
PID correction — the wheel encoder measures actual speed and nudges the PWM to close the error against the setpoint.
Battery factor — low voltage scales down the max speed to avoid stalling.

The final command is min(tilt_pwm, brake_limit, pid_output).
