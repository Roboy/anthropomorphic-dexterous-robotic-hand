# anthropomorphic-hand-prototype1
This repo contains design files for fusion 360 as well as a description how to set up the Arduino and the Adafruit motorboard for the hand (prototype1).

The documentation of the Prototype 1 can be found here: https://devanthro.atlassian.net/wiki/display/R2M/Anthropomorphic+hand+for+Roboy

![prototype1a](https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Documentation/images/for%20descriptions/prototype1a.jpg?raw=true)

## Hardware
For the prototype1 the following hardware is used:
```
- Robotic hand (3D printed)
- Genuino 101 (power supply via laptop)
- 2 Adafruit 16-Channel 12-bit PWM Servo Driver, 
- A power supply (5V, 10A) for the motorboards
- 25 servos (TowerPro, Micro Servo SG90).
```
# Building from source
The following instructions guide you through the process of building this repo from source.

## Install the Arduino Software

To program the Arduino board you need the Arduino environment.
Download Arduino: From the software page. (https://www.arduino.cc/en/Main/Software)

Linux note: For help getting the Arduino IDE running on Debian, please see the FAQ ("How can I run the Arduino IDE under Linux?").

Mac OS X note: After downloading the IDE, run the macosx_setup.command. It corrects permission on a few files for use with the serial port and will prompt you for your password. You may need to reboot after running this script.

## Connect the board

See also instruction here: https://www.arduino.cc/en/main/howto

If you're using a serial board, power the board with an external power supply (6 to 25 volts DC, with the core of the connector positive). Connect the board to a serial port on your computer.

On the USB boards, the power source is selected by the jumper between the USB and power plugs. To power the board from the USB port (good for controlling low power devices like LEDs), place the jumper on the two pins closest to the USB plug. To power the board from an external power supply (needed for motors and other high current devices), place the jumper on the two pins closest to the power plug. Either way, connect the board to a USB port on your computer. On Windows, the Add New Hardware wizard will open; tell it you want to specify the location to search for drivers and point to the folder containing the USB drivers you unzipped in the previous step.

The power LED should go on.
 
 ## Read more about the Arduino IDE

In case of troubleshooting
https://www.arduino.cc/en/Guide/Environment?from=Main.Environment

 
# Adafruit 16-Channel Servo Driver with Arduino
## Hooking it Up: Connecting the motorboard to the Arduino

Driving servo motors with the Arduino Servo library is pretty easy, but each one consumes a
precious pin - not to mention some Arduino processing power. The Adafruit 16-Channel 12-bit
PWM/Servo Driver will drive up to 16 servos over I2C with only 2 pins. The on-board PWM
controller will drive all 16 channels simultaneously with no additional Arduino processing
overhead. What's more, you can chain up to 62 of them to control up to 992 servos - all with the
same 2 pins!
The Adafruit PWM/Servo Driver is the perfect solution for any project that requires a lot of
servos.

The PWM/Servo Driver uses I2C so it take only 4 wires to connect to your Arduino:
```
### Genuino 101
+5v -> VCC (this is power for the BREAKOUT only, NOT the servo power!)
GND -> GND
SDA -> SDA
SCL -> SCL
### "Classic" Arduino wiring:
+5v -> VCC (this is power for the BREAKOUT only, NOT the servo power!)
GND -> GND
Analog 4 -> SDA
Analog 5 -> SCL
### Older Mega wiring:
+5v -> VCC (this is power for the BREAKOUT only, NOT the servo power!)
GND -> GND
Digital 20 -> SDA
Digital 21 -> SCL
### R3 and later Arduino wiring (Uno, Mega & Leonardo):
(These boards have dedicated SDA & SCL pins on the header nearest the USB connector)
+5v -> VCC (this is power for the BREAKOUT only, NOT the servo power!)
GND -> GND
SDA -> SDA
SCL -> SCL
```
The VCC pin is just power for the chip itself. If you want to connect servos or LEDs that use the
V+ pins, you MUST connect the V+ pin as well. The V+ pin can be as high as 6V even if VCC is
3.3V (the chip is 5V safe). We suggest connecting power through the blue terminal block since it
is polarity protected.


## Power for the Servos

Most servos are designed to run on about 5 or 6v. Keep in mind that a lot of servos moving at
the same time (particularly large powerful ones) will need a lot of current. Even micro servos
will draw several hundred mA when moving. Some High-torque servos will draw more than 1A
each under load.
Good power choices are:
5v 2A switching power supply (http://adafru.it/276)
5v 10A switching power supply (http://adafru.it/658)
4xAA Battery Holder (http://adafru.it/830) - 6v with Alkaline cells. 4.8v with NiMH
rechargeable cells.
4.8 or 6v Rechargeable RC battery packs from a hobby store.
It is not a good idea to use the Arduino 5v pin to power your servos. Electrical noise and
'brownouts' from excess current draw can cause your Arduino to act erratically, reset and/or
overheat.
We use the following power for 25 servos: 5A, 10A (https://www.amazon.de/gp/product/B00KETLBAU/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1)

## Connecting a Servo motor

We use the SG90 TowerPro Servos (http://www.micropik.com/PDF/SG90Servo.pdf).
Most servos come with a standard 3-pin female connector that will plug directly into the headers
on the Servo Driver. Be sure to align the plug with the ground wire (usually black or brown) with
the bottom row and the signal wire (usually yellow or white) on the top.

A single servo should be plugged into the PWM #0 port, the first port. You should see the servo
sweep back and forth over approximately 180 degrees. 

![connecting to Arduino_Uno](https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Documentation/images/for%20descriptions/connecting%20to%20Arduino_Uno.JPG?raw=true)

Up to 16 servos can be attached to one board.

![Adding more servos](https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Documentation/images/for%20descriptions/Adding%20more%20servos.JPG?raw=true)

## Chaining drivers
Multiple Drivers (up to 62) can be chained to control still more servos. With headers at both
ends of the board, the wiring is as simple as connecting a 6-pin parallel
cable (http://adafru.it/206) from one board to the next. In our case we use 2 motor boards for controlling 25 servo motors. 

![Chaining Drivers](https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Documentation/images/for%20descriptions/Chaining%20Drivers.JPG?raw=true)

# Using the Adafruit Library

Since the PWM Servo Driver is controlled over I2C, its super easy to use with any microcontroller or microcomputer. 

## Download the library from Github
```
Start by downloading the library from the GitHub repository (http://adafru.it/aQl) You can do that
by visiting the github repo and manually downloading or, easier, just click this button to
download the zip
Download Adafruit PWM/Servo Library
http://adafru.it/cDw
Rename the uncompressed folder Adafruit_PWMServoDriver and check that the
Adafruit_PWMServoDriver folder contains Adafruit_PWMServoDriver.cpp and
Adafruit_PWMServoDriver.h
Place the Adafruit_PWMServoDriver library folder your arduinosketchfolder/libraries/ folder.
You may need to create the libraries subfolder if its your first library. Restart the IDE.
There is also a great tutorial on how to install the library:
http://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use (http://adafru.it/aYM)
```
# Upload the Code
```
Upload the Code for the movement of the 5 Fingers: "first_prototype_5fingers.ino" to the Arduino. 
https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Programming/Prototype1/first_prototype_5fingers.ino
```
### Verify/Compile 
Checks your sketch for errors compiling it; it will report memory usage for code and variables in the console area.
### Upload 
Compiles and loads the binary file onto the configured board through the configured Port.


# Experimental setup
In the picture below you can see the experimental setup of the prototype 1. Further description of the experimental setup can be found on the following link: https://devanthro.atlassian.net/wiki/display/R2M/Anthropomorphic+hand+for+Roboy

![prototype1](https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Documentation/images/for%20descriptions/prototype1.jpg?raw=true)
