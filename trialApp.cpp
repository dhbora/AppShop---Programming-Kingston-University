#include "trialApp.h"
#include "user.h"
#include <iostream>

trialApp::trialApp(const int ID, const char *name, const char *desc, user *dev, short period)
:app(ID, name, desc, dev), trialPeriod(period)
{
}

void trialApp::displayData()
{
    std::cout << "Trial App ID = " << id << "\n\tapp name: " << appName << "\n\t" << description << "\n\tnumber of downloads: " << population << "\n\tdeveloped by: " << devel->getName() << "\n\ttrial period: " << trialPeriod << std::endl << std::endl;
}

double trialApp::getPrice()
{
    return 0.0;
}
