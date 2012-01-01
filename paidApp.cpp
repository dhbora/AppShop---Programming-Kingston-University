#include "paidApp.h"
#include "user.h"
#include <iostream>

paidApp::paidApp(const int ID, const char *name, const char *desc, user *dev, const double prc)
:app(ID, name, desc, dev), price(prc)
{
}

void paidApp::displayData()
{
    std::cout << "Paid App ID = " << id << "\n\tapp name: " << appName << "\n\t" << description << "\n\tnumber of downloads: " << popularity << "\n\tdeveloped by: " << devel->getName() << "\n\tprice: " << price << std::endl << std::endl;
}

double paidApp::getPrice()
{
    return price;
}

paidApp::~paidApp()
{
}
