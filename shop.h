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
	user *currentUser;   //currently logged in user         //change for smart pointer

public:
    shop();
    user* login(const int id, const char *pass);
    void logout();
    app* uploadApp(const char *name, const char *description, double price = 0, short period = 0) throw(char *);
    userList* getUserList();
    appList* getAppList();
    user* getCurrentUser();
    ~shop(); //for *currentUser
};

#endif
