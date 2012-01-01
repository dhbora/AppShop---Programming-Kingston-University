#include "basket.h"
#include "app.h"


basket* basket::add(app *application)
{
    basketList.addApp(application);
    return this;
}

bool basket::remove(int id)
{
    if(!basketList.removeApp(id))
        return true;		//if removing suceeded return true

    return false;			//otherwise return false

}

void basket::increasePopularity()
{
	for(int i = 0; i < basketList.numberOfApps(); i++)
		basketList.getAppByPosition(i)->increasePopularity();
}

double basket::workoutTotal()
{
    double total = 0.0;
    for(int i = 0; i < basketList.numberOfApps(); i++)
        total += basketList.getAppByPosition(i)->getPrice();		//go throgh all apps from the basket and add their prices to total

    return total;

}

void basket::displayContent()
{
    basketList.showList();
}
