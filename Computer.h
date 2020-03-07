#pragma once
#include "LeakedObjectDetector.h"

struct Computer
{
    int numKeys;
    float processorSpeed; // in [GHz]
    bool isLaptop;
    bool isFormatted;
    int formatTime = 10;

    Computer();
    ~Computer();

    struct App
    {
        bool isStandalone = true;
        float appSize = 300.0f; // in [MB]
    };
    
    void formatComputer(bool toFormat);
    void printInfo();
    
    App JUCE;

    JUCE_LEAK_DETECTOR(Computer)
};
