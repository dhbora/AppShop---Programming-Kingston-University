#ifndef CUSTOMER
#define CUSTOMER

#include <string>
#include "user.h"
#include "basket.h"

class customer : public user
{
protected:
	short age;
    basket bskt;

public:
    customer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years);
    basket* getBasket() throw(int);
};
#endif
