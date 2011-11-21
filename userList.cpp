#include "userList.h"
#include "academic.h"
#include "admin.h"
#include "developer.h"
#include "student.h"
#include <cstring>

user* userList::addUser(const char *fName, const char *sName, const char *adrs1, const char *adrs2, const char *pCode, const char *pass, const char *profession, const short age, const short grade)
{
    if(!strcmp(profession, "academic"))
    {
        academic *usr = new academic(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, profession, age);
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
    }else if ((!strcmp(profession, "student")) && (age < 25) && (grade > 7))
    {
        student *usr = new student(user::getNextID(), fName, sName, adrs1, adrs2, pCode, pass, grade, profession, age);
        usrLst.push_back(usr);
        return usr;
    }/*else
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
