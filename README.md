# CyberPong
CyberPong - Ping Pong Exersice Mashine

### About

This is the Ping Pong Exersice Machine that Uses 4 DC Motors and in order to shoot out ping pong balls at different angles.

What is used in the Project:

**PSOC 4200 BLE(CY8CKIT-042-BLE-A to be exact)**
- programed via _PSOC Creator_

**RoHS 18152522 R DC Motors**
- Each one has VCC and GND, and an encoder with VCC, GND and Output that tells the actual motor speed.
- 4 of them are used.
- Power supply is **12V** and max RPM is ~**4350** with that power.

**L298N Motor Driver**
![ded](./img/driver.png)
- 2.5 of them are used.
- 2 power the motors and the other half powers the serving motor.

**JGA25-370 DC Motow with a reducer**
![ded](./img/serve_motor.png)
- Responsible for serving the ball, can work with **5V** as well as **12V**
