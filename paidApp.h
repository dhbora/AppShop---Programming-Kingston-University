#ifndef PAIDAPP
#define PAIDAPP

#include "app.h"

class paidApp : public app
{
private:
	double price;
public:
    paidApp(const int ID, const char *name, const char *desc, user *dev, const double prc);
    void displayData(float discount = 0.0);
    double getPrice();
    virtual ~paidApp();
};
#endif
