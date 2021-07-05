/*******************************************************************************
* AUTHOR     : Belal Zahran
* STUDENT ID : 1176978
* CLASS      : CS1C - MTWT: 3:00 - 5:20pm
* DUE DATE   : 7/6/2021
*******************************************************************************/

#include <iostream>
#include "ManageInventory.h"
using namespace std;



/*******************************************************************************
* hw07 - Pointers and Dynamic Arrays
*-------------------------------------------------------------------------------
* This program is practice on dynamic memory allocation and deallocation for hw7
*-------------------------------------------------------------------------------*/
int main()
{

    cout << "*****************************************\n";
    cout << "   Programmed by: Belal Zahran\n";
    cout << "   Student ID   : 1176978\n";
    cout << "   CS1B         : MTWT: 3:00 - 5:20pm\n";
    cout << "   HW #7        : Pointers and Dynamic Arrays\n";
    cout << "*****************************************\n\n";


    // intitialize inventory
    ManageInventory myFirstInventory{5};
    ManageInventory secondInventory;


    // add items
    string newItem;
    ManageInventory firstInventory;


    cout << "Add new Item: ";
    getline(cin, newItem);
    firstInventory.addItem(newItem, 22, 145.99);

    cout << "\nAdd new Item: ";
    getline(cin, newItem);
    firstInventory.addItem(newItem, 33, 29.99);

    cout << "\nAdd new Item: ";
    getline(cin, newItem);
    firstInventory.addItem(newItem, 11, 111.44);

    cout << "\nAdd new Item: ";
    getline(cin, newItem);
    firstInventory.addItem(newItem, 20, 165.88);

    cout << "\nAdd new Item: ";
    getline(cin, newItem);
    firstInventory.addItem(newItem, 77, 45.77);

    cout << "\n\nCopying Original inventory into second inventory object...\n\n";
    secondInventory = firstInventory;

    firstInventory.PrintInventory();

// prompt the user to buy things from the inventory
    firstInventory.Shop();

    // print inventory
    firstInventory.PrintInventory();

    cout << "PRINT THE COPIED Original Inventory:\n";
    secondInventory.PrintInventory();





    return 0;
}




