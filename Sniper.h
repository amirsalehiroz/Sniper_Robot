
#ifndef Sniper
#define Sniper

class sniper
{
public:
	sniper(int in1_pin, int in2_pin, int in3_pin, int in4_pin, int command_servo_pin, int ena, int enb, int x_axis, int y_axis);
	void begin();
	void left(float command_s_speed, int degrees);
	void right(float command_s_speed, int degrees);
	void forward(float motor_speed);
	void back(float motor_speed);
	void stop_motors();
	void x_axis(float x_axis_speed, float _x_axis_degrees);
	void y_axis(float y_axis_speed, float _y_axis_degrees);
	
private:
	int _in1_pin;
	int _in2_pin;
	int _in3_pin;
	int _in4_pin;
	int _command_servo_pin;
	int _ena;
	int _enb;
	float _x_axis_degrees;
	float _y_axis_degrees;
	float _degrees;
	float _x_axis_speed;
	float _y_axis_speed;
	float _command_s_speed;
	float _motor_speed;
	int _x_axis;
	int _y_axis;
};
#endif