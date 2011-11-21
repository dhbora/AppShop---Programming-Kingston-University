#include "app.h"

int app::numberOfApps = 0;

app::app(const int ID, const char *name, const char *desc, user *dev)//change user to developer
:population(0), id(ID), appName(name), description(desc), devel(dev)
{
}

int app::getNextID()
{
    return ++numberOfApps;
}


int app::getID()
{
    return id;
}
