#ifndef ORDERLIST
#define ORDERLIST

#include <vector>

class order;

class orderList
{
	std::vector<order*> orderLst;
    addToList(basket &bskt);
};
#endif
