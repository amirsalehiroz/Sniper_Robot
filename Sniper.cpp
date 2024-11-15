#include "Sniper.h"
#include <Arduino.h>
#include <Servo.h>

Servo s_servo;
Servo x_axis_servo;
Servo y_axis_servo;

sniper::sniper(int in1_pin, int in2_pin, int in3_pin, int in4_pin, int command_servo_pin, int ena, int enb , int x_axis, int y_axis)
{
	_in1_pin = in1_pin;
	_in2_pin = in2_pin;
	_in3_pin = in3_pin;
	_in4_pin = in4_pin;
	_command_servo_pin = command_servo_pin;
	_ena = ena;
	_enb = enb;
	_command_servo_pin = command_servo_pin;
	_command_s_speed = _command_s_speed;
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
	s_servo.attach(_command_servo_pin);
	x_axis_servo.attach(_x_axis);
	y_axis_servo.attach(_y_axis);
	pinMode(_in1_pin, OUTPUT);
	pinMode(_in2_pin, OUTPUT);
	pinMode(_in3_pin, OUTPUT);
	pinMode(_in4_pin, OUTPUT);
	pinMode(_ena, OUTPUT);
	pinMode(_enb, OUTPUT);
	pinMode(_x_axis, OUTPUT);
	pinMode(_y_axis, OUTPUT);

}

void sniper::left(float _command_s_speed, int degrees)
{
	s_servo.write(degrees);
	delay(_command_s_speed);
}

void sniper::right(float _command_s_speed, int degrees)
{
	s_servo.write(degrees);
	delay(_command_s_speed);
}

void sniper::forward(float _motor_speed)
{
	digitalWrite(_in1_pin, HIGH);
	digitalWrite(_in2_pin, LOW);
	digitalWrite(_in3_pin, HIGH);
	digitalWrite(_in4_pin, LOW);
	analogWrite(_ena, _motor_speed);
	analogWrite(_enb, _motor_speed);
}

void sniper::back(float _motor_speed)
{
	digitalWrite(_in1_pin, LOW);
	digitalWrite(_in2_pin, HIGH);
	digitalWrite(_in3_pin, LOW);
	digitalWrite(_in4_pin, HIGH);
	analogWrite(_ena, _motor_speed);
	analogWrite(_enb, _motor_speed);
}

void sniper::stop_motors()
{
	digitalWrite(_in1_pin, LOW);
	digitalWrite(_in2_pin, LOW);
	digitalWrite(_in3_pin, LOW);
	digitalWrite(_in4_pin, LOW);
	s_servo.write(0);
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
