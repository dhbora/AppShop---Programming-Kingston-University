#ifndef ADMIN
#define ADMIN

#include "user.h"

class admin : public user
{
private:

public:
    admin(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof);
    basket* getBasket() throw (int);		//throws an exception
    orderList* getOrderList() throw (int);		//throws an exception
    void displayDetails();
    float getDiscount();
    virtual ~admin();
};
#endif
