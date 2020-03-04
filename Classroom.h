struct Classroom
{
    int numDesks;
    int occupiedDesks = 12;
    float height = 3.0f; // in [m]
    float width = 4.0f; // in [m]
    float length = 5.0f; // in [kg]
    bool isBooked = true;

    Classroom();
    ~Classroom();

    struct Desk
    {
        bool isWooden = true;
        float height = 1.5f; // in [m]
        float width = 2.0f; // in [m]
    };
    
    // Desk myDesk;

    void spawnDesk();
    int howManyFreeDesks();

    // JUCE_LEAK_DETECTOR(Classroom)
}; 
