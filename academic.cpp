#include "academic.h"
#include <cstring>
#include <string>

academic::academic(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years, const short grade)
: customer(ID, fName, sName, adrs1, adrs2, pCode, pass, prof, years), gradePoint(grade)
{
    if ((profession == "academic") && age > 25)
        discount = 0.1;
    else if((profession == "student") && (age < 25) && (gradePoint > 7))
        discount = 0.25;
    else
        discount = 0;
}
