#include "appList.h"
#include "app.h"
#include <iostream>
#include <ctype.h>
#include <string>

appList* appList::addApp(app *software)
{
        appLst.push_back(software);		//add app to the list
        return this;
}

bool appList::removeApp(int id)
{
    try															//try to remove app from the list
    {
        appLst.erase(appLst.begin() + getAppPosition(id));
    }catch (int)												//if app cannot be found
    {
        return false;
    }
    return true;
}

app* appList::getAppById(const int id) throw (int)
{
    for (unsigned int i = 0; i < appLst.size(); i++)		//search appList to find the app
    {
        if(appLst[i]->getID() == id)					//if that's the app
            return appLst[i];
    }
    throw (1);											//if ap not found throw exception
}

app* appList::getAppByPosition(const unsigned int pos) throw (int)
{
    if(pos < appLst.size())		//if position exists
        return appLst[pos];
    throw (1);					//if position doesn't exist
}

app* appList::getAppByName(const char *name) throw (int)
{
	for (unsigned int i = 0; i < appLst.size(); i++)		//search appList to find the app
    {
    	std::string str1, str2, str3;
    	str1 = appLst[i]->getName();
    	str2 = name;
    	for (unsigned int j = 0; j < str1.length(); j++)
    		str1[j] = tolower(str1[j]);

		for (unsigned int j = 0; j < str2.length(); j++)
    		str2[j] = tolower(str2[j]);

        //if(appLst[i]->getName() == name)
        if (str1 == str2)					//if that's the app
            return appLst[i];
    }
    throw (1);											//if ap not found throw exception
}

int appList::getAppPosition(const int id) throw (int)
{
    for (unsigned int i = 0; i < appLst.size(); i++)		//search appList for the app
    {
        if(appLst[i]->getID() == id)
            return i;									//if that's the app, return its position
    }
    throw (1);											//if app not found throw exception
}

void appList::showList(float discount)
{
    for(unsigned int i = 0; i < appLst.size(); i++)
        appLst[i]->displayData(discount);

}

int appList::numberOfApps()
{
    return appLst.size();		//return static variable from app class
}

void appList::clearList()
{
	appLst.clear();
}

bool appList::isEmpty()
{
	if (appLst.size() == 0)
		return true;
	else
		return false;
}
