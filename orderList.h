#ifndef ORDERLIST
#define ORDERLIST

#include <vector>
#include <time.h>
#include "basket.h"

class orderList
{
    private:

        class order		//order class that will be user only within orderList
        {
            private:
                int id;
                basket basketPurchased;
                time_t datetime;

            public:
                order(int ID, basket *bskt);
                void displayOrder();		//display single order details
        };

        std::vector<order*> orderLst;
        int numberOfPurchases;		//how many purchases has the user made

        int getNextId();		//it's a method

	public:
        orderList();
        basket* addToList(basket *bskt);
        void displayHistory();		//display all items from the order list

};
#endif
