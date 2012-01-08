#include "userList.h"
#include "academic.h"
#include "admin.h"
#include "developer.h"
#include "customer.h"
#include <cstring>
#include <string>
#include <iostream>

user* userList::addUser(const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *profession, const short age, const short grade)
{
    if(!strcmp(profession, "academic") || !strcmp(profession, "student"))		//what kind of user to create
    {
    	std::cout << "Your ID = " << user::getNextID() << std::endl;
        academic *usr = new academic(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession, age, grade);
        usrLst.push_back(usr);		//add user to the list
        user::increaseNumberOfUsers();
        return usr;
    }else if (!strcmp(profession, "admin"))
    {
    	std::cout << "Your ID = " << user::getNextID() << std::endl;
        admin *usr = new admin(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession);
        usrLst.push_back(usr);		//add user to the list
        user::increaseNumberOfUsers();
        return usr;
    }else if (!strcmp(profession, "developer"))
    {
    	std::cout << "Your ID = " << user::getNextID() << std::endl;
        developer *usr = new developer(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession);
        usrLst.push_back(usr);		//add user to the list
        user::increaseNumberOfUsers();
        return usr;
    }else
    {
    	std::cout << "Your ID = " << user::getNextID() << std::endl;
        customer *usr = new customer(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession, age);
        usrLst.push_back(usr);		//add user to the list
        user::increaseNumberOfUsers();
        return usr;
    }

}

user* userList::getUserById(const int id) throw (int)
{
    for (unsigned int i = 0; i < usrLst.size(); i++)		//go through the list and find the user
    {
        if(usrLst[i]->getID() == id)
            return usrLst[i];
    }

    throw (1);		//if user not found throw exception
}

user* userList::getUserByName(const char* fname, const char* sname) throw (int)
{
	std::string name = fname;
	name += " ";
	name += sname;

	for (unsigned int i = 0; i < usrLst.size(); i++)		//search usrList to find the user
    {
        if(usrLst[i]->getName() == name)					//if that's the user
            return usrLst[i];
    }
    throw (1);
}

bool userList::removeUser(int id)
{
	try															//try to remove app from the list
    {
        usrLst.erase(usrLst.begin() + getUserPosition(id));
    }catch (int)												//if app cannot be found
    {
        return false;;
    }
    return true;
}

int userList::getUserPosition(const int id) throw (int)
{
	for (unsigned int i = 0; i < usrLst.size(); i++)		//search userList for the user
    {
        if(usrLst[i]->getID() == id)
            return i;									//if that's the user, return position
    }
    throw (1);
}

void userList::showList()
{
	for(unsigned int i = 0; i < usrLst.size(); i++)
        usrLst[i]->displayDetails();
}

int userList::numberOfCustomers()
{
	return (int) usrLst.size();
}
