#include <Arduino.h>
#include <WiFiAdapter.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

WiFiAdapter::WiFiAdapter(){
    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
    WiFi.enableAP(false);
}

String WiFiAdapter::cm_getSsid(){
    return WiFi.SSID();
}

/**
* Versucht sich mit den zuletzt verwendeten Zugangsdaten an einem WLAN anzumelden
*/
void WiFiAdapter::cm_reconnect(){
    WiFi.enableSTA(true);
}

bool WiFiAdapter::cm_isConnected(){
    return WiFi.status() == WL_CONNECTED;
}

void WiFiAdapter::cm_stop(){
    WiFi.enableSTA(false);
}

void WiFiAdapter::apm_start(char *ssid, char *password, char *apIp){
    WiFi.softAPConfig(IPAddress(apIp[0], apIp[1], apIp[2], apIp[3]),
                      IPAddress(apIp[0], apIp[1], apIp[2], apIp[3]),
                      IPAddress(0xFF, 0xFF, 0xFF, 0x00));
    WiFi.softAP(ssid, password);
    WiFi.enableAP(true);
}
