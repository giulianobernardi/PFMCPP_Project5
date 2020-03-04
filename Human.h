#pragma once
#include "LeakedObjectDetector.h"

struct Human
{
    int numHands;
    float height; // in [m]
    std::string chromosome {"XX"};
    int totalSteps {0};
    bool leftFootFront {true};

    Human();
    ~Human();

    struct Hand
    {
        bool isLeftHand = false;
        float fingerLength = 0.082f;        //2) in [m]
    };    
    
    bool isMale();
    void addSteps(int addedSteps);
    void goToSleep(bool isItTimeToSleep);
    void printInfo();
    
    Hand myLeftHand;
    
    JUCE_LEAK_DETECTOR(Human)
};
