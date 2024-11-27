
#ifndef Sniper
#define Sniper

class sniper
{
public:
	// public func
	sniper(int in1_pin_m1, int in2_pin_m1, int in3_pin_m2, int in4_pin_m2,int in1_pin_m3,int in2_pin_m3,int in3_pin_m4,int in4_pin_m4, int ena_m1, int enb_m2,int ena_m3,int enb_m4, int x_axis, int y_axis);
	void begin();
	void left();
	void right();
	void forward(float motor_speed);
	void back(float motor_speed);
	void stop_motors();
	void x_axis(float x_axis_speed, float _x_axis_degrees);
	void y_axis(float y_axis_speed, float _y_axis_degrees);
	
private:
	// define private variable
	int _in1_pin_m1;
	int _in2_pin_m1;
	int _in3_pin_m2;
	int _in4_pin_m2;
	int _in1_pin_m3;
	int _in2_pin_m3;
	int _in3_pin_m4;
	int _in4_pin_m4;
	int _enam1;
	int _enbm2;
	int _enam3;
	int _enbm4;
	float _x_axis_degrees;
	float _y_axis_degrees;
	float _degrees;
	float _x_axis_speed;
	float _y_axis_speed;
	float _motor_speed;
	int _x_axis;
	int _y_axis;
};
#endif