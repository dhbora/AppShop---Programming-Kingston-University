#include "developer.h"

developer::developer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof)
:user(ID, fName, sName, adrs1, adrs2, pCode, pass, prof)
{
}

basket* developer::getBasket() throw (int)
{
    throw (1);
}
