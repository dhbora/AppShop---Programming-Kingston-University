#ifndef USER
#define USER

#include <string>

class basket;
class orderList;

class user
{
private:
    static int numberOfUsers;

protected:
	int id;
	std::string firstName, surname, profession, password,
				address1, address2, postcode;

public:
    user(const int ID, const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *prof);
    bool verifyPass(const char *pass);
    std::string getProfession();
    static int getNextID();
    int getID();
    virtual basket* getBasket() throw (int)= 0;
    virtual orderList* getOrderList() throw (int)= 0;
    const std::string getName();
    user * editFirstName(const char * fName);
    user * editSurname(const char * sName);
    user * editAddress(const char * adrs1, const char * adrs2, const char * pCode);
    user * changePassword(const char *pass);
    static int increaseNumberOfUsers();
    virtual void displayDetails() = 0;
    virtual float getDiscount() = 0;
    virtual ~user();

};
#endif
