#include <iostream>
#include "shop.h"
#include "customer.h"

using namespace std;

int gui(shop *myShop);

int main()
{
    shop myShop;
	gui(&myShop);
    
    myShop.addUser("Mateusz", "Borkowski", "18 Western Avenue", "Wembley", "SW3 5TY", "mypass");
    myShop.addUser("Tomasz", "Kowalski", "102 Horn Lane", "Acton", "W3 6YR", "passwd", "developer", 22);
    myShop.addUser("Adam", "Malysz", "102 Horn Lane", "Acton", "W3 6YR", "passwd", "academic", 27);
    cout << "Total number of customers: " << myShop.getUserList()->numberOfCustomers() << endl;
    try
    {
    	myShop.getUserList()->getUserByName("Tomsz", "Kowalski");
    }catch (int)
	{
		cout << "Can't find the user" << endl;
	}
    myShop.showUserList();
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
    myShop.getAppList()->getAppByName("androiD");
	myShop.showAppList();
    myShop.logout();

    if (myShop.getUserList()->removeUser(2))
    	cout << "User succesfully removed" << endl;
	else
		cout << "User doesn't exist" << endl;

	myShop.showUserList();
	cout << "Total number of customers: " << myShop.getUserList()->numberOfCustomers() << endl;

    myShop.login(3, "passwd");
    try
    {
        myShop.addToBasket(myShop.getAppList()->getAppById(2));
        myShop.addToBasket(myShop.getAppList()->getAppById(1));
        myShop.addToBasket(myShop.getAppList()->getAppById(3));
        myShop.displayBasket();
        cout << "Total: " << myShop.getTotal() << endl << endl;

		if(myShop.getCurrentUser()->getBasket()->remove(1))
			cout << "Removing app successful" << endl;
		else
			cout << "No such app" << endl;


        cout << "After removing app id=1" << endl << endl;
        myShop.displayBasket();
        cout << "Total: " << myShop.getTotal() << endl << endl;
    }catch (int)
    {
        cout << "This user does not have a basket";
    }

    try
    {
    	cout << "Number of free apps purchased: " << myShop.getNoOfFreeAppsPurchased()
    		 << "\nNumber of paid apps purchased: " << myShop.getNoOfPaidAppsPurchased() << endl;
		cout << "Total apps purchased: " << myShop.totalAppsPurchased() << endl;
        myShop.placeOrder();
        cout << "Number of free apps purchased: " << myShop.getNoOfFreeAppsPurchased()
    		 << "\nNumber of paid apps purchased: " << myShop.getNoOfPaidAppsPurchased() << endl;
		cout << "Total apps purchased: " << myShop.totalAppsPurchased() << endl;
        myShop.addToBasket(myShop.getAppList()->getAppById(3));
        myShop.placeOrder();
        myShop.getCurrentUser()->getBasket()->remove(1);
        myShop.addToBasket(myShop.getAppList()->getAppById(1));
        myShop.addToBasket(myShop.getAppList()->getAppById(1));
        myShop.placeOrder();
        cout << "Number of free apps purchased: " << myShop.getNoOfFreeAppsPurchased()
    		 << "\nNumber of paid apps purchased: " << myShop.getNoOfPaidAppsPurchased() << endl;
		cout << "Total apps purchased: " << myShop.totalAppsPurchased() << endl;
        myShop.displayOrderHistory();
    }catch (int)
    {
        cout << "This user does not have order list";
    }

    myShop.logout();
    

    return 0;
}
