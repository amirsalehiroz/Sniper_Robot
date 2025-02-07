#ifndef SocketUdp
#define SocketUdp

class _SocketUdp_{
public:
  	_SocketUdp_();
	  void begin(char* ssid, char* password);
	  void TrasmitFeedback(char* message);
	  char* RecieveCommand();
	  void RetrunLog();

};
#endif