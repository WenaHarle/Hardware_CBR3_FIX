#include <HX711.h>

#include <Stepper.h>


const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
const unsigned long interval = 1000;  // Interval in milliseconds 
unsigned long previousMillis = 0;
int stepValue1 = 100;
int stepValueN1 = -100;
int stepValue2 = -50;
int stepValueN2 = 50;
// initialize the stepper library on pins  3  through 11:
Stepper myStepper1(stepsPerRevolution, 6, 5, 4, 3);
Stepper myStepper2(stepsPerRevolution, 8, 9, 10, 11);

String str_in;
int StepperActivate = 0;

void setup() {
 // set the speed at 60 rpm:
 myStepper1.setSpeed(200);
 myStepper2.setSpeed(200);
 // initialize the serial port:
 Serial.begin(9600);

}

void loop() {
 // step one revolution  in one direction:
   unsigned long currentMillis = millis();
   if (Serial.available() > 0 ) {
      
      str_in = Serial.readStringUntil('\n');
      str_in.trim();
        if (str_in.equals("A") && StepperActivate == 0 ) {
            Serial.println("Grade A");
            myStepper1.step(stepValue1);
            StepperActivate = 1;
            previousMillis = currentMillis;
          }

        if (str_in.equals("B") && StepperActivate == 0) {
            Serial.println("Grade B");
            myStepper2.step(stepValue2);
            StepperActivate = 2;
            previousMillis = currentMillis;
          }

}


        if (currentMillis - previousMillis >= interval) {

              previousMillis = currentMillis;
              resetStepper();
          }



}

void resetStepper() {

 switch (StepperActivate) {
        case 1:
          Serial.println("Reset back");
          myStepper1.step(stepValueN1);
          StepperActivate = 0;
          break;

        case 2:
          Serial.println("Reset back");
          myStepper2.step(stepValueN2);
          StepperActivate = 0;
          break;

        default:
          
          
          break;
        
 }

}