#include <iostream>
#include "Window.h"

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
