#include "appList.h"
#include "app.h"
#include <iostream>

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
        std::cout << "No such application" << std::endl;
        return 1;
    }
    return 0;
}

app* appList::getAppById(const int id) throw (int)
{
    for (int i = 0; i < (int) appLst.size(); i++)		//search appList to find the app
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

int appList::getAppPosition(const int id) throw (int)
{
    for (int i = 0; i < (int) appLst.size(); i++)		//search appList for the app
    {
        if(appLst[i]->getID() == id)
            return i;									//if that's the app, return its position
    }
    throw (1);											//if app not found throw exception
}

void appList::showList()
{
    for(int i = 0; i < (int) appLst.size(); i++)
        appLst[i]->displayData();

}

int appList::numberOfApps()
{
    return appLst.size();		//return static variable from app class
}
