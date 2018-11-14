#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    List cory;

    cout << "empty(); function returns: " << cory.empty() << endl << endl;

    cory.insert(4, 0);
    cory.insert(5, 1);
    cory.insert(6, 2);

    cout << "Size of list: " << cory.getSize() << endl << endl;

    cout << "empty(); function returns: " << cory.empty() << endl << endl;



    cout << "Using print() function..." << endl << endl;
    cory.print(cout);


    cout << endl << "Adding elements and printing..." << endl << endl;
    cory.insert(7, 3);
    cory.insert(8, 4);
    cory.print(cout);
    cout << endl;

    cout << "Traversing for data member ""5""....." << endl << endl;
    cory.traverse(5);

    cout << "Deleting index 3 and printing..." << endl << endl;
    cory.deleteElem(3);
    cout << "Size of list: " << cory.getSize() << endl << endl;


    cory.print(cout);

   cout << "Testing getNth() function...." << endl << endl;
   cout << "Result of function call with Index 0: " << cory.getNth(0) << endl << endl;
   cout << "Result of function call with Index 2: " << cory.getNth(2) << endl << endl;
   cout << "Result of function call with Index 5: " << cory.getNth(5) << endl << endl;

   cout << "Testing the split() function..." << endl << endl;
   cout << "Result of split() on list 'Cory'..." << endl;
   cory.split();

   cout << endl << "Creating new list 'compe' with 6 elements, then split()...." << endl << endl;
    List compe;
    compe.insert(1, 0);
    compe.insert(2, 1);
    compe.insert(3, 2);
    compe.insert(4, 3);
    compe.insert(5, 4);
    compe.insert(6, 5);
    compe.split();

    cout << endl << "Creating new list 'c160' with 0 elements, then split()...." << endl << endl;
    List c160;
    c160.split();

    cout << endl << "Creating new list 'Jay' with 1 element, then split()...." << endl << endl;
    List Jay;
    Jay.insert(10, 0);
    Jay.split();


    cout << endl << "Creating new list 'Clem' with 2 elements, then split()...." << endl << endl;
    List clem;
    clem.insert(3, 0);
    clem.insert(4, 1);
    clem.split();




    return 0;
}
