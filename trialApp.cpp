#include "trialApp.h"

trialApp::trialApp(const int ID, const char *name, const char *desc, user *dev, short period)
:app(ID, name, desc, dev), trialPeriod(period)
{
}
