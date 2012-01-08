#ifndef USERLIST
#define USERLIST

#include <vector>
#include <string>
//#include "user.h"

class user;

class userList
{
private:
	std::vector<user*> usrLst;
public:
	user* addUser(const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *profession = "customer", const short age = 200, const short grade = 0);
	user* getUserById(const int id) throw (int);
	user* getUserByName(const char* fname, const char* sname) throw (int);
	bool removeUser(int id);
	int getUserPosition(const int id) throw (int);
	void showList();		//display data of all members of the list
	int numberOfCustomers();
};
#endif
