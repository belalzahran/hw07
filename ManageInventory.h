
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef HW7EC_MANAGEINVENTORY_H
#define HW7EC_MANAGEINVENTORY_H



struct Item{
    string name;
    int quantity;
    float cost;
};

const int MAX_SIZE = 50;

class ManageInventory{
private:
    int size{MAX_SIZE};
    int count;
    Item ** p__pInventoryItems;
public:
    ManageInventory();
    ManageInventory(int size);
    ~ManageInventory();

    void addItem(string name, int quantity, float cost);
    void PrintInventory() const;
};








#endif //HW7EC_MANAGEINVENTORY_H