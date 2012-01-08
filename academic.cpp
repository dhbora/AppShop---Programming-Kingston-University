#include "academic.h"
#include <cstring>
#include <string>
#include <iostream>

academic::academic(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years, const short grade)
: customer(ID, fName, sName, adrs1, adrs2, pCode, pass, prof, years), gradePoint(grade)
{
    if ((profession == "academic") && age > 25)		//what discount to apply
        discount = 0.1;
    else if((profession == "student") && (age <= 25) && (gradePoint > 7))
        discount = 0.25;
    else
        discount = 0;	//user doesn't meet discount requirements
}

void academic::displayDetails()
{
	std::cout << "Academic ID = " << id << "\n\tName: " << firstName << " " << surname << "\n\tAddress: \t" << address1 << "\n\t\t\t" << address2 << "\n\t\t\t" << postcode;
	if(age != 200)
		std::cout << "\n\tAge: " << age;
	if(gradePoint != 0)
		std::cout <<  "\n\tGrade Point: " << gradePoint;
	if(discount != 0.0)
		std::cout << "\n\tDiscount: " << discount * 100 << "%";

	std::cout << std::endl << std::endl;
}

float academic::getDiscount()
{
	return discount;
}

academic * academic::editGradePoint(short grade)
{
  gradePoint = grade;
  return this;
}

academic::~academic()
{
}
