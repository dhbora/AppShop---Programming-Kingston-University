#include "orderList.h"
#include <time.h>
#include <iostream>

orderList::orderList(): numberOfPurchases(0)
{
}

int orderList::getNextId()
{
    return numberOfPurchases + 1;
}

orderList::order::order(int ID, basket *bskt): id(ID), basketPurchased(*bskt)
{
    time ( &datetime);
}

void orderList::order::displayOrder()
{
    struct tm *tme = localtime(&datetime);
    char buffer[40];
    strftime(buffer, 40, "%x at %X", tme);		//display date and time in the format MM/DD/YY at HH:MM:SS
    std::cout << "Order number: " << id << " purchased on: " << buffer << " consists of:" << std::endl;
    basketPurchased.displayContent();
}

basket* orderList::addToList(basket *bskt)
{
    orderLst.push_back(new order(getNextId(), bskt));		//add basket's content to the order list
    bskt->increasePopularity();
    numberOfPurchases++;		//increase number of purchases
    return bskt;
}

void orderList::displayHistory()
{
    for(unsigned int i = 0; i < orderLst.size(); i++)		//go through the order list and display its content
    {
        orderLst[i]->displayOrder();
    }

}
