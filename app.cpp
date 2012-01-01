#include "app.h"

int app::numberOfApps = 0;		//initializing static variable

app::app(const int ID, const char *name, const char *desc, user *dev)
:popularity(0), id(ID), appName(name), description(desc), devel(dev)
{
}

int app::getNextID()
{
    return numberOfApps + 1;
}

app * app::editName(char * name)
{
	appName = name;
	return this;
}

app * app::editDescription(char * desc)
{
	description = desc;
	return this;
}

int app::getPopularity()
{
	return popularity;
}

int app::increasePopularity()
{
	return popularity++;
}

int app::getID()
{
    return id;
}

int app::getNumberOfApps()
{
	return numberOfApps;
}

int app::increaseNumberOfApps()
{
    return ++numberOfApps;		//incrementing number of apps and returning the value
}

app::~app()
{
}
