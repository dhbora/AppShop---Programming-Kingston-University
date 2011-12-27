#ifndef USERLIST
#define USERLIST

#include <vector>
//#include "user.h"

class user;

class userList
{
private:
	std::vector<user*> usrLst;
public:
	user* addUser(const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *profession = "customer", const short age = 100, const short grade = 0);
	user* findUser(const int id) throw (int);
};
#endif
