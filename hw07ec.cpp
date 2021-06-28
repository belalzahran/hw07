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
* hw07ec - Dynamic Memory
*-------------------------------------------------------------------------------
* This program is practice on dynamic memory allocation and deallocation for hw7
*-------------------------------------------------------------------------------*/
int main()
{

    cout << "*****************************************\n";
    cout << "   Programmed by: Belal Zahran\n";
    cout << "   Student ID   : 1176978\n";
    cout << "   CS1B         : MTWT: 3:00 - 5:20pm\n";
    cout << "   HW #7ec      : Dynamic Memory \n";
    cout << "*****************************************\n\n";


    // intitialize inventory
    ManageInventory myFirstInventory{5};


    // add items
    myFirstInventory.addItem("Shoes", 33, 20.99);
    myFirstInventory.addItem("Sunglasses", 23, 19.99);
    myFirstInventory.addItem("Hats", 124, 10.99);
    myFirstInventory.addItem("Umbrellas", 14, 19.99);
    myFirstInventory.addItem("Jackets", 23, 59.99);



    // print inventory
    myFirstInventory.PrintInventory();



    return 0;
}