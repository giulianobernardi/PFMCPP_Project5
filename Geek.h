#pragma once
#include "LeakedObjectDetector.h"
// #include needed as I'm instantiating objects
#include "Human.h" 
#include "Computer.h"
#include "Watch.h"

struct Geek
{
    Human theGeek;
    Watch theWatch;
    Computer theComputer;

    Geek();
    Geek(Human theGeek_, Watch theWatch_, Computer theComputer_);
    ~Geek();

    JUCE_LEAK_DETECTOR(Geek)
};
