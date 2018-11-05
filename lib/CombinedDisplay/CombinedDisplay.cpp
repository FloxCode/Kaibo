#include <CombinedDisplay.h>
#include <TM1637Display.h>
#include <U8g2lib.h>

// 7 Segment Konstanten
const uint8_t clear[] = {0x00, 0x00, 0x00, 0x00};
// Oled Konstanten
const char dayNames[7][11] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

// Positionen
const uint8_t row0 = 15;
const uint8_t row1 = 30;
const uint8_t row2 = 45;
const uint8_t row3 = 60;
const uint8_t defX = 10;

CombinedDisplay::CombinedDisplay(uint8_t oledClock, uint8_t oledData,
                                 uint8_t sevenSegClock, uint8_t sevenSegDIO) :
                                 sevenSegment(sevenSegClock, sevenSegDIO),
                                 oled(U8G2_R0, U8X8_PIN_NONE, oledClock, oledData){

}

void CombinedDisplay::init(){
    sevenSegment.setSegments(clear);
    sevenSegment.setBrightness(0, true);
    oled.begin();
    oled.setFont(u8g2_font_ncenB08_tr);
    oled.setDrawColor(1); // TODO: Konstante verwenden
    oled.clearBuffer();
    oled.sendBuffer();
}

void CombinedDisplay::setBrightness(Brightness b){
    // TODO: Implementieren
}

bool showColumn = false;
void CombinedDisplay::showDate(uint8_t hour, uint8_t min, uint8_t sec,
                               uint16_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek,
                               bool showSeconds, bool showDate, bool showDayOfWeek)
{
    // Uhrzeit
    if(showSeconds){ // Doppelpunkt blinken lassen
        if(showColumn){
            sevenSegment.showNumberDecEx(hour, 0xFF, false, 2, 0);
        }
        else{
            sevenSegment.showNumberDecEx(hour, 0x00, false, 2, 0);
        }
        showColumn = !showColumn;
    }
    else{
        sevenSegment.showNumberDecEx(hour, 0xFF, false, 2, 0);
    }
    sevenSegment.showNumberDec(min, true, 2, 2);
    // Wochentag und Datum
    if(showDayOfWeek && showDate){
        oled.clearBuffer();
        oled.drawStr(defX, row2, dayNames[dayOfWeek]);
        printDate(defX, row3, year, month, day);
        oled.sendBuffer();
    }
    else if(showDate){
        oled.clearBuffer();
        printDate(defX, row3, year, month, day);
        oled.sendBuffer();
    }
    else if(showDayOfWeek){
        oled.clearBuffer();
        oled.drawStr(defX, row3, dayNames[dayOfWeek]);
        oled.sendBuffer();
    }
}

void CombinedDisplay::showMessage(char *lines[80], int lineCount){
    sevenSegment.setSegments(clear);
    oled.clearBuffer();
    if(lineCount >= 4){
        oled.drawStr(defX, row0, lines[0]);
        oled.drawStr(defX, row1, lines[1]);
        oled.drawStr(defX, row2, lines[2]);
        oled.drawStr(defX, row3, lines[3]);
    }
    else if(lineCount == 3){
        oled.drawStr(defX, row1, lines[0]);
        oled.drawStr(defX, row2, lines[1]);
        oled.drawStr(defX, row3, lines[2]);
    }
    else if(lineCount == 2){
        oled.drawStr(defX, row2, lines[0]);
        oled.drawStr(defX, row3, lines[1]);
    }
    else{
        oled.drawStr(defX, row3, lines[0]);
    }
    oled.sendBuffer();


}

void CombinedDisplay::clearDisplay(){
    sevenSegment.setSegments(clear);
    oled.clearBuffer();
    oled.sendBuffer();
}

void CombinedDisplay::printDate(uint8_t xpos, uint8_t ypos, uint16_t year, uint8_t month, uint8_t day){
    oled.setCursor(xpos, ypos);
    if(day<10){ // Tag ggf. auf zweistellig erweitern
        oled.print(0);
    }
    oled.print(day);
    oled.print(".");
    if(month<10){ // Monat ggf. auf zweistellig erweitern
        oled.print(0);
    }
    oled.print(month);
    oled.print(".");
    oled.print(year);
}
