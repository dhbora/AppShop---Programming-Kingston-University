#include "basket.h"
#include "app.h"
#include <iostream>

basket* basket::add(app *application)
{
	bool canAdd = true;
	for (int i = 0; i < basketList.numberOfApps(); i++)
		if (application->getID() == basketList.getAppByPosition(i)->getID())
			canAdd = false;

	if (canAdd)
    	basketList.addApp(application);
	else
		std::cout << "This app is already in basket" << std::endl;

    return this;
}

bool basket::remove(int id)
{
    return basketList.removeApp(id);
}

void basket::increasePopularity()
{
	for(int i = 0; i < basketList.numberOfApps(); i++)
		basketList.getAppByPosition(i)->increasePopularity();
}

double basket::workoutTotal(float discount)
{
    double total = 0.0;
    for(int i = 0; i < basketList.numberOfApps(); i++)
        total += basketList.getAppByPosition(i)->getPrice();		//go throgh all apps from the basket and add their prices to total

    return total * (1.0 - discount);

}

void basket::displayContent(float discount)
{
    basketList.showList(discount);
}

void basket::clearBasket()
{
	basketList.clearList();
}

bool basket::isEmpty()
{
	return basketList.isEmpty();
}

bool basket::isItOnList(app *application)
{
	for (int i = 0; i < basketList.numberOfApps(); i++)
		if (application->getID() == basketList.getAppByPosition(i)->getID())
			return true;	//if the app is in Basket return true

	return false;		//if it's not in the basket return flase

}

int basket::getNumberOfFreeApps()
{
	int freeApps = 0;
	for (int i = 0; i < basketList.numberOfApps(); i++)
		if (basketList.getAppByPosition(i)->getPrice() == 0.0)
			freeApps++;

	return freeApps;
}

int basket::getNumberOfPaidApps()
{
	int paidApps = 0;
	for (int i = 0; i < basketList.numberOfApps(); i++)
		if (basketList.getAppByPosition(i)->getPrice() != 0.0)
			paidApps++;

	return paidApps;
}
