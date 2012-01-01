#include "admin.h"

admin::admin(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof)
:user(ID, fName, sName, adrs1, adrs2, pCode, pass, prof)
{

}

basket* admin::getBasket() throw(int)
{
    throw (1);		//admin doesn't have a basket
}

orderList* admin::getOrderList() throw (int)
{
    throw (1);		//admin doesn't have an orderList
}

admin::~admin()
{
}
