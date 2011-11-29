#include "user.h"
    #include <cstring>
#include <string>

int user::numberOfUsers = 0;

user::user(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof)
:id(ID), firstName(fName), surname(sName), profession(prof), password(pass), address1(adrs1), address2(adrs2), postcode(pCode)
{
}

bool user::verifyPass(const char *pass)
{
    if (!strcmp(pass, password))
        return true;
    else
        return false;

}

const char* user::getProfession()
{
    return profession.c_str();
}

int user::getNextID()
{
    return ++numberOfUsers;
}

user * user::editFirstName(char * fName)
{
firstName = fName;
return this;
}

user * user::editSurname(char * sName);
{
	surname = sName
		return this;
}

user * user::editAddress(char * adrs1, char * adrs2, char * pCode);
{
	address1 = adrs1;
	address2 = adrs2;
	postcode = pCode;
	return this;
}

user * user::changePassword(char pass);
{
password = pass;
return this;
}

int user::getID()
{
    return id;
}
