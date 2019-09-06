#include <TelloDrone.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <string.h>

        const char* networkName = "";
        const char* networkPswd = "";

        //The udp library class
        WiFiUDP udp;
        boolean connected;

        const char* udpAddress = "192.168.10.1";
        const int udpPort = 8889;

        TelloDrone::TelloDrone()
        {
        }

        void TelloDrone::connect(const char* ssid, const char* password)
        {
                this->networkName = ssid;
                this->networkPswd = password;
        
                // WiFi network name and password:
                
                IPAddress myIP(192,168,10,2);
                IPAddress gateway(192,168,10,1);
                IPAddress subnet(255,255,255,0);
                
                Serial.print("Connection to: ");
                Serial.println(networkName);
                
                WiFi.disconnect();

                
                WiFi.onEvent([this](WiFiEvent_t event, system_event_info_t info) {this->WiFiEvent(event, info); });


                WiFi.config(myIP,gateway,subnet);
                //Initiate connection
                WiFi.begin(networkName, networkPswd);

                Serial.println("Waiting for WIFI connection...");

        }

        //wifi event handler
        void TelloDrone::WiFiEvent(WiFiEvent_t event, system_event_info_t info){
                switch(event) {
                        case SYSTEM_EVENT_STA_GOT_IP:
                                //When connected set
                                Serial.print("WiFi connected! IP address: ");
                                Serial.println(WiFi.localIP());
                                //initializes the UDP state
                                //This initializes the transfer buffer
                                udp.begin(WiFi.localIP(),udpPort);
                                this->connected = true;
                                break;
                        case SYSTEM_EVENT_STA_DISCONNECTED:
                                Serial.println("WiFi lost connection");
                                //this->connected = false;
                                break;
                        case SYSTEM_EVENT_AP_STOP:
                                Serial.println("Lost connection to Drone");
                                this->connected = false;
                                break;
                        
                }
        }

        void TelloDrone::sendCommand(const char* message)  
        {
                String out = "Sending command '" + (String)message + "'";
                Serial.println(out);
                //Send a packet
                udp.beginPacket(udpAddress,udpPort);
                udp.printf(message);
                udp.endPacket();

                // read reply

                int packetSize = udp.parsePacket();
        
                if (packetSize)
                {        
                        char packetBuffer[255];
        
                        int len = udp.read(packetBuffer, 255);
                        if (len > 0) {
                                packetBuffer[len] = 0;
                        }
                        Serial.println(packetBuffer);
                        
                }
        }
        


