#ifndef ORDERLIST
#define ORDERLIST

#include <vector>
#include <time.h>
#include "basket.h"

class orderList
{
    private:

        class order
        {
            private:
                int id;
                basket basketPurchased;
                time_t datetime;

            public:
                order(int ID, basket *bskt);
                void displayOrder();
        };

        std::vector<order*> orderLst;
        int numberOfPurchases;

        int getNextId();

	public:
        orderList();
        basket* addToList(basket *bskt);
        void displayHistory();

};
#endif
