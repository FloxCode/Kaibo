#include <Arduino.h>
#include <CombinedDisplay.h>
#include <Interval.h>
#include <Configuration.h>
#include <WiFiAdapter.h>

#define SS_CLK D5
#define SS_DIO D6
#define OLED_CLK D1
#define OLED_DATA D2

CombinedDisplay display(OLED_CLK, OLED_DATA, SS_CLK, SS_DIO);
WiFiAdapter wifi();
Configuration conf();

Interval connectionWaitTime(20000, true);


void setup() {
    display.init();
    // TODO: Bootsequenz
    // Verbingung zu gespeichertem Netzwerk aufnehmen
    wifi.connectTo(conf.getSsid(), conf.getPassword());
    connectionTimeout.start();
    while(!wifi.isConnected() && !connectionWaitTime.over()){
        yield();
    }
    // Wenn Verbindung zu gespeichertem Netzwerk nicht aufgebaut werden konnte in AP-Modus wechseln
    if(!wifi.isConnected()){
        // TODO: AP-Modus + Konfiguration
    }
}

void loop() {
    // put your main code here, to run repeatedly:
}
