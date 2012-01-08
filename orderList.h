#ifndef ORDERLIST
#define ORDERLIST

#include <vector>
#include <time.h>
#include "basket.h"

class app;
class shop;

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
                void displayOrder(float discount = 0);		//display single order details
                bool isItOnList(app *application);
        };

        std::vector<order*> orderLst;
        int numberOfPurchases;		//how many purchases has the user made


		int numberOfFreeApps, numberOfPaidApps;

		void updateNumberOfAppsPurchased(basket *bskt);
        int getNextId();		//it's a method

	public:
        orderList();
        basket* addToList(basket *bskt);
        void displayHistory(float discount = 0);		//display all items from the order list
        bool doIOwnIt(app *application);
        int getNumberOfFreeApps();
        int getNumberOfPaidApps();

};
#endif
