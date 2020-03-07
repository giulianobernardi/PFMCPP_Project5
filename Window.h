#pragma once
#include "LeakedObjectDetector.h"
#pragma once
#include "LeakedObjectDetector.h"

struct Window
{
    float height; // in [m]
    float width; // in [m]
    float weight; // in [kg]
    bool isClean;
    bool isOpen;
    bool isGlassOpaque;
    int structIntegrity;
    int currDamage;

    Window();
    Window(float height_, float width_, float weight_);
    ~Window();

    void print();

    struct Knob
    {
        bool isSteel = true;
        // Color color{0.5f,0.5f,0.5f,1.0f};
    };
    
    void cleanWindow(bool toClean);
    void openWindow(bool toOpen);
    void hammerWindow(int numBlows);
    
    Knob myKnob;

    // JUCE_LEAK_DETECTOR(Window)
}; 
