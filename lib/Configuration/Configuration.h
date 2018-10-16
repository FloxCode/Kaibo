#include <Arduino.h>

typedef struct {
    char *ssid;
    char *password;
} configData;

class Configuration {
    public:
        Configuration();
        void save();
        char *getSsid();
        void setSsid(char *ssid);
        char *getPassword();
        void setPassword(char *password);
    private:
        configData data;
        const uint16_t eepromSize = 512;
        const uint8_t eepromAdress = 0;
};
