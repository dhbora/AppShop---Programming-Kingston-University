#include <iostream>
#include "shop.h"
#include "customer.h"

using namespace std;

int main(int argc, char *argv[])
{
    shop myShop;
    myShop.getUserList()->addUser("Mateusz", "Borkowski", "18 Western Avenue", "Wembley", "SW3 5TY", "mypass");
    myShop.getUserList()->addUser("Tomasz", "Kowalski", "102 Horn Lane", "Acton", "W3 6YR", "passwd", "developer", 22);
    myShop.login(2, "passwd");
    try
    {
        myShop.uploadApp("MyApp", "This is my application", 5);
        myShop.uploadApp("Android", "Operating System", 0, 30);
        myShop.uploadApp("SomeApp", "This is some application", 10);
    }catch(char *warn)
    {
        cout << warn << endl;
    }

    myShop.logout();
    myShop.login(1, "mypass");
    try
    {
        myShop.getCurrentUser()->getBasket()->add(myShop.getAppList()->getAppById(2));
        myShop.getCurrentUser()->getBasket()->add(myShop.getAppList()->getAppById(1));
        myShop.getCurrentUser()->getBasket()->add(myShop.getAppList()->getAppById(3));
        myShop.getCurrentUser()->getBasket()->displayContent();
        cout << "Total: " << myShop.getCurrentUser()->getBasket()->workoutTotal() << endl << endl;
        myShop.getCurrentUser()->getBasket()->remove(1);
        cout << "After removing app id=1" << endl << endl;
        myShop.getCurrentUser()->getBasket()->displayContent();
        cout << "Total: " << myShop.getCurrentUser()->getBasket()->workoutTotal() << endl << endl;
    }catch (int)
    {
        cout << "This user does not have a basket";
    }

    myShop.logout();
    return 0;
}
