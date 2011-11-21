#ifndef APPLIST
#define APPLIST

#include <vector>

class app;
class user; // change to developer

class appList
{
private:
	std::vector<app*> appLst;

public:
    app* addApp(const char *name, const char *description, user *dev, double price = 0, short period = 0);//change user to developer
	app* findApp(const int id);

};

#endif
