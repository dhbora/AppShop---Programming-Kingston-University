#include "orderList.h"
#include "app.h"
#include "shop.h"
#include <time.h>
#include <iostream>

orderList::orderList(): numberOfPurchases(0), numberOfFreeApps(0), numberOfPaidApps(0)
{
}

void orderList::updateNumberOfAppsPurchased(basket *bskt)
{
	numberOfFreeApps += bskt->getNumberOfFreeApps();
	numberOfPaidApps += bskt->getNumberOfPaidApps();
}

int orderList::getNextId()
{
    return numberOfPurchases + 1;
}

orderList::order::order(int ID, basket *bskt): id(ID), basketPurchased(*bskt)
{
    time ( &datetime);
}

void orderList::order::displayOrder(float discount)
{
    struct tm *tme = localtime(&datetime);
    char buffer[40];
    strftime(buffer, 40, "%x at %X", tme);		//display date and time in the format MM/DD/YY at HH:MM:SS
    std::cout << "Order number: " << id << " purchased on: " << buffer << " consists of:" << std::endl;
    basketPurchased.displayContent(discount);
}

bool orderList::order::isItOnList(app *application)
{
	return basketPurchased.isItOnList(application);
}

basket* orderList::addToList(basket *bskt)
{
	if (!bskt->isEmpty())
	{
		orderLst.push_back(new order(getNextId(), bskt));		//add basket's content to the order list
		bskt->increasePopularity();
		numberOfPurchases++;		//increase number of purchases
		updateNumberOfAppsPurchased(bskt);
		bskt->clearBasket();
	}else
	{
		std::cout << "Couldn't take order, basket is empty" << std::endl;
	}
    return bskt;
}

void orderList::displayHistory(float discount)
{
    for(unsigned int i = 0; i < orderLst.size(); i++)		//go through the order list and display its content
    {
        orderLst[i]->displayOrder(discount);
    }

}

bool orderList::doIOwnIt(app *application)
{
	for (unsigned int i = 0; i < orderLst.size(); i++)
		if (orderLst[i]->isItOnList(application))
			return true;		//if the app has already been purchased return true

	return false;		//if the app has not been purchased return flase
}

int orderList::getNumberOfFreeApps()
{
	return numberOfFreeApps;
}

int orderList::getNumberOfPaidApps()
{
	return numberOfPaidApps;
}
