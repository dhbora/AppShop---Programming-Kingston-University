#include "customer.h"

customer::customer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years)
:user(ID, fName, sName, adrs1, adrs2, pCode, pass, prof), age(years)
{
}
