#include "SocketUdp.h"
#include <Arduino.h>
#include <WebServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  
char incomingPacket[255];

_SocketUdp_::_SocketUdp_(){

}

void _SocketUdp_::begin(char* ssid, char* password){
  int status = WL_IDLE_STATUS;
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to wifi");
  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}
void _SocketUdp_::TrasmitFeedback(char* message){

  const char* UDP_IP = "192.168.199.237" ;
  const int UDP_PORT = 4210;

  Udp.beginPacket(UDP_IP ,UDP_PORT);
  uint8_t buffer[50];
  strncpy((char*)buffer, message, sizeof(buffer) - 1);
  buffer[sizeof(buffer) - 1] = '\0'; 
  Udp.write(buffer, 11);
  Udp.endPacket();
}
char* _SocketUdp_::RecieveCommand(){
  bool readPacket = false;
  while (!readPacket) {
    int packetSize = Udp.parsePacket();
    if (packetSize)
     {
      // receive incoming UDP packets
      Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
      int len = Udp.read(incomingPacket, 255);
      if (len > 0)
      {
        incomingPacket[len] = 0;
      }
      Serial.printf(incomingPacket);
      return incomingPacket;
      readPacket = true;
    } 

  }
}

void _SocketUdp_::RetrunLog(){
  Serial.println("return log");
}