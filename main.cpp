/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

#include <iostream>
#include <vector>
#include "LeakedObjectDetector.h"
// UDT storing rgba color
struct Color 
{
    Color (float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
    float r, g, b, a;
};
/* 
**********************************************************************
 copied UDT 1:
**********************************************************************
*/
struct Human
{
    int numHands;
    float height; // in [m]
    std::string chromosome = "XX";
    int totalSteps = 0;
    bool leftFootFront = true;

    Human() // constructor
    {
        numHands = 2;
        height = 1.68f; // in [m]
    }

    ~Human() {}

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

void Human::printInfo()
{
    std::cout << "Num hands: " << this->numHands << " hands\n" <<
    "Height: " << this->height << " m\n" <<
    "Chromosome: " << this->chromosome << "\n" <<
    "Total steps: " << this->totalSteps << " steps\n" << std::endl; 
}

bool Human::isMale()
{
    std::size_t found = this->chromosome.find("Y");
    return (found!=std::string::npos ? true : false);
}

// Add a given number of steps and update front foot
void Human::addSteps(int addedSteps)
{
    for (int i = 0; i < addedSteps; i++)
    {
        this->totalSteps += 1;

        if ( i % 2 == 0 )
            this->leftFootFront = false;
        else
            this->leftFootFront = true;
    }

    std::cout << "Total steps: " << this->totalSteps << "\nCurrent foot in front: " << (leftFootFront == true ? "Left" : "Right") << " foot" << std::endl;
}

void Human::goToSleep(bool isItTimeToSleep) 
{
    if (isItTimeToSleep)
        std::cout << "Person gone to sleep" << std::endl;
}

// Wrapper for UDT Human
struct HumanWrapper
{
    HumanWrapper ( Human* ptr ) : ptrToHuman( ptr ) {}
    ~HumanWrapper() { delete ptrToHuman; }
    Human* ptrToHuman = nullptr;
};

/* 
**********************************************************************
 copied UDT 2:
**********************************************************************
*/
struct Computer
{
    int numKeys;
    float processorSpeed; // in [GHz]
    bool isLaptop;
    bool isFormatted;
    int formatTime = 10;

    Computer() : numKeys(48), isLaptop(true)// constructor
    {
        processorSpeed = 4.2f; // in [GHz]
        isFormatted = false;
    }

    ~Computer() {}

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

void Computer::printInfo()
{
    std::cout <<
    "Num keys: " << this->numKeys << "\n" <<
    "Processor speed: " << this->processorSpeed << " GHz\n" <<
    "It is a laptop: " << this->isLaptop << "\n" <<
    "It is formatted: " << this->isFormatted << "\n" << 
    "Format time: " << this->formatTime << " s\n" << std::endl;
}

void Computer::formatComputer(bool toFormat)
{
    int i = 0;
    std::cout << "Formatting computer" << std::endl;

    while (i < this->formatTime)
    {
        std::cout << "Current progress: " << ++i << "0%" << std::endl;
    }

    toFormat ? (isFormatted = true) : (isFormatted = false);
}

// Wrapper for UDT Computer
struct ComputerWrapper
{
    ComputerWrapper ( Computer* ptr ) : ptrToComputer( ptr ) {}
    ~ComputerWrapper() { delete ptrToComputer; }
    Computer* ptrToComputer = nullptr;
};

/* 
**********************************************************************
 copied UDT 3:
**********************************************************************
*/
struct Watch
{
    int numBatteries;
    int totalHours;
    float weight; // in [g]
    bool isDigital;
    bool isResetted;
    float currentAlarmTime;

    Watch() // constructor
    {
        numBatteries = 1;
        totalHours = 12;
        weight = 50.0f; // in [g]
        isDigital = true;
        isResetted = true;
    }

    ~Watch() {}

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

void Watch::printInfo()
{
    std::cout << 
    "Num batteries: " << this->numBatteries << "\n" <<
    "Total hours: " << this->totalHours << " h\n" <<
    "Weight: " << this->weight << " g\n" <<
    "It is digital: " << this->isDigital << "\n" << 
    "It is resetted: " << this->isResetted << " \n" << std::endl; 
}

void Watch::reset(bool toReset)
{
    toReset ? (isResetted = true) : (isResetted = false);
    std::cout << "Watch resetted" << std::endl;
}

void Watch::setAlarm(float timeAlarm)
{
    this->currentAlarmTime = timeAlarm;
}

// Wrapper for UDT Watch
struct WatchWrapper
{
    WatchWrapper ( Watch* ptr ) : ptrToWatch( ptr ) {}
    ~WatchWrapper() { delete ptrToWatch; }
    Watch* ptrToWatch = nullptr;
};

/* 
**********************************************************************
 copied UDT 4:
**********************************************************************
*/
struct Table
{
    int numLegs;
    float height; // in [m]
    float width; // in [m]
    float weight; // in [kg]
    bool isWooden;
    bool isClean;


    Table(int numLegs_, float height_, float width_, float weight_, bool isWooden_, bool isClean_) 
    {
        numLegs = numLegs_;
        height = height_; // in [m]
        width = width_; // in [m]
        weight = weight_; // in [kg]
        isWooden = isWooden_;
        isClean = isClean_;  
        print(); 
        std::cout << "*** Table object created ***" << std::endl;
    }

    ~Table() { std::cout << "*** Table object destroyed ***" << std::endl; }

    void print()
    {
        std::cout << 
        "Num legs: " << numLegs << "\n" << 
        "Height: " << height << "\n" << 
        "Width: " << width << "\n" << 
        "Weight: " << weight << 
        std::endl;
    }

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

void Table::cleanTable(bool toClean)
{
    toClean ? (isClean = true) : (isClean = false);
}

void Table::placeTablecloth(Table::Tablecloth myTablecloth)
{
    this->currentTablecloth = myTablecloth;
}

// Wrapper for UDT Table
struct TableWrapper
{
    TableWrapper ( Table* ptr ) : ptrToTable( ptr ) {}
    ~TableWrapper() { delete ptrToTable; }
    Table* ptrToTable = nullptr;
};

/* 
**********************************************************************
 copied UDT 5:
**********************************************************************
*/
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
        Color color{0.5f,0.5f,0.5f,1.0f};
    };
    
    void cleanWindow(bool toClean);
    void openWindow(bool toOpen);
    void hammerWindow(int numBlows);
    
    Knob myKnob;

    // JUCE_LEAK_DETECTOR(Window)
}; 

void Window::cleanWindow(bool toClean)
{
    toClean ? (isClean = true) : (isClean = false);
}

void Window::openWindow(bool toOpen)
{
    toOpen ? (isOpen = true) : (isOpen = false);
}

// tests the structural integrity of the window upon a bunch of hammer blows
void Window::hammerWindow(int numBlows)
{
    for (int i = 0; i < numBlows; i++)
    {
        int blowStrength = rand() % 4 + 1;
        this->currDamage += blowStrength;

        if (this->currDamage >= this->structIntegrity)
        {
            std::cout << "The window has been broken!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Current damage level: " << this->currDamage << "/10" << std::endl;
        }
    }
}

// Wrapper for UDT Window
struct WindowWrapper
{
    WindowWrapper ( Window* ptr ) : ptrToWindow( ptr ) {}
    ~WindowWrapper() { delete ptrToWindow; }
    Window* ptrToWindow = nullptr;
};


/* 
**********************************************************************
 copied UDT 6:
**********************************************************************
*/
struct Classroom
{
    int numDesks;
    int occupiedDesks = 12;
    float height = 3.0f; // in [m]
    float width = 4.0f; // in [m]
    float length = 5.0f; // in [kg]
    bool isBooked = true;

    Classroom() : numDesks(20) {}

    ~Classroom() {}

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

void Classroom::spawnDesk()
{
    this->numDesks += 1;
}

int Classroom::howManyFreeDesks()
{
    return numDesks - occupiedDesks;
}

// Wrapper for UDT Classroom
struct ClassroomWrapper
{
    ClassroomWrapper ( Classroom* ptr ) : ptrToClassroom( ptr ) {}
    ~ClassroomWrapper() { delete ptrToClassroom; }
    Classroom* ptrToClassroom = nullptr;
};

/* 
**********************************************************************
 new UDT 1:
**********************************************************************
*/
struct School
{
    int numClasses;
    int numWindows;
    int numTeacherTables;
    std::vector<Classroom> classrooms;
    std::vector<Window> windows;
    std::vector<Table> teacherTables;

    School(int numClasses_, int numWindows_, int numTeacherTables_) 
    {
        numClasses = numClasses_;
        numWindows = numWindows_;
        numTeacherTables = numTeacherTables_;

        classrooms.reserve(numClasses);
        windows.reserve(numWindows);
        teacherTables.reserve(numTeacherTables);

        for (int i = 0; i < numClasses; i++)
        {
            this->classrooms.emplace_back();
        }

        for (int i = 0; i < numWindows; i++)
        {
            this->windows.emplace_back(1.2f, 1.6f, 12.f);
        }

        for (int i = 0; i < numTeacherTables; i++)
        {
            this->teacherTables.emplace_back(4, 1.6f, 1.2f, 10.f, true, true);
        }        

        std::cout << "School object created with" << std::endl;
        std::cout << this->classrooms.size() << " classrooms" << std::endl;
        std::cout << this->windows.size() << " windows" << std::endl;
        std::cout << this->teacherTables.size() << " tables" << std::endl;
        std::cout << "School object created" << std::endl;
    }
    ~School()
    {
        std::cout << "School object destroyed" << std::endl;
    }

    JUCE_LEAK_DETECTOR(School)
}; 

// Wrapper for UDT School
struct SchoolWrapper
{
    SchoolWrapper ( School* ptr ) : ptrToSchool( ptr ) {}
    ~SchoolWrapper() { delete ptrToSchool; }
    School* ptrToSchool = nullptr;
};

/* 
**********************************************************************
 new UDT 2:
**********************************************************************
*/
struct Geek
{
    Human theGeek;
    Watch theWatch;
    Computer theComputer;

    Geek(Human theGeek_, Watch theWatch_, Computer theComputer_) 
    {
        theGeek = theGeek_;
        theWatch = theWatch_;
        theComputer = theComputer_;
        std::cout << "*** Geek object created ***" << std::endl;
    }
    ~Geek()
    {
        theGeek.goToSleep(true);
        theWatch.reset(true);
        theComputer.formatComputer(true);
        std::cout << "Geek object destroyed" << std::endl;
    }

    JUCE_LEAK_DETECTOR(Geek)
}; 

// Wrapper for UDT Geek
struct GeekWrapper
{
    GeekWrapper ( Geek* ptr ) : ptrToGeek( ptr ) {}
    ~GeekWrapper() { delete ptrToGeek; }
    Geek* ptrToGeek = nullptr;
};

 
int main()
{
    // --------------------------------
    HumanWrapper human1 (new Human());  
    // --------------------------------
    ComputerWrapper computer1 (new Computer());
    // --------------------------------
    WatchWrapper watch1 (new Watch());
    // --------------------------------

    std::cout << "========================\n" << std::endl;

    // Access member variables of human directly
    std::cout << "Human object instance recap obtained accessing member variables directly:" << std::endl;
    if (human1.ptrToHuman != nullptr)
    {
        std::cout << 
        "Num hands: " << human1.ptrToHuman->numHands << " hands\n" <<
        "Height: " << human1.ptrToHuman->height << " m\n" <<
        "Chromosome: " << human1.ptrToHuman->chromosome << "\n" <<
        "Total steps: " << human1.ptrToHuman->totalSteps << " steps\n" << std::endl; 
        // Access member variables of human through member function
        std::cout << "Human object instance recap obtained accessing member variables through member function:" << std::endl;
        human1.ptrToHuman->printInfo();
    }
    std::cout << "========================\n" << std::endl;

    // Access member variables of computer1 directly
    std::cout << "Computer object instance recap obtained accessing member variables directly:" << std::endl;
    if (computer1.ptrToComputer != nullptr)
    {
        std::cout << 
        "Num keys: " << computer1.ptrToComputer->numKeys << "\n" <<
        "Processor speed: " << computer1.ptrToComputer->processorSpeed << " GHz\n" <<
        "It is a laptop: " << computer1.ptrToComputer->isLaptop << "\n" <<
        "It is formatted: " << computer1.ptrToComputer->isFormatted << "\n" << 
        "Format time: " << computer1.ptrToComputer->formatTime << " s\n" << std::endl; 
        // Access member variables of computer1 through member function
        std::cout << "Computer object instance recap obtained accessing member variables through member function:" << std::endl;
        computer1.ptrToComputer->printInfo();
    }
    std::cout << "========================\n" << std::endl;

    // Access member variables of watch1 directly
    std::cout << "Watch object instance recap obtained accessing member variables directly:" << std::endl;
    if (watch1.ptrToWatch != nullptr)
    {
        std::cout << 
        "Num batteries: " << watch1.ptrToWatch->numBatteries << "\n" <<
        "Total hours: " << watch1.ptrToWatch->totalHours << " h\n" <<
        "Weight: " << watch1.ptrToWatch->weight << " g\n" <<
        "It is digital: " << watch1.ptrToWatch->isDigital << "\n" << 
        "It is resetted: " << watch1.ptrToWatch->isResetted << " \n" << std::endl; 
        // Access member variables of watch1 through member function
        std::cout << "Watch object instance recap obtained accessing member variables through member function:" << std::endl;
        watch1.ptrToWatch->printInfo();
    }
    std::cout << "========================\n" << std::endl;   

    std::cout << "good to go!\n" << std::endl;
}
