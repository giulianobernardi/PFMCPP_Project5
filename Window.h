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

    Window(float height_, float width_, float weight_) //constructor
    {
        this->height = height_;
        this->width = width_;
        this->weight = weight_;
        isClean = true;
        isOpen = false;
        isGlassOpaque = true;
        structIntegrity = 10;
        currDamage = 0;
        print();
        std::cout << "*** Window object created ***" << std::endl;
    }
    
    ~Window() {}

    void print()
    {
        std::cout << 
        "Height: " << this->height << "\n" << 
        "Width: " << this->width << "\n" << 
        "Weight: " << this->weight << 
        std::endl;
    }

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
