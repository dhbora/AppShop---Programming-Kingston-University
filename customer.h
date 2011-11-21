#ifndef CUSTOMER
#define CUSTOMER

#include <string>
#include "user.h"

class customer : public user
{
private:
	short age;

public:
    customer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years);


};
#endif
