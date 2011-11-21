#include <iostream>
#include "shop.h"

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
    }catch(char *warn)
    {
        cout << warn << endl;
    }

    myShop.logout();
    return 0;
}
