#ifndef APPLIST
#define APPLIST

#include <vector>

class app;
class user;

class appList
{
private:
	std::vector<app*> appLst;

public:
    appList* addApp(app *software);
    bool removeApp(int id);
	app* getAppById(const int id) throw (int);
	app* getAppByPosition(const unsigned int pos) throw (int);
	int getAppPosition(const int id) throw (int);
	void showList();		//display data of all members of the list
	int numberOfApps();
};

#endif
