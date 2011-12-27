#include "shop.h"
#include "app.h"
#include "trialApp.h"
#include "paidApp.h"

shop::shop()
:currentUser(NULL)
{
}

user* shop::login(const int id, const char *pass)
{
    try
    {
        user* usr = usrLst.findUser(id);
        if(usr->verifyPass(pass))
            return currentUser = usr;
    }catch (int)
    {
    }

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
        if (price == 0)
        {
            trialApp *software = new trialApp(app::getNextID(), name, description, currentUser, period);
            applicationLst.addApp(software);
            return software;
        }
        else
        {
            paidApp *software = new paidApp(app::getNextID(), name, description, currentUser, price);
            applicationLst.addApp(software);
            return software;
        }
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
