#include "student.h"

student::student(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const short grade, const char *prof, const short years)
:gradePoint(grade), discount(0.25), customer(ID, fName, sName, adrs1, adrs2, pCode, pass, prof, years)
{
}
