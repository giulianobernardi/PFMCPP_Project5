/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some. 
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}



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
    int numHands_;
    float height_; // in [m]
    std::string chromosome_ = "XX";
    int totalSteps_ = 0;
    bool leftFootFront_ = true;

    Human() // constructor
    {
        numHands_ = 2;
        height_ = 1.68f; // in [m]
    }

    ~Human() {}

    struct Hand
    {
        bool isLeftHand_ = false;
        float fingerLength_ = 0.082f;        //2) in [m]
    };    
    
    bool isMale();
    void addSteps(int addedSteps);
    void goToSleep(bool isItTimeToSleep);
    void printInfo();
    
    Hand myLeftHand;
};

void Human::printInfo()
{
    std::cout << "Num hands: " << this->numHands_ << " hands\n" <<
    "Height: " << this->height_ << " m\n" <<
    "Chromosome: " << this->chromosome_ << "\n" <<
    "Total steps: " << this->totalSteps_ << " steps\n" << std::endl; 
}

bool Human::isMale()
{
    std::size_t found = this->chromosome_.find("Y");
    return (found!=std::string::npos ? true : false);
}

// Add a given number of steps and update front foot
void Human::addSteps(int addedSteps)
{
    for (int i = 0; i < addedSteps; i++)
    {
        this->totalSteps_ += 1;

        if ( i % 2 == 0 )
            this->leftFootFront_ = false;
        else
            this->leftFootFront_ = true;
    }

    std::cout << "Total steps: " << this->totalSteps_ << "\nCurrent foot in front: " << (leftFootFront_ == true ? "Left" : "Right") << " foot" << std::endl;
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
    int numKeys_;
    float processorSpeed_; // in [GHz]
    bool isLaptop_;
    bool isFormatted_;
    int formatTime_ = 10;

    Computer() : numKeys_(48), isLaptop_(true)// constructor
    {
        processorSpeed_ = 4.2f; // in [GHz]
        isFormatted_ = false;
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
};

void Computer::printInfo()
{
    std::cout <<
    "Num keys: " << this->numKeys_ << "\n" <<
    "Processor speed: " << this->processorSpeed_ << " GHz\n" <<
    "It is a laptop: " << this->isLaptop_ << "\n" <<
    "It is formatted: " << this->isFormatted_ << "\n" << 
    "Format time: " << this->formatTime_ << " s\n" << std::endl;
}

void Computer::formatComputer(bool toFormat)
{
    int i = 0;
    std::cout << "Formatting computer" << std::endl;

    while (i < this->formatTime_)
    {
        std::cout << "Current progress: " << ++i << "0%" << std::endl;
    }

    toFormat ? (isFormatted_ = true) : (isFormatted_ = false);
}

/* 
**********************************************************************
 copied UDT 3:
**********************************************************************
*/
struct Watch
{
    int numBatteries_;
    int totalHours_;
    float weight_; // in [g]
    bool isDigital_;
    bool isResetted_;
    float currentAlarmTime_;

    Watch() // constructor
    {
        numBatteries_ = 1;
        totalHours_ = 12;
        weight_ = 50.0f; // in [g]
        isDigital_ = true;
        isResetted_ = true;
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
}; 

void Watch::printInfo()
{
    std::cout << 
    "Num batteries: " << this->numBatteries_ << "\n" <<
    "Total hours: " << this->totalHours_ << " h\n" <<
    "Weight: " << this->weight_ << " g\n" <<
    "It is digital: " << this->isDigital_ << "\n" << 
    "It is resetted: " << this->isResetted_ << " \n" << std::endl; 
}

void Watch::reset(bool toReset)
{
    toReset ? (isResetted_ = true) : (isResetted_ = false);
    std::cout << "Watch resetted" << std::endl;
}

void Watch::setAlarm(float timeAlarm)
{
    this->currentAlarmTime_ = timeAlarm;
}

/* 
**********************************************************************
 copied UDT 4:
**********************************************************************
*/
struct Table
{
    int numLegs_;
    float height_; // in [m]
    float width_; // in [m]
    float weight_; // in [kg]
    bool isWooden_;
    bool isClean_;


    Table(int numLegs, float height, float width, float weight, bool isWooden, bool isClean) 
    {
        this->numLegs_ = numLegs;
        this->height_ = height; // in [m]
        this->width_ = width; // in [m]
        this->weight_ = weight; // in [kg]
        this->isWooden_ = isWooden;
        this->isClean_ = isClean;  
        print(); 
        std::cout << "*** Table object created ***" << std::endl;
    }

    ~Table() { std::cout << "*** Table object destroyed ***" << std::endl; }

    void print()
    {
        std::cout << 
        "Num legs: " << numLegs_ << "\n" << 
        "Height: " << height_ << "\n" << 
        "Width: " << width_ << "\n" << 
        "Weight: " << weight_ << 
        std::endl;
    }

    struct Tablecloth
    {
        bool isPlastic_ = true;
        float height_ = 1.5f; // in [m]
        float width_ = 1.0f; // in [m]
    };
    
    void cleanTable(bool toClean);
    void placeTablecloth(Tablecloth myTablecloth);
    
    Tablecloth currentTablecloth;
}; 

void Table::cleanTable(bool toClean)
{
    toClean ? (isClean_ = true) : (isClean_ = false);
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
    float height_; // in [m]
    float width_; // in [m]
    float weight_; // in [kg]
    bool isClean_;
    bool isOpen_;
    bool isGlassOpaque_;
    int structIntegrity_;
    int currDamage_;

    Window(float height, float width, float weight) //constructor
    {
        this->height_ = height;
        this->width_ = width;
        this->weight_ = weight;
        this->isClean_ = true;
        this->isOpen_ = false;
        this->isGlassOpaque_ = true;
        this->structIntegrity_ = 10;
        this->currDamage_ = 0;
        print();
        std::cout << "*** Window object created ***" << std::endl;
    }
    
    ~Window() {}

    void print()
    {
        std::cout << 
        "Height: " << this->height_ << "\n" << 
        "Width: " << this->width_ << "\n" << 
        "Weight: " << this->weight_ << 
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
    toClean ? (isClean_ = true) : (isClean_ = false);
}

void Window::openWindow(bool toOpen)
{
    toOpen ? (isOpen_ = true) : (isOpen_ = false);
}

// tests the structural integrity of the window upon a bunch of hammer blows
void Window::hammerWindow(int numBlows)
{
    for (int i = 0; i < numBlows; i++)
    {
        int blowStrength = rand() % 4 + 1;
        this->currDamage_ += blowStrength;

        if (this->currDamage_ >= this->structIntegrity_)
        {
            std::cout << "The window has been broken!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Current damage level: " << this->currDamage_ << "/10" << std::endl;
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
    int numClasses_;
    int numWindows_;
    int numTeacherTables_;
    std::vector<Classroom> classrooms;
    std::vector<Window> windows;
    std::vector<Table> teacherTables;

    School(int numClasses, int numWindows, int numTeacherTables) 
    {
        this->numClasses_ = numClasses;
        this->numWindows_ = numWindows;
        this->numTeacherTables_ = numTeacherTables;

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
}; 

/* 
**********************************************************************
 new UDT 2:
**********************************************************************
*/
struct Geek
{
    Human theGeek_;
    Watch theWatch_;
    Computer theComputer_;

    Geek(Human theGeek, Watch theWatch, Computer theComputer) 
    {
        theGeek_ = theGeek;
        theWatch_ = theWatch;
        theComputer_ = theComputer;
        std::cout << "*** Geek object created ***" << std::endl;
    }
    ~Geek()
    {
        theGeek_.goToSleep(true);
        theWatch_.reset(true);
        theComputer_.formatComputer(true);
        std::cout << "Geek object destroyed" << std::endl;
    }
}; 

 
int main()
{
    // --------------------------------
    Human human1;  
    // --------------------------------
    Computer computer1;
    // --------------------------------
    Watch watch1;
    // --------------------------------

    std::cout << "========================\n" << std::endl;

    // Access member variables of human directly
    std::cout << "Human object instance recap obtained accessing member variables directly:\n" << 
    "Num hands: " << human1.numHands_ << " hands\n" <<
    "Height: " << human1.height_ << " m\n" <<
    "Chromosome: " << human1.chromosome_ << "\n" <<
    "Total steps: " << human1.totalSteps_ << " steps\n" << std::endl; 
    // Access member variables of human through member function
    std::cout << "Human object instance recap obtained accessing member variables through member function:" << std::endl;
    human1.printInfo();

    std::cout << "========================\n" << std::endl;

    // Access member variables of computer1 directly
    std::cout << "Computer object instance recap obtained accessing member variables directly:\n" << 
    "Num keys: " << computer1.numKeys_ << "\n" <<
    "Processor speed: " << computer1.processorSpeed_ << " GHz\n" <<
    "It is a laptop: " << computer1.isLaptop_ << "\n" <<
    "It is formatted: " << computer1.isFormatted_ << "\n" << 
    "Format time: " << computer1.formatTime_ << " s\n" << std::endl; 
    // Access member variables of computer1 through member function
    std::cout << "Computer object instance recap obtained accessing member variables through member function:" << std::endl;
    computer1.printInfo();

    std::cout << "========================\n" << std::endl;

    // Access member variables of watch1 directly
    std::cout << "Watch object instance recap obtained accessing member variables directly:\n" << 
    "Num batteries: " << watch1.numBatteries_ << "\n" <<
    "Total hours: " << watch1.totalHours_ << " h\n" <<
    "Weight: " << watch1.weight_ << " g\n" <<
    "It is digital: " << watch1.isDigital_ << "\n" << 
    "It is resetted: " << watch1.isResetted_ << " \n" << std::endl; 
    // Access member variables of watch1 through member function
    std::cout << "Watch object instance recap obtained accessing member variables through member function:" << std::endl;
    watch1.printInfo();

    std::cout << "========================\n" << std::endl;   

    std::cout << "good to go!\n" << std::endl;
}
