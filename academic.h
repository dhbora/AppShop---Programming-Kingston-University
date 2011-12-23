#ifndef ACADEMIC
#define ACADEMIC

#include "customer.h"

class academic : public customer
{
private:
	short discount;
	short gradePoint;

public:
    academic(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, char const *pass, const char *prof, const short years, const short grade = 0);
};
#endif
