/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

 Destructors
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 6) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <vector>
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
        std::cout << "*** Human object created ***" << std::endl;
    }

    ~Human() { std::cout << "*** Human object destroyed ***" << std::endl; }

    struct Hand
    {
        Hand(){std::cout << "*** Hand object created ***" << std::endl;}
        ~Hand(){std::cout << "*** Hand object destroyed ***" << std::endl;}

        bool isLeftHand = false;
        float fingerLength = 0.082f;        //2) in [m]
    };    
    
    bool isMale();
    void addSteps(int addedSteps);
    void goToSleep(bool isItTimeToSleep);
    
    Hand myLeftHand;
};

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
        std::cout << "*** Computer object created ***" << std::endl;
    }

    ~Computer() { std::cout << "*** Computer object destroyed ***" << std::endl; }

    struct App
    {
        bool isStandalone = true;
        float appSize = 300.0f; // in [MB]
    };
    
    void formatComputer(bool toFormat);
    
    App JUCE;
};

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
        std::cout << "*** Watch object created ***" << std::endl;
    }

    ~Watch() { std::cout << "*** Watch object destroyed ***" << std::endl; }

    struct Wristband
    {
        bool isLeather = true;
        Color color{0.5f,0.5f,0.0f,1.f};
    };
    
    void reset(bool toReset);
    void setAlarm(float timeAlarm);
    
    Wristband myPlasticWB;
}; 

void Watch::reset(bool toReset)
{
    toReset ? (isResetted = true) : (isResetted = false);
    std::cout << "Watch resetted" << std::endl;
}

void Watch::setAlarm(float timeAlarm)
{
    this->currentAlarmTime = timeAlarm;
}

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
}; 

void Table::cleanTable(bool toClean)
{
    toClean ? (isClean = true) : (isClean = false);
}

void Table::placeTablecloth(Table::Tablecloth myTablecloth)
{
    this->currentTablecloth = myTablecloth;
}


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
    
    ~Window() { std::cout << "*** Window object destroyed ***" << std::endl; }

    void print()
    {
        std::cout << 
        "Height: " << height << "\n" << 
        "Width: " << width << "\n" << 
        "Weight: " << weight << 
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

    Classroom() : numDesks(20)
    { 
        std::cout << "*** Classroom object created ***" << std::endl; 
    }

    ~Classroom() { std::cout << "*** Classroom object destroyed ***" << std::endl; }

    struct Desk
    {
        bool isWooden = true;
        float height = 1.5f; // in [m]
        float width = 2.0f; // in [m]
    };
    
    // Desk myDesk;

    void spawnDesk();
    int howManyFreeDesks();
}; 

void Classroom::spawnDesk()
{
    this->numDesks += 1;
}

int Classroom::howManyFreeDesks()
{
    return numDesks - occupiedDesks;
}


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
        std::cout << classrooms.size() << " classrooms" << std::endl;
        std::cout << windows.size() << " windows" << std::endl;
        std::cout << teacherTables.size() << " tables" << std::endl;
        std::cout << "School object created" << std::endl;
    }
    ~School()
    {
        std::cout << "School object destroyed" << std::endl;
    }
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
}; 

 
int main()
{
    // --------------------------------
    std::cout << "----------------------" << std::endl;  
    Human human1;
    std::cout << "----------------------\n" << std::endl;  
    // --------------------------------
    std::cout << "----------------------" << std::endl;  
    Computer computer1;
    std::cout << "----------------------\n" << std::endl;
    // --------------------------------
    std::cout << "----------------------" << std::endl;  
    Watch watch1;
    std::cout << "----------------------\n" << std::endl;
    
    
    // --------------------------------
    std::cout << "----------------------" << std::endl;  
    Geek geek(human1, watch1, computer1);
    std::cout << "----------------------\n" << std::endl;  
    // --------------------------------
    std::cout << "----------------------" << std::endl;  
    School school(10, 30, 10);
    std::cout << "----------------------\n" << std::endl;  
    
    // School school;
    std::cout << "good to go!\n" << std::endl;
    std::cout << "Now we get all the destructors of objects defined in main (in reverse order)\n" << std::endl;
}
