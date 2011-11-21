#ifndef USER
#define USER

#include <string>

class user
{
private:
	int id;
	static int numberOfUsers;
	std::string firstName, surname, profession;//, password;
	const char *password;   //change to string if possible
	std::string address1, address2, postcode;

public:
    user(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof);
    bool verifyPass(const char *pass);
    const char* getProfession();
    static int getNextID();
    int getID();


};
#endif
