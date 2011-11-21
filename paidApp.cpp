#include "paidApp.h"

paidApp::paidApp(const int ID, const char *name, const char *desc, user *dev, const double prc)
:app(ID, name, desc, dev), price(prc)
{
}
