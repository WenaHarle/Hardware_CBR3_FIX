/*
 * Complete project details at https://RandomNerdTutorials.com/esp32-load-cell-hx711/
 *
 * HX711 library for Arduino - example file
 * https://github.com/bogde/HX711
 *
 * MIT License
 * (c) 2018 Bogdan Necula
 *
**/
#include <Arduino.h>
#include "HX711.h"
#include "soc/rtc.h"
#include <Stepper.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 16;
const int LOADCELL_SCK_PIN = 4;
String grade;

HX711 scale;

//==============================Initiate Stepper==========================//
const int stepsPerRevolution = 360;  // change this to fit the number of steps per revolution

// initialize the stepper library on pins  3  through 11:
Stepper myStepper1(stepsPerRevolution, 13, 12, 14, 27);  //Hand kanan hitam
Stepper myStepper2(stepsPerRevolution, 26, 25, 33, 32); //hand kiri birumuda
Stepper myStepper3(stepsPerRevolution, 5, 18, 19, 21); //hand puter kuning

//================================Inpu Button=========================//
#define INPUT_PIN 2
int step_pos;


//==============================Milis==============================//
const unsigned long interval = 5000;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  rtc_cpu_freq_config_t config;
  rtc_clk_cpu_freq_get_config(&config);
  rtc_clk_cpu_freq_to_config(RTC_CPU_FREQ_80M, &config);
  rtc_clk_cpu_freq_set_config_fast(&config);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  scale.set_scale(-600);
  scale.tare();               // reset the scale to 0


  Serial.begin(115200);    
  pinMode(INPUT_PIN, INPUT); 


  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  myStepper3.setSpeed(200);
}

void loop() {
  unsigned long currentMillis = millis();
  int pinState = digitalRead(INPUT_PIN);
  Serial.print("Weight :\t");
  float berat =  scale.get_units(10);
  Serial.println(berat); 
  if (berat>50) {
      myStepper3.step(200);
      if (berat>150) {
        myStepper1.step(10);
        myStepper2.step(10);
        step_pos = 1;
        previousMillis = currentMillis;
        grade = "C";
      }
      if (berat>300) {
        myStepper1.step(-10);
        myStepper2.step(-10);
        step_pos = 2;
        previousMillis = currentMillis;
        grade = "A";
      }
      else{grade = "C";}
  }
  if (currentMillis - previousMillis >= interval) {
      // Save the current time as the last time the interrupt was triggered
      switch(step_pos){
        case 1:
        myStepper1.step(-10);
        myStepper2.step(-10);
        break;

        case 2:
        myStepper1.step(10);
        myStepper2.step(10);
        break;
      }


    }
  Serial.println(pinState);
  Serial.println(grade);
  scale.power_down();             // put the ADC in sleep mode
  delay(500);
  scale.power_up();
}