#include "shop.h"

shop::shop()
:currentUser(NULL)
{
}

user* shop::login(const int id, const char *pass)
{
    user* usr = usrLst.findUser(id);
    if(usr->verifyPass(pass))
        return currentUser = usr;
    else
        return currentUser = NULL;
}

void shop::logout()
{
    currentUser = NULL;
}

app* shop::uploadApp(const char *name, const char *description, double price, short period) throw (char *)
{
    if(currentUser->getProfession() == "developer")
    {
        applicationLst.addApp(name, description, currentUser, price, period);
    }else
    {
        const char *warning = "Only developer can upload apps";
        throw warning;
    }
}

userList* shop::getUserList()
{
    return &usrLst;
}

appList* shop::getAppList()
{
    return &applicationLst;
}

user* shop::getCurrentUser()
{
    return currentUser;
}

shop::~shop()
{
    currentUser = NULL;
}
