#include <Arduino.h>
#include <TM1637Display.h>
#include <U8g2lib.h>

enum Brightness{
           off,
           dark,
           brighter,
           bright
       };

class CombinedDisplay {
    public:
        CombinedDisplay(uint8_t oledClock, uint8_t oledData, uint8_t sevenSegClock, uint8_t sevenSegDIO);
        void init();
        void showDate(uint8_t hour, uint8_t min, uint8_t sec, uint16_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek,
                      bool showSeconds, bool showDate, bool showDayOfWeek);
        void setBrightness(Brightness b);
    private:
        TM1637Display sevenSegment;
        U8G2_SH1106_128X64_NONAME_F_HW_I2C oled;
        void printDate(uint8_t xpos, uint8_t ypos, uint16_t year, uint8_t month, uint8_t day);
};
