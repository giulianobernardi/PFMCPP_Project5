#include "Human.h"
#include "Watch.h"
#include "Computer.h"
#include "Geek.h"

Geek::Geek(){}
Geek::Geek(Human theGeek_, Watch theWatch_, Computer theComputer_) 
{
    theGeek = theGeek_;
    theWatch = theWatch_;
    theComputer = theComputer_;
    std::cout << "*** Geek object created ***" << std::endl;
}
Geek::~Geek()
{
    theGeek.goToSleep(true);
    theWatch.reset(true);
    theComputer.formatComputer(true);
    std::cout << "Geek object destroyed" << std::endl;
}
