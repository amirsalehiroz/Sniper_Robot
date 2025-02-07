#ifndef Sniper
#define Sniper

class SniperRobot{
public:
	// public func
	SniperRobot();
	void begin();
	void StopMotors();
	void X_Axis(float angle);
	void Y_Axis(float angle);
  void laser(bool state);
  void SpringStepper(int distance);
  void shot();
private:
	// define private variable
  int a;
};


#endif