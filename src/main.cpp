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
WiFiAdapter wifi;
Configuration conf;

// Intervalle
Interval connectionWaitTime(5000, false);
Interval messageInterval(4000, false);

// AP-Konstanten
char ap_ssid[] = "KAIBO-Setup";
char ap_password[] = "K418053tup";
char ap_ip[4] = {8, 2, 6, 6};

// Nachrichten
char message[80];
char t_connecting[] = "Verbinde mit:";
char t_NoConnection[] = "Keine Verbindung!";
char t_ssid[] = "WLAN:";
char t_password[] = "Passwort:";

void setup() {
    //Serial.begin(9600);
    display.init();
    display.showDate(0, 0, 0, 2000, 5, 1, 6, false, true, true);
    delay(3000);
    // TODO: Bootsequenz
    // Verbindung zu gespeichertem Netzwerk aufnehmen
    wifi.cm_reconnect();
    connectionWaitTime.start();
    strcpy(message, wifi.cm_getSsid().c_str());
    char *lines[80] = {t_connecting, message};
    messageInterval.start();
    display.showMessage(lines, 2);
    while(!(messageInterval.over() && wifi.cm_isConnected())){
        yield();
        if(connectionWaitTime.over()){
            break;
        }
    }

    // Wenn Verbindung zu gespeichertem Netzwerk nicht aufgebaut werden konnte in AP-Modus wechseln
    if(!wifi.cm_isConnected()){
        char *lines4[80] = {t_NoConnection};
        display.showMessage(lines4, 1);
        messageInterval.start();
        while(!messageInterval.over()){
            yield();
        }
        wifi.cm_stop();
        wifi.apm_start(ap_ssid, ap_password, ap_ip);
        char *lines2[80] = {t_ssid, ap_ssid, t_password, ap_password};
        display.showMessage(lines2, 4);
    }
    else{
        char *lines3[80] = {"Verbunden!"};
        display.showMessage(lines3, 1);
        messageInterval.start();
        while(!messageInterval.over()){
            yield();
        }
        display.clearDisplay();
    }
}

void loop() {
    // put your main code here, to run repeatedly:
}
