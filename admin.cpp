#include "admin.h"
#include <iostream>

admin::admin(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof)
:user(ID, fName, sName, adrs1, adrs2, pCode, pass, prof)
{

}

basket* admin::getBasket() throw(int)
{
    throw (1);		//admin doesn't have a basket
}

orderList* admin::getOrderList() throw (int)
{
    throw (1);		//admin doesn't have an orderList
}

void admin::displayDetails()
{
	std::cout << "Admin ID = " << id << "\n\tName: " << firstName << " " << surname << "\n\tAddress: \t" << address1 << "\n\t\t\t" << address2 << "\n\t\t\t" << postcode << std::endl << std::endl;
}

float admin::getDiscount()
{
	return 0.0;
}

admin::~admin()
{
}
