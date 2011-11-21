#ifndef TRIALAPP
#define TRIALAPP

#include "app.h"

class trialApp : public app
{
private:
	short trialPeriod;

public:
    trialApp(const int ID, const char *name, const char *desc, user *dev, short period);

};
#endif
