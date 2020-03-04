#include "LeakedObjectDetector.h"

struct Table
{
    int numLegs;
    float height; // in [m]
    float width; // in [m]
    float weight; // in [kg]
    bool isWooden;
    bool isClean;

    Table();
    Table(int numLegs_, float height_, float width_, float weight_, bool isWooden_, bool isClean_);

    ~Table();

    void print();

    struct Tablecloth
    {
        bool isPlastic = true;
        float height = 1.5f; // in [m]
        float width = 1.0f; // in [m]
    };
    
    void cleanTable(bool toClean);
    void placeTablecloth(Tablecloth myTablecloth);
    
    Tablecloth currentTablecloth;

    JUCE_LEAK_DETECTOR(Table)
}; 
