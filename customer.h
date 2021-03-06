#ifndef CUSTOMER
#define CUSTOMER

#include <string>
#include "user.h"
#include "basket.h"
#include "orderList.h"

class customer : public user
{
protected:
	short age;
    basket bskt;
    orderList ordrLst;

public:
    customer(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof, const short years);
    basket* getBasket() throw(int);
    orderList* getOrderList() throw (int);
    void displayDetails();
    float getDiscount();
    customer * editAge(short years);
    virtual ~customer();
};
#endif
