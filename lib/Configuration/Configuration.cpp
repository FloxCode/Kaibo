#include <Configuration.h>
#include <EEPROM.h>

Configuration::Configuration() {
    EEPROM.begin(eepromSize);
    EEPROM.get(eepromAdress, data);
}

void Configuration::save() {
    EEPROM.put(eepromAdress, data);
    EEPROM.commit();
    EEPROM.end();
}

char *Configuration::getSsid(){
    return data.ssid;
}

void Configuration::setSsid(char *ssid){
    data.ssid = ssid;
}

char *Configuration::getPassword(){
    return data.password;
}

void Configuration::setPassword(char *password){
    data.password = password;
}
