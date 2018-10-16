#include <Configuration.h>
#include <EEPROM.h>

Configuration::Configuration() {
    EEPROM.begin(eepromSize);
    EEPROM.get(eepromAdress, data);
    EEPROM.end();
}

void Configuration::reload() {
    EEPROM.begin(eepromSize);
    EEPROM.get(eepromAdress, data);
    EEPROM.end();
}

void Configuration::save() {
    EEPROM.begin(eepromSize);
    EEPROM.put(eepromAdress, data);
    EEPROM.commit();
    EEPROM.end();
}

char* Configuration::getSsid(){
    return data.ssid;
}

void Configuration::setSsid(char* ssid){
    strcpy(data.ssid, ssid);
}

char* Configuration::getPassword(){
    return data.password;
}

void Configuration::setPassword(char* password){
    strcpy(data.password, password);
}
