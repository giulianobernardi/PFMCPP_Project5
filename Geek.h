#pragma once
#include "LeakedObjectDetector.h"

struct Human;
struct Computer;
struct Watch;

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
