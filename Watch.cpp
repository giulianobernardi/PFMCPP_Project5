#include <iostream>
#include "Watch.h"

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
