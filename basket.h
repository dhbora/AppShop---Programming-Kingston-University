#ifndef BASKET
#define BASKET

#include <vector>
#include "appList.h"

class app;

class basket
{
private:
    appList basketList;
    double total;
public:
    basket* add(app *application);
    bool remove(int id);
    void increasePopularity();	//increase popularity of each app
    double workoutTotal(float discount = 0);
    void displayContent(float discount = 0);		//display all details of all items from the basket
    void clearBasket();
    bool isEmpty();
    bool isItOnList(app *application);
    int getNumberOfFreeApps();
    int getNumberOfPaidApps();

};
#endif
