#ifndef USER
#define USER

#include <string>

class user
{
private:
    static int numberOfUsers;

protected:
	int id;
	std::string firstName, surname, profession, password;
	//char *password;
	std::string address1, address2, postcode;

public:
    user(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof);
    bool verifyPass(const char *pass);
    std::string getProfession();
    static int getNextID();
    int getID();
    user * editFirstName(char * fName);
    user * editSurname(char * sName);
    user * editAddress(char * adrs1, char * adrs2, char * pCode);
    user * changePassword(char pass);

};
#endif
