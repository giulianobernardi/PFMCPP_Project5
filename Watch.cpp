#include <iostream>
#include "Watch.h"

Watch::Watch() // constructor
{
    numBatteries = 1;
    totalHours = 12;
    weight = 50.0f; // in [g]
    isDigital = true;
    isResetted = true;
}

Watch::~Watch() {}

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
