#include <Arduino.h>

typedef struct {
    char ssid[31];
    char password[31];
} configData;

class Configuration {
    public:
        Configuration();
        void reload();
        void save();
        char* getSsid();
        void setSsid(char* ssid);
        char* getPassword();
        void setPassword(char* password);
    private:
        const uint16_t eepromSize = 512;
        const uint8_t eepromAdress = 0;
        configData data;
};
