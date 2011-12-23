#include "userList.h"
#include "academic.h"
#include "admin.h"
#include "developer.h"
#include <cstring>

user* userList::addUser(const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *profession, const short age, const short grade)
{
    if(!strcmp(profession, "academic") || !strcmp(profession, "student"))
    {
        academic *usr = new academic(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession, age, grade);
        usrLst.push_back(usr);
        return usr;
    }else if (!strcmp(profession, "admin"))
    {
        admin *usr = new admin(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession);
        usrLst.push_back(usr);
        return usr;
    }else if (!strcmp(profession, "developer"))
    {
        developer *usr = new developer(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession);
        usrLst.push_back(usr);
        return usr;
    }
    /*else
    {
        //throw exception
    }*/

}

user* userList::findUser(const int id)
{
    for (int i = 0; (int) usrLst.size(); i++)
    {
        if(usrLst[i]->getID() == id)
            return usrLst[i];
    }
    //throw exception

}
