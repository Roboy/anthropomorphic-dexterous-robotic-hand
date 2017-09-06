# anthropomorphic-hand
This repo contains design files for fusion 360 as well as a description how to set up the robotic hand (prototype1 & 2).

The human hand has a very delicate and complex structure. This allows muscles and joints in the hand a great range of movement and precision. The goal of this work is to build a tendon driven anthropomorphic robotic hand, which is able to closely mimic the human hand. Because of the inherent complexity of human hand, biomimetic anthropomorphic hand inevitably involves lots of compromises while maintaining a human-ish form factor. The hand for Roboy is designed based on the general idea of Roboy, whose limbs are all driven with motors using tendons. Due to the complexity of the human hand, lots of simplifications (like reducing the degree of freedom and integrated mechanical joints) are required.

## Current challenges & scope for the future work:
The prototype 1 was only a test prototype for Roboy and the prototype 2 is more compact with a better design in comparison to the prototype 1.
To make the robotic hand adaptable to the Roboy 2.0 hand-arm system, the following points were considered: 

        - The design have to look more human like. 
        - The new tendon routing have to support the precision of the fingers. 
        - Since the space for the motors is limited, the new robotic hand should have a reasonable degree of freedom. 
        - A Simulation of a mathematical model for the tendon driven hand have to be created.
        - Another servo motor (with more power) has to be selected in order to increase the gripping force of the hand. 
        - To control the wrist a sensor system is necessary (sensor angle measurement).

### Prototype 1
The prototype 1 was developed independently from Roboy to test the design of five tendon driven fingers with the servo system driven by 25 motors. 

#### Useful links
- The documentation of the Prototype 1 can be found here: https://devanthro.atlassian.net/wiki/display/R2M/Anthropomorphic+hand+for+Roboy
- The CAD files of the Prototype 1 can be found here: https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/tree/master/CAD/Prototype1
- The documentation of the coding can be found here: https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/tree/master/Programming/Prototype1


### Prototype 2
The second prototype was developed in order to adapt it into Roboy 2.0 (SS 2017). The second prototype has 20 servo motors which will be integrated in Roboy´s new arm (Documentation: https://devanthro.atlassian.net/wiki/display/R2M/Arms). The new design of Roboy´s hand will be more humanlike and an additional wrist was developed. The new tendon routing improved the precision in comparison to the old robotic hand. Furthermore, a sensor system on the wrist will be implemented.

#### Useful links
- The documentation of the Prototype 2 can be found here: https://devanthro.atlassian.net/wiki/display/R2M/Anthropomorphic+hand+for+Roboy
- The CAD files of the Prototype 2 can be found here: https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/tree/master/CAD/Prototype2
- The documentation of the coding can be found here: https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/tree/master/Programming/Prototype2

### Pictures of the prototype 1 & 2

#### Prototype 1
![prototype1a](https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Documentation/images/for%20descriptions/prototype1a.jpg?raw=true)

#### Prototype 2
![prototype2](https://github.com/Roboy/anthropomorphic-dexterous-robotic-hand/blob/master/Documentation/images/for%20descriptions/prototype2.jpg?raw=true)
