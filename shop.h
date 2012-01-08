#ifndef SHOP
#define SHOP

#include "appList.h"
#include "app.h"
#include "userList.h"
#include "user.h"
#include "academic.h"
#include "admin.h"
#include "developer.h"

class shop
{
private:
    appList applicationLst;
	userList usrLst;
	user *currentUser;   //currently logged in user
	int totalNumberOfAppsPurchased;

	float getUserDiscount();

public:
    shop();
    user* login(const int id, const char *pass);
    void logout();
    app* uploadApp(const char *name, const char *description, double price = 0, short period = 0) throw(char *);
 	user* addUser(const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *profession = "customer", const short age = 200, const short grade = 0);
    userList* getUserList();
    appList* getAppList();
    user* getCurrentUser();
    app* addToBasket(app *application);
    int totalAppsPurchased();
    basket* placeOrder();
    void showUserList();
    void showAppList();
    void displayBasket();
    double getTotal();
    void displayOrderHistory();
    int getNoOfFreeAppsPurchased();
    int getNoOfPaidAppsPurchased();
    ~shop();
};

#endif
