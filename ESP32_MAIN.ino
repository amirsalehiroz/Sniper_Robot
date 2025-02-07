#include <Arduino.h>
#include "Sniper.h"
#include "SocketUdp.h"

SniperRobot sniperRobot;

_SocketUdp_ socket;

void setup() {
  Serial.begin(115200);
  sniperRobot.begin();
  socket.begin("amir", "12345678");
  
}

void loop() {
  sniperRobot.SpringStepper(2000);
}