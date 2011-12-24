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
	app* findApp(const int id);

};

#endif
