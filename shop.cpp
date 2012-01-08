#include "shop.h"
#include "app.h"
#include "trialApp.h"
#include "paidApp.h"
#include "iostream"

shop::shop()
:currentUser(NULL), totalNumberOfAppsPurchased(0)  //currentUser = NULL so it doesn't point to any user when creating a shop
{
}

float shop::getUserDiscount()
{
	return currentUser->getDiscount();
}

user* shop::login(const int id, const char *pass)
{
    try
    {
        user* usr = usrLst.getUserById(id);    //find required user by id
        if(usr->verifyPass(pass))           //verify user's password
            return currentUser = usr;
    }catch (int)
    {
        std::cout << "Cannot find a user with this ID" << std::endl;        //if couldn't find required user
    }

	std::cout << "Wrong Password" << std::endl;
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

user* shop::addUser(const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *profession, const short age, const short grade)
{
	return getUserList()->addUser(fName, sName, adrs1, adrs2, pCode, pass, profession, age, grade);
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

app* shop::addToBasket(app *application)
{
	if (!currentUser->getOrderList()->doIOwnIt(application))
	currentUser->getBasket()->add(application);
	return application;
}

basket* shop::placeOrder()
{
	totalNumberOfAppsPurchased += currentUser->getBasket()->getNumberOfFreeApps() + currentUser->getBasket()->getNumberOfPaidApps();
	currentUser->getOrderList()->addToList(currentUser->getBasket());
	return currentUser->getBasket();
}

int shop::totalAppsPurchased()
{
	return totalNumberOfAppsPurchased;
}

void shop::showUserList()
{
	getUserList()->showList();
}

void shop::showAppList()
{
	getAppList()->showList(getUserDiscount());
}

void shop::displayBasket()
{
	currentUser->getBasket()->displayContent(getUserDiscount());
}

double shop::getTotal()
{
	return currentUser->getBasket()->workoutTotal(getUserDiscount());
}
void shop::displayOrderHistory()
{
	currentUser->getOrderList()->displayHistory(getUserDiscount());
}

int shop::getNoOfFreeAppsPurchased()
{
	return currentUser->getOrderList()->getNumberOfFreeApps();
}

int shop::getNoOfPaidAppsPurchased()
{
	return currentUser->getOrderList()->getNumberOfPaidApps();
}

shop::~shop()
{
    currentUser = NULL;
}
