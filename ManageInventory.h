
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
using namespace std;

#ifndef HW7EC_MANAGEINVENTORY_H
#define HW7EC_MANAGEINVENTORY_H


// struct for the Items and its aspects
struct Item{
    string name;
    int quantity;
    float cost;
};


// max size of an item array
const int MAX_SIZE = 50;

class ManageInventory{

private:
    int size{50};
    int count;
    Item ** p__pInventoryItems;

public:
/********************************************************************
 * Default Constructor ManageInventory: class ManageInventory
 * ------------------------------------------------------------------
 * This creates a default instance of the class
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * <none>
 *
 * POST-CONDITIONS
 * this function creates a ManageInventory object
 ********************************************************************/
    ManageInventory();

/********************************************************************
 * Alternate Constructor ManageInventory: class ManageInventory
 * ------------------------------------------------------------------
 * This creates a default instance of the class
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * <none>
 *
 * POST-CONDITIONS
 * this function creates a ManageInventory object
 ********************************************************************/
    ManageInventory(int size);

/********************************************************************
 * Destructor ~ManageInventory: class ManageInventory
 * ------------------------------------------------------------------
 * This deallocated memory on heap of the class object
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * <none>
 *
 * POST-CONDITIONS
 * this function destroys a ManageInventory object
 ********************************************************************/
    ~ManageInventory();

/********************************************************************
 * Copy Constructor ManageInventory: class ManageInventory
 * ------------------------------------------------------------------
 * This performs a deep copy of the class object
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * <none>
 *
 * POST-CONDITIONS
 * exact copy of original manageInventory object
 ********************************************************************/
    ManageInventory(const ManageInventory& invent);


/********************************************************************
 * Method addItem: class ManageInventory
 * ------------------------------------------------------------------
 * This method enters an item into the array of items
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * existing inventory and a quantity, cost, and name
 *
 * POST-CONDITIONS
 * added item to inventory
 ********************************************************************/
    void addItem(string name, int quantity, float cost);

/********************************************************************
 * Method ItemPurchase: class ManageInventory
 * ------------------------------------------------------------------
 * This method will allow a purchase to be made from the inventory
 * meaning that the quantity of one of the items will be deducted from
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * existing manageInventory object
 *
 * POST-CONDITIONS
 * the quantity of one selected items will be deducted from
 ********************************************************************/
    void ItemPurchase(string name, int quantity);

/********************************************************************
 * Method Shop: class ManageInventory
 * ------------------------------------------------------------------
 * This perform a shopping experience and allow the user to select
 * the items and enter how many he or she would like to buy.
 * this method will also call a receipt function at the end to print
 * the transactions made
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * existing manageInventory object
 *
 * POST-CONDITIONS
 * deductions of items and printed receipts
 ********************************************************************/
    void Shop();


/********************************************************************
 * Method GetIndex: class ManageInventory
 * ------------------------------------------------------------------
 * This method will return the index of an item in the item array
 * after taking in the name of the object
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * existing manageInventory object
 *
 * POST-CONDITIONS
 * returned array index
 ********************************************************************/
    int GetIndex(string name) const;

/********************************************************************
 * Method PrintReceipt: class ManageInventory
 * ------------------------------------------------------------------
 * This method will take in a vector of the indexes of the items
 * and a vector of the quantity purchased and print a receipt of all
 * the transactions to the console
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * existing manageInventory object
 *
 * POST-CONDITIONS
 * printed receipt to console
 ********************************************************************/
    void PrintReceipt(vector<int>* index, vector<int>* numBought) const;

/********************************************************************
 * Method PrintInventory: class ManageInventory
 * ------------------------------------------------------------------
 * This method will print the inventory and items in stock in table
 * to the console
 * ------------------------------------------------------------------
 * PRE-CONDITIONS
 * existing manageInventory object
 *
 * POST-CONDITIONS
 * printed inventory
 ********************************************************************/
    void PrintInventory() const;

};



#endif //HW7EC_MANAGEINVENTORY_H