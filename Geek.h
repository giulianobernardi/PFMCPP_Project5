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
