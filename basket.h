#ifndef BASKET
#define BASKET

#include <vector>

class app;

class basket
{
private:
    std::vector<app*> appList;
    double total;
    short quantity;
public:
    app& add(app &application);
    app& remove(app &application);
    bool buy();
    double workoutTotal();

};
#endif
