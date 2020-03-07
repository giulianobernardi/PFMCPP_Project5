#include <iostream>
#include "Human.h"

Human::Human() // constructor
{
    numHands = 2;
    height = 1.68f; // in [m]
}

Human::~Human() {}

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

void Human::printInfo()
{
    std::cout << "Num hands: " << this->numHands << " hands\n" <<
    "Height: " << this->height << " m\n" <<
    "Chromosome: " << this->chromosome << "\n" <<
    "Total steps: " << this->totalSteps << " steps\n" << std::endl; 
}
