#include <Arduino.h>

class WiFiAdapter{
    public:
        WiFiAdapter();
        void connectTo(char *ssid, char *password);
        bool isConnected();
        void startAccessPoint(char *ssid, char *password, char *apIp);
};
