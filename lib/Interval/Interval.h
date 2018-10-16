#include <Arduino.h>

class Interval {
    public:
        Interval(unsigned long milliseconds, bool autoReset);
        void setLength(unsigned long milliseconds);
        void reset();
        void start();
        bool over();
    private:
        unsigned long prev;
        unsigned long interval;
        bool automaticReset;
};
