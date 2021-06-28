#include "ManageInventory.h"



// default constructor
ManageInventory::ManageInventory()
        : count{0}, p__pInventoryItems{new Item *[size]}
{

}

// alternate constructor
ManageInventory::ManageInventory(int size)
        : size{size}, count{0}, p__pInventoryItems{new Item *[size]}
{

}

// destructor that first deallocated each item in array and then deallocated the array itself
ManageInventory::~ManageInventory()
{
    // looping through array to delete items
    for (int i = 0; i < count; i++)
    {
        delete p__pInventoryItems[i];
    }
    // deleting array
    delete [] p__pInventoryItems;
}




// method to add items to the array of items
void ManageInventory::addItem(string name, int quantity, float cost)
{

    // create new pointer
    Item *x = new Item;

    // add values
    x->name = name;
    x->quantity = quantity;
    x->cost = cost;

    // insert and increment count
    p__pInventoryItems[count] = x;

    count++;
}

// method to print out inventory
void ManageInventory::PrintInventory() const
{
    cout << left;

    cout << "INVENTORY:\n";
    cout << "Item        # left   Price\n";
    cout <<"----------- ------- -------\n";
    // loop through list
    for (int i = 0; i < count; i++)
    {
        // output values
        cout << setw(14) << p__pInventoryItems[i]->name;
        cout << setw(6) << p__pInventoryItems[i]->quantity;
        cout << "$" << p__pInventoryItems[i]->cost << endl;
    }

    cout << right;
}