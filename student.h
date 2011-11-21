#ifndef STUDENT
#define STUDENT

#include "customer.h"

class student : public customer
{
private:
	const short discount; //make 0.25 in contructor
	short gradePoint;

public:
    student(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const short grade, const char *prof, const short years);
};
#endif
