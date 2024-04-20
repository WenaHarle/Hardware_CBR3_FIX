#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 1, 2, 3, 4);

void setup() {
 // set the speed at 60 rpm:
 myStepper1.setSpeed(60);
 // initialize the serial port:
 Serial.begin(9600);
}

void loop() {
 // step one revolution  in one direction:
 Serial.println("clockwise");
 myStepper.step(30);
 delay(500);

 // step one revolution in the other direction:
 Serial.println("counterclockwise");
 myStepper.step(30);
 delay(500);
}