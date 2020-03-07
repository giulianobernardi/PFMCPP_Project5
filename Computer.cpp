#include <iostream>
#include "Computer.h"

Computer::Computer() : numKeys(48), isLaptop(true)// constructor
{
    processorSpeed = 4.2f; // in [GHz]
    isFormatted = false;
}

Computer::~Computer() {}

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
