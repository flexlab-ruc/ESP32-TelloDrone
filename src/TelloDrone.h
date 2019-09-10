#include <WiFi.h>
#include <WiFiUdp.h>
#include <string.h>

using namespace std;

class TelloDrone
{
    public:
        boolean connected;
        TelloDrone();
        string sendMessage(string message);
        void printWifiStatus(); 
        void connect(const char* ssid, const char* password);
        void sendCommand(string message);
        string getResponse();
        const char* networkName;
        const char* networkPswd;


    private:
        //const char * networkName = "tello2";
        //const char * networkPswd = "";'
        void WiFiEvent(WiFiEvent_t event, system_event_info_t info);
        WiFiUDP udp;
        const char * udpAddress = "192.168.10.1";
        const int udpPort = 8889;  
 
         
};