#include <Arduino.h>
#include <ESP8266WiFi.h>

class WiFiAdapter{
    public:
        WiFiAdapter();
        String cm_getSsid();
        void cm_reconnect();
        void cm_connectTo(char *ssid, char *password);
        bool cm_isConnected();
        void cm_stop();
        void apm_start(char *ssid, char *password, char* apIp);
};
