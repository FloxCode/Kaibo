#include <Arduino.h>
#include <Interval.h>

unsigned long prev = 0;
unsigned long interval = 0;

Interval::Interval(unsigned long milliseconds){
    interval = milliseconds;
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
    return millis() - prev > interval;
}
