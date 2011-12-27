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
    short quantity;
public:
    app* add(app *application);
    bool remove(int id);
//    bool buy();
    double workoutTotal();
    void displayContent();

};
#endif
