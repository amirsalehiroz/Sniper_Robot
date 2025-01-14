#include <Servo.h>
#include "Sniper.h"

#define In1 3
#define In2 4
#define In3 5
#define In4 6
#define servo_pin 2
#define Ena 8
#define Enb 9

sniper sniper_robot(In1, In2, In3, In4, servo_pin, Ena, Enb);

String data = "";
char c;

void setup() {
	
	sniper_robot.begin();
	Serial.begin(9600);
}

void loop() {
	while (Serial.available() > 0)
	{
		c = Serial.read();
		data += c;
	}
	if (data.endsWith("w")) {
		sniper_robot.forward(255);
	}
	if (data.endsWith("s")) {
		sniper_robot.back(255);
	}
	if (data.endsWith("d")) {
		sniper_robot.right(0, 30);
	}
	if (data.endsWith("a")) {
		sniper_robot.left(0, 180);

	}
}
