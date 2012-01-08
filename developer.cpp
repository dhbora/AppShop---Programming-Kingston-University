#include "developer.h"
#include <iostream>

developer::developer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof)
:user(ID, fName, sName, adrs1, adrs2, pCode, pass, prof)
{
}

basket* developer::getBasket() throw (int)
{
    throw (1);		//developer doesn't have a basket
}

orderList* developer::getOrderList() throw (int)
{
    throw (1);		//developer doesn't have an order list
}

void developer::displayDetails()
{
	std::cout << "Developer ID = " << id << "\n\tName: " << firstName << " " << surname << "\n\tAddress: \t" << address1 << "\n\t\t\t" << address2 << "\n\t\t\t" << postcode << std::endl << std::endl;
}

float developer::getDiscount()
{
	return 0.0;
}

developer::~developer()
{
}
