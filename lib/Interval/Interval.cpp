#include <Arduino.h>
#include <Interval.h>

/*
* milliseconds: Länge des Intervals
* autoReset: Steuert, ob Interval automatisch neu startet, wenn over() true zurueck gibt
*/
Interval::Interval(unsigned long milliseconds, bool autoReset){
    interval = milliseconds;
    automaticReset = autoReset;
}

void Interval::setLength(unsigned long milliseconds){
    interval = milliseconds;
}

void Interval::reset(){
    prev=millis();
}

void Interval::start(){
    reset();
}

bool Interval::over(){
    if(millis() - prev > interval){
        if(automaticReset){
            reset();
        }
        return true;
    }
    return false;
}
