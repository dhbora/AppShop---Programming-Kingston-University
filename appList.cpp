#include "appList.h"
#include "app.h"
#include <iostream>

app* appList::addApp(app *software)
{
        appLst.push_back(software);
        return software;
}

bool appList::removeApp(int id)
{
    try
    {
        appLst.erase(appLst.begin() + getAppPosition(id));
    }catch (int)
    {
        std::cout << "No such application" << std::endl;
        return 1;
    }
    return 0;
}

app* appList::getAppById(const int id) throw (int)
{
    for (int i = 0; i < (int) appLst.size(); i++)
    {
        if(appLst[i]->getID() == id)
            return appLst[i];
    }
    throw (1);
}

app* appList::getAppByPosition(const unsigned int pos) throw (int)
{
    if(pos < appLst.size())
        return appLst[pos];
    throw (1);
}

int appList::getAppPosition(const int id) throw (int)
{
    for (int i = 0; i < (int) appLst.size(); i++)
    {
        if(appLst[i]->getID() == id)
            return i;
    }
    throw (1);
}

void appList::showList()
{
    for(int i = 0; i < (int) appLst.size(); i++)
        appLst[i]->displayData();

}

int appList::numberOfApps()
{
    return appLst.size();
}
