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
	app* getAppByName(const char* name) throw (int);
	int getAppPosition(const int id) throw (int);
	void showList(float discount = 0);		//display data of all members of the list
	int numberOfApps();
	void clearList();
	bool isEmpty();
};

#endif
