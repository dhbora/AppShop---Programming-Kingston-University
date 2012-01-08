#ifndef APP
#define APP

#include <string>

class user;

class app
{
private:
    static int numberOfApps;

protected:
	int popularity, id;
	std::string appName, description;
	user *devel;

public:
	app(const int ID, const char *name, const char *desc, user *dev);
	static int getNextID();
	app * editName(const char * name);
	app * editDescription(const char * desc);
	int getID();
	int getPopularity();
	const std::string getName();
	int increasePopularity();
	virtual void displayData(float discount = 0.0) = 0;
	virtual double getPrice() = 0;
	static int getNumberOfApps();
	static int increaseNumberOfApps();
	virtual ~app();
};
#endif
