/*
 * Simple demo, should work with any driver board
 *
 * Connect STEP, DIR as indicated
 *
 * Copyright (C)2015-2017 Laurentiu Badea
 *
 * This file may be redistributed under the terms of the MIT license.
 * A copy of this license has been included with this distribution in the file LICENSE.
 */
#include <Arduino.h>
#include "BasicStepperDriver.h"
//#include "ssd1306.h"

//Temperatuursensor
//#define SERIESRESISTOR 10000

//#define THERMISTORPIN A0
 
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 5000
 
// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 1
 
// All the wires needed for full functionality
//#define DIR 55
//#define STEP 54
//Uncomment line to use enable/disable functionality
//#define ENABLE 38
 
// 2-wire basic config, microstepping is hardwired on the driver
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);
 
//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, ENABLE);
//BasicStepperDriver stepper2(200, 61, 60, 56);

#define X_STEP_PIN    54
#define X_DIR_PIN     55
#define X_ENABLE_PIN  38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30

BasicStepperDriver stepperX(MOTOR_STEPS, X_DIR_PIN, X_STEP_PIN, X_ENABLE_PIN);
BasicStepperDriver stepperY(MOTOR_STEPS, Y_DIR_PIN, Y_STEP_PIN, Y_ENABLE_PIN); 
BasicStepperDriver stepperE(MOTOR_STEPS, E_DIR_PIN, E_STEP_PIN, E_ENABLE_PIN); 
BasicStepperDriver stepperE1(MOTOR_STEPS, E1_DIR_PIN, E1_STEP_PIN, E1_ENABLE_PIN); 

int solenoidPin = 9;
 
int rotations;
int s = 1;

int color = 1;
//proximity sensor
//float metalDetected;
//int monitoring;
//int metalDetection = 1;

int flag = 0;
int switchPin = 3;

void setup() {
    Serial.begin(9600);
    pinMode(switchPin, INPUT);
  
    //ssd1306_128x64_i2c_init();
    //ssd1306_fillScreen(0x00);
    //ssd1306_setFixedFont(ssd1306xled_font6x8);
 
    rotations = 0;
 
    //stepperX.begin(RPM, MICROSTEPS);
    //stepperY.begin(RPM, MICROSTEPS);
    //stepperE.begin(RPM, MICROSTEPS);
    //stepperE1.begin(RPM, MICROSTEPS);

    //pinMode(solenoidPin, OUTPUT);

    //Serial.begin(9600);
    
    
}
 
void loop() {
//float reading;

//reading = analogRead(THERMISTORPIN);

//Serial.print("Analog readin ");
//Serial.println(reading);
 // reading = (1023 / reading)  - 1;     // (1023/ADC - 1) 
 // reading = SERIESRESISTOR / reading;  // 10K / (1023/ADC - 1)
 // Serial.print("Thermistor resistance "); 
 // Serial.println(reading);
 // delay(1000);

// monitoring = analogRead(metalDetection);
// metalDetected = (float) monitoring*100/1024.0;
// Serial.print("bla: ");
// delay(500);
// Serial.print("initializing Proximity Sensor");
// delay(500);
// Serial.print("please wait...");
// delay(1000);
// Serial.print("Metal is proximited = ");
// Serial.print(metalDetected);
// Serial.print("%");
// if (monitoring > 250)
//  Serial.println("Metal is Detected");
// delay(1000);

    if(digitalRead(switchPin) == HIGH){
      Serial.println("yes");
      delay(1000);
    } 
    if(digitalRead(switchPin) == LOW){
      Serial.println("no");
      delay(1000);
    }

//    if( (digitalRead(switchPin) == LOW) && (flag == 0) ){
//      Serial.println("closed");
//      flag = 1;
//      delay(20);
//    }
//
//    if( (digitalRead(switchPin) == HIGH) && (flag == 1) ){
//      Serial.println("opened");
//      flag = 0;
//      delay(20);
//    }
 

 if (color == 1 && s < 2)
 {
    //vorkmotor
    //stepperE1.enable();
    //stepperE1.rotate(44000);
    
    //delay(3000);
    
    //magazijn groen
    //stepperY.enable();
    //stepperY.move(47700);
    //stepperY.move(-47700);
    //delay(3000);
    
    //stepperY.disable();
    //stepperE1.rotate(-44000);
    //stepperE1.disable();
    //delay(3000);

    
//    // energize coils - the motor will hold position
//    stepperX.enable();
//    
//    //stepper.rotate(-360);
//    //stepper.rotate(-90);
//
//    //penmotor
//    stepperX.move(2880 * 4);
//    stepperX.move(-2880 * 4);
// 
//    // pause and allow the motor to be moved by hand
//    stepperX.disable();
//
//    //magazijn 2
//    stepperY.enable();
//    stepperY.move(46000);
//    stepperY.move(-46000);
//    stepperY.disable();
//
//
//    //magazijn 1
//    stepperE.enable();
//    stepperE.move(46000);
//    stepperE.move(-46000);
//    stepperE.disable();

//    //vorkmotor
//    stepperE1.enable();
//    stepperE1.rotate(2880 * 4);
//    delay(1000);
//    stepperE1.rotate(-2880 * 4);
//    stepperE1.disable();

    //solenoid
//    digitalWrite(solenoidPin, HIGH); //aan
//    delay(1000);
//    digitalWrite(solenoidPin,LOW); //uit
     
    rotations++;
    //String toPrint = String(rotations);
    //ssd1306_printFixedN (0, 16, toPrint.c_str(), STYLE_BOLD, FONT_SIZE_4X);
    s++;
 }
    //delay(500);
}
