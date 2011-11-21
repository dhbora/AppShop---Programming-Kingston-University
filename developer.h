#ifndef DEVELOPER
#define DEVELOPER

#include "user.h"

class app;

class developer : public user
{
public:
    developer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof);
    app* uploadApp(const char *name, const char *description, double price = 0, short period = 0);
};
#endif
