#include "basket.h"
#include "app.h"


app* basket::add(app *application)
{
    basketList.addApp(application);
    return application;
}

bool basket::remove(int id)
{
    if(!basketList.removeApp(id))
        return true;

    return false;

}

double basket::workoutTotal()
{
    double total = 0.0;
    for(int i = 0; i < basketList.numberOfApps(); i++)
    {
        total += basketList.getAppByPosition(i)->getPrice();
    }
    return total;

}

void basket::displayContent()
{
    basketList.showList();
}
