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
    app* addApp(app *software);
    bool removeApp(int id);
	app* getAppById(const int id) throw (int);
	app* getAppByPosition(const unsigned int pos) throw (int);
	int getAppPosition(const int id) throw (int);
	void showList();
	int numberOfApps();
};

#endif
