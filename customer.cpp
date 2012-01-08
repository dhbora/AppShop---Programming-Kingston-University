#include "customer.h"
#include <iostream>

customer::customer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years)
:user(ID, fName, sName, adrs1, adrs2, pCode, pass, prof), age(years)
{
}

basket* customer::getBasket() throw (int)
{
    return &bskt;
}

orderList* customer::getOrderList() throw (int)
{
    return &ordrLst;
}

void customer::displayDetails()
{
	std::cout << "Customer ID = " << id << "\n\tName: " << firstName << " " << surname << "\n\tAddress: \t" << address1 << "\n\t\t\t" << address2 << "\n\t\t\t" << postcode;
	if(age != 200)
		std::cout << "\n\tAge: " << age;

	std::cout << std::endl << std::endl;
}

float customer::getDiscount()
{
	return 0.0;
}

customer *customer::editAge(short years)
{
  age = years;
  return this;
}

customer::~customer()
{
}
