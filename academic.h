#ifndef ACADEMIC
#define ACADEMIC

#include "customer.h"

class academic : public customer
{
private:
	const short discount; //make 0.1 in constructor

public:
    academic(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years);
};
#endif
