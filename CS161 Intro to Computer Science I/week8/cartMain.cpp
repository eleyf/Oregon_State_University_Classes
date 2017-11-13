/*****************************

**	main to test classes

*****************************/

#include <iostream>
#include "ShoppingCart.hpp"
#include <string>

using namespace std;

int main()
{
	Item a("affidavit", 179.99, 12);
    Item b("Bildungsroman", 0.7, 20);
    Item c("capybara", 4.5, 6);
    Item d("dirigible", 0.05, 16);

/*    
    cout << endl;
    cout << "a values:" << "  ";
    cout << a.getName() << "  ";
    cout << a.getPrice() << "  ";
    cout << a.getQuantity() << endl << endl;

	cout << "b values:" << "  ";
    cout << b.getName() << "  ";
    cout << b.getPrice() << "  ";
    cout << b.getQuantity() << endl << endl;

    cout << "c values:" << "  ";
    cout << c.getName() << "  ";
    cout << c.getPrice() << "  ";
    cout << c.getQuantity() << endl << endl;

    cout << "d values:" << "  ";
    cout << d.getName() << "  ";
    cout << d.getPrice() << "  ";
    cout << d.getQuantity() << endl << endl;

*/

    ShoppingCart sc1;
    sc1.addItem(&a);
    sc1.addItem(&b);
    sc1.addItem(&c);
    sc1.addItem(&d);
    double diff = sc1.totalPrice();

    cout << "Total: " << diff << endl << endl;



	return 0;
}

