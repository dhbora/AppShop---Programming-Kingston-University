#include "appList.h"
#include "paidApp.h"
#include "trialApp.h"

app* appList::addApp(const char *name, const char *description, user *dev, double price, short period) //change user to developer
{
    if (price == 0)
    {
        trialApp *software = new trialApp(app::getNextID(), name, description, dev, period);
        appLst.push_back(software);
        return software;
    }else
    {
        paidApp *software = new paidApp(app::getNextID(), name, description, dev, price);
        appLst.push_back(software);
        return software;
    }
}

app* appList::findApp(const int id)
{
    for (int i = 0; (int) appLst.size(); i++)
    {
        if(appLst[i]->getID() == id)
            return appLst[i];
    }
    //throw exception

}
