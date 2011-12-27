#ifndef APP
#define APP

#include <string>

class user; //change to developer

class app
{
private:
    static int numberOfApps;

protected:
	int population;
	int id;
	std::string appName, description;
	user *devel;

public:
	app(const int ID, const char *name, const char *desc, user *dev);//change user to developer
	static int getNextID();
	app * editName(char * name);
	app * editDescription(char * desc);
	int getID();
	int getPopulation();
	virtual void displayData() = 0;
	virtual double getPrice() = 0;
};
#endif
