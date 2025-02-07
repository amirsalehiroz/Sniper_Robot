#include "Sniper.h"
#include <Arduino.h>
#include <ESP32Servo.h>

#define x_axis 18
#define y_axis 19
#define Dir 33
#define Step 32
#define Enable 25 
#define Laser 14
#define shotservopin 17

Servo x_axis_servo;
Servo y_axis_servo;
Servo shot_servo;

SniperRobot::SniperRobot(){
	// define pin varaible 
  int a;

}

void SniperRobot::begin(){
	// define pin direction
	x_axis_servo.attach(x_axis);
	y_axis_servo.attach(y_axis);
  shot_servo.attach()
	shot_servo.attach(shotservopin);
  pinMode(Dir, OUTPUT);
  pinMode(Step, OUTPUT);
  pinMode(Enable, OUTPUT);
  pinMode(Laser, OUTPUT);
}

void SniperRobot::StopMotors(){
	// stop all motors
  x_axis_servo.write(0);
  y_axis_servo.write(0);
  digitalWrite(Step, LOW);
}

void SniperRobot::X_Axis(float angle){
	x_axis_servo.write(angle);
}

void SniperRobot::Y_Axis(float angle){
	y_axis_servo.write(angle);
}

void SniperRobot::SpringStepper(int distance){

  for (int i=0;i<distance;i++){
    digitalWrite(Step, HIGH);
    delayMicroseconds(800);
    digitalWrite(Step, LOW);
    delayMicroseconds(800);
  }

}
void SniperRobot::laser(bool state){
  if (state == true){
    digitalWrite(Laser , HIGH);
  }
  else{
    digitalWrite(Laser, LOW);
  }
  
}
void SniperRobot::shot(){
  shot_servo.write(90);
  delay(2000);
  shot_servo.write(0);
}
