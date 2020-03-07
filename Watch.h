#pragma once
#include "LeakedObjectDetector.h"
#include "Color.h"

struct Watch
{
    int numBatteries;
    int totalHours;
    float weight; // in [g]
    bool isDigital;
    bool isResetted;
    float currentAlarmTime;

    Watch();
    ~Watch();

    struct Wristband
    {
        bool isLeather = true;
        Color color{0.5f,0.5f,0.0f,1.f};
    };
    
    void reset(bool toReset);
    void setAlarm(float timeAlarm);
    void printInfo();
    
    Wristband myPlasticWB;

    JUCE_LEAK_DETECTOR(Watch)
}; 
