#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//600 is the 'maximum' pulse length count (out of 4096)
int pos1 = 600; // indexfinger 
int pos2 = 600; // middlefinger
int pos3 = 600; // ringfinger
int pos4 = 600; // pinky
int pos5 = 600; // thumb
int pos123 = 600; // for the movements flexion & stretch


////////////////////////////////////////////////////////
///////////////////    CONSTANTS    ///////////////////
////////////////////////////////////////////////////////
const int UNTERES_LIMIT = 170; // this value depends on the adjustment of the servos
const int OBERES_LIMIT = 580; // this value depends on the adjustment of the servos
const int SCHRITTWEITE = 10; // setting up the step size of the servos

// There are two different adresses for the two Adafruit motor boards: pwm & pwm2
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("movement of the roboy hand");
  pwm.begin();
  pwm2.begin();

  // Servos run at ~50 Hz updates
  pwm.setPWMFreq(50);  
  pwm2.setPWMFreq(50); 
  yield();
}

////////////////////////////////////////////////////////
//////////////////    FLEXION_ALL    ///////////////////
////////////////////////////////////////////////////////

void strecken_beugen_alle_gleichzeitig(){
  while( pos123 <= OBERES_LIMIT )
  {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, pos123);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, pos123);
    pwm.setPWM(13, 0, pos123);
    pwm.setPWM(14, 0, 600);
    
    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, pos123);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, pos123);
    pwm.setPWM(8, 0, pos123);
    pwm.setPWM(9, 0, 600);

    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, pos123);   
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, pos123);
    pwm.setPWM(3, 0, pos123);
    pwm.setPWM(4, 0, 600);

    // pinky motors: 5, 6, 7, 8, 9 (pwm2 board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm2.setPWM(5, 0, pos123);   
    pwm2.setPWM(6, 0, 600);  
    pwm2.setPWM(7, 0, pos123);
    pwm2.setPWM(8, 0, pos123);
    pwm2.setPWM(9, 0, 600);

    // thumb motors: 0, 1, 2, 3, 4 (pwm2 board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm2.setPWM(0, 0, pos123);   
    pwm2.setPWM(1, 0, 600);  
    pwm2.setPWM(2, 0, pos123);
    pwm2.setPWM(3, 0, pos123);
    pwm2.setPWM(4, 0, 600);
    
    Serial.println("Position beugen alle:");
    Serial.println(pos123);
                pos123+=SCHRITTWEITE; 
       }
}


void strecken_beugen_indexfinger(){

do
   {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, pos1);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, pos1);
    pwm.setPWM(13, 0, pos1);
    pwm.setPWM(14, 0, 600);
    Serial.println("Position beugen indexfinger:");
    Serial.println(pos1);
    pos1+=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos1 <= 580);
}

void strecken_beugen_middlefinger(){

do
   {
    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, pos2);   
    pwm.setPWM(6, 0, 600);   
    pwm.setPWM(7, 0, pos2);
    pwm.setPWM(8, 0, pos2);
    pwm.setPWM(9, 0, 600);
    Serial.println("Position beugen middlefinger:");
    Serial.println(pos2);
    pos2+=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos2 <= 580);
}


void strecken_beugen_ringfinger(){

do
   {
    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, pos3);   
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, pos3);
    pwm.setPWM(3, 0, pos3);
    pwm.setPWM(4, 0, 600);
    Serial.println("Position beugen ringfinger:");
    Serial.println(pos3);
    pos3+=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos3 <= 580);
}

void strecken_beugen_pinky(){

do
   {
    // pinky motors: 5, 6, 7, 8, 9 (pwm2 board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm2.setPWM(5, 0, pos4);   
    pwm2.setPWM(6, 0, 600);  
    pwm2.setPWM(7, 0, pos4);
    pwm2.setPWM(8, 0, pos4);
    pwm2.setPWM(9, 0, 600);
    Serial.println("Position beugen pinky:");
    Serial.println(pos4);
    pos4+=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos4 <= 580);
}

void strecken_beugen_thumb(){

do
   {
    // thumb motors: 0, 1, 2, 3, 4 (pwm2 board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm2.setPWM(0, 0, pos5);   
    pwm2.setPWM(1, 0, 600);  
    pwm2.setPWM(2, 0, pos5);
    pwm2.setPWM(3, 0, pos5);
    pwm2.setPWM(4, 0, 600);
    Serial.println("Position beugen thumb:");
    Serial.println(pos5);
    pos5+=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos5 <= 580);
}

////////////////////////////////////////////////////////
//////////////////    STRETCH_ALL    ///////////////////
////////////////////////////////////////////////////////

void beugen_strecken_alle_gleichzeitig(){
  while( pos123 >= UNTERES_LIMIT )
  {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, pos123);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, pos123);
    pwm.setPWM(13, 0, pos123);
    pwm.setPWM(14, 0, 600);

    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, pos123);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, pos123);
    pwm.setPWM(8, 0, pos123);
    pwm.setPWM(9, 0, 600);

    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, pos123);   // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, pos123);
    pwm.setPWM(3, 0, pos123);
    pwm.setPWM(4, 0, 600);

    // pinky motors: 5, 6, 7, 8, 9 (pwm2 board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm2.setPWM(5, 0, pos123);   
    pwm2.setPWM(6, 0, 600);  
    pwm2.setPWM(7, 0, pos123);
    pwm2.setPWM(8, 0, pos123);
    pwm2.setPWM(9, 0, 600);

    // thumb motors: 0, 1, 2, 3, 4 (pwm2 board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm2.setPWM(0, 0, pos123);   
    pwm2.setPWM(1, 0, 600);  
    pwm2.setPWM(2, 0, pos123);
    pwm2.setPWM(3, 0, pos123);
    pwm2.setPWM(4, 0, 600);

    
    Serial.println("Position beugen alle:");
    Serial.println(pos123);
                pos123-=SCHRITTWEITE; 
       }
}


void beugen_strecken_indexfinger(){

do
   {
     // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, pos1);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, pos1);
    pwm.setPWM(13, 0, pos1);
    pwm.setPWM(14, 0, 600);
    Serial.println("Position strecken indexfinger:");
    Serial.println(pos1);
    pos1-=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos1 >= 170);
} 

void beugen_strecken_middlefinger(){

do
   {
    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, pos2);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, pos2);
    pwm.setPWM(8, 0, pos2);
    pwm.setPWM(9, 0, 600);
    Serial.println("Position strecken middlefinger:");
    Serial.println(pos2);
    pos2-=20;
 
 
//    delay(0.5);
   } while (pos2 >= 170);
} 


void beugen_strecken_ringfinger(){

do
   {
    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, pos3);   
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, pos3);
    pwm.setPWM(3, 0, pos3);
    pwm.setPWM(4, 0, 600);
    Serial.println("Position strecken ringfinger:");
    Serial.println(pos3);
    pos3-=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos3 >= 170);
} 

void beugen_strecken_pinky(){

do
   {
    // pinky motors: 5, 6, 7, 8, 9 (pwm2 board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm2.setPWM(5, 0, pos4);   
    pwm2.setPWM(6, 0, 600);  
    pwm2.setPWM(7, 0, pos4);
    pwm2.setPWM(8, 0, pos4);
    pwm2.setPWM(9, 0, 600);
    Serial.println("Position strecken pinky:");
    Serial.println(pos4);
    pos4-=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos4 >= 170);
} 

void beugen_strecken_thumb(){

do
   {
    // thumb motors: 0, 1, 2, 3, 4 (pwm2 board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm2.setPWM(0, 0, pos5);   
    pwm2.setPWM(1, 0, 600);  
    pwm2.setPWM(2, 0, pos5);
    pwm2.setPWM(3, 0, pos5);
    pwm2.setPWM(4, 0, 600);
    Serial.println("Position strecken thumb:");
    Serial.println(pos5);
    pos5-=SCHRITTWEITE;
 
 
//    delay(0.5);
   } while (pos5 >= 170);
} 


void loop() {

beugen_strecken_alle_gleichzeitig(); // movement from flexion to stretch
delay(2000);
strecken_beugen_alle_gleichzeitig(); // movement from stretch to flexion
delay(2000);

// movement stretch, all fingers seperately
beugen_strecken_thumb();
beugen_strecken_indexfinger();
beugen_strecken_middlefinger();
beugen_strecken_ringfinger();
beugen_strecken_pinky();


delay(1000);
// movement flexion, all fingers seperately
strecken_beugen_thumb();
strecken_beugen_indexfinger();
strecken_beugen_middlefinger();
strecken_beugen_ringfinger();
strecken_beugen_pinky();

delay(1000);

}
