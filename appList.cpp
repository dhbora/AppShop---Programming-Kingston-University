#include "appList.h"
#include "app.h"

app* appList::addApp(app *software)
{
        appLst.push_back(software);
        return software;
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
