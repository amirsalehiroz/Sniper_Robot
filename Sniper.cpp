#include "Sniper.h"
#include <Arduino.h>
#include <Servo.h>

Servo x_axis_servo;
Servo y_axis_servo;

sniper::sniper(int in1_pin_m1, int in2_pin_m1, int in3_pin_m2, int in4_pin_m2, int in1_pin_m3, int in2_pin_m3, int in3_pin_m4, int in4_pin_m4, int ena_m1, int enb_m2, int ena_m3, int enb_m4, int x_axis, int y_axis)
{
	// define pin varaible 
	_in1_pin_m1 = in1_pin_m1;
	_in2_pin_m1 = in2_pin_m1;
	_in3_pin_m2 = in3_pin_m2;
	_in4_pin_m2 = in4_pin_m2;
	_in1_pin_m3 = in1_pin_m3;
	_in2_pin_m3 = in2_pin_m3;
	_in3_pin_m4 = in3_pin_m4;
	_in4_pin_m4 = in4_pin_m4;
	_enam1 = ena_m1;
	_enbm2 = enb_m2;
	_enam3 = ena_m3;
	_enbm4 = enb_m4;
	_motor_speed = _motor_speed;
	_x_axis_speed = _x_axis_speed;
	_y_axis_speed = _y_axis_speed;
	_x_axis_degrees = _x_axis_degrees;
	_y_axis_degrees = _y_axis_degrees;
	_degrees = _degrees;
	_x_axis = x_axis;
	_y_axis = y_axis;
}

void sniper::begin()
{
	// define pin direction
	x_axis_servo.attach(_x_axis);
	y_axis_servo.attach(_y_axis);
	pinMode(_in1_pin_m1, OUTPUT);
	pinMode(_in2_pin_m1, OUTPUT);
	pinMode(_in3_pin_m2, OUTPUT);
	pinMode(_in4_pin_m2, OUTPUT);
	pinMode(_enam1, OUTPUT);
	pinMode(_enbm2, OUTPUT);
	pinMode(_x_axis, OUTPUT);
	pinMode(_y_axis, OUTPUT);

}

void sniper::left()
{
	// move left

}

void sniper::right()
{
	// move right

}

void sniper::forward(float _motor_speed)
{
	// move forward

}

void sniper::back(float _motor_speed)
{
	// move back

}

void sniper::stop_motors()
{
	// stop all motors
	digitalWrite(_in1_pin_m1, LOW);
	digitalWrite(_in2_pin_m1, LOW);
	digitalWrite(_in3_pin_m2, LOW);
	digitalWrite(_in4_pin_m2, LOW);

}

void sniper::x_axis(float x_axis_speed, float _x_axis_degrees)
{
	x_axis_servo.write(_x_axis_degrees);
	delay(x_axis_speed);
}

void sniper::y_axis(float y_axis_speed, float _y_axis_degrees)
{
	y_axis_servo.write(_y_axis_degrees);
	delay(y_axis_speed);
}
