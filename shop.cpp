#include "shop.h"
#include "app.h"
#include "trialApp.h"
#include "paidApp.h"
#include "iostream"

shop::shop()
:currentUser(NULL)  //currentUser = NULL so it doesn't point to any user when creating a shop
{
}

user* shop::login(const int id, const char *pass)
{
    try
    {
        user* usr = usrLst.findUser(id);    //find required user by id
        if(usr->verifyPass(pass))           //verify user's password
            return currentUser = usr;
    }catch (int)
    {
        std::cout << "Cannot find a user with this ID" << std::endl;        //if couldn't find required user
    }

    return currentUser = NULL;
}

void shop::logout()
{
    currentUser = NULL;     //logout a user by assigning NULL to the pointer
}

app* shop::uploadApp(const char *name, const char *description, double price, short period) throw (char *)
{
    if(currentUser->getProfession() == "developer")     //developer has to be logged in to upload app
    {
        if (price == 0)     //if free app
        {
            trialApp *software = new trialApp(app::getNextID(), name, description, currentUser, period);
            applicationLst.addApp(software);
            app::increaseNumberOfApps();
            return software;
        }
        else        //if paid app
        {
            paidApp *software = new paidApp(app::getNextID(), name, description, currentUser, price);
            applicationLst.addApp(software);
            app::increaseNumberOfApps();
            return software;
        }
    }else       //if not developer logged in
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
