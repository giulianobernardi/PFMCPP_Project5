/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


#include <iostream>
#include <vector>

#include "Human.h"
#include "Computer.h"
#include "Watch.h"
#include "Table.h"
#include "Window.h"
#include "Classroom.h"
#include "Window.h"

#include "School.h" 
#include "Geek.h"

#include "Wrappers.h"

// #include "Color.h"
 
int main()
{
    // --------------------------------
    HumanWrapper human1 (new Human());  
    // --------------------------------
    ComputerWrapper computer1 (new Computer());
    // --------------------------------
    WatchWrapper watch1 (new Watch());
    // --------------------------------
    TableWrapper table1 (new Table());
    // --------------------------------
    WindowWrapper window1 (new Window());
    // --------------------------------
    ClassroomWrapper classroom1 (new Classroom());   
    // --------------------------------
    GeekWrapper geek1 (new Geek());   
    // --------------------------------
    SchoolWrapper school1 (new School(3,2,1));   

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
        // human1.ptrToHuman->printInfo();
        human1.ptrToHuman->goToSleep(true);
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
