
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
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
    void ItemPurchase(string name, int quantity);
    void Shop();
    int GetIndex(string name) const;
    void PrintReceipt(vector<int> index, vector<int> num) const;
};

string Round(float x);








#endif //HW7EC_MANAGEINVENTORY_H