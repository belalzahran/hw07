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


 void ManageInventory::ItemPurchase(string name, int quantity)
{
    int i = 0;
    bool found = false;
    while(i < count && !found)
    {
        if(p__pInventoryItems[i]->name == name)
        {
            if (p__pInventoryItems[i]->quantity >= quantity)
            {
                cout << quantity << " " << name << " have been bought.\n";
                p__pInventoryItems[i]->quantity -= quantity;
                found = true;
            }
            else
            {
                cout << "Not enough " << name << " are in stock for your purchase.\n";
                found = true;
            }

        }
        else
        {
            i++;
        }
    }
}


int ManageInventory::GetIndex(string name) const
{
    int index = 0;
    bool found = false;
    while(index < count && !found)
    {
        if(p__pInventoryItems[index]->name == name)
        {
            found = true;
        }
        else
        {
            index++;
        }
    }

    if(found)
    {
        return index;
    }
    else
    {
        return -1;
    }
}
void ManageInventory::Shop()
{
    string receipt;
    string product;
    int numberOfProduct;
    vector<int> index;
    vector<int> numBought;

    receipt += "RECEIPT:\n\n";

    cout << "What would you like to buy(Enter 0 to exit): ";
    getline(cin, product);

    while (product != "0")
    {
        cout << "How many " << product << " would you like to buy: ";
        cin >> numberOfProduct;
        cin.ignore(1000,'\n');

        if(GetIndex(product) != -1)
        {
            ItemPurchase(product, numberOfProduct);
            index.push_back(GetIndex(product));
            numBought.push_back(numberOfProduct);
        }
        else
        {
            cout << "Sorry, item was NOT found!\n";
        }

        cout << "What would you like to buy(Enter 0 to exit): ";
        getline(cin, product);
    }

    PrintReceipt(index, numBought);

}


// method to print out inventory
void ManageInventory::PrintInventory() const
{
    cout << left << endl << endl;

    cout << "INVENTORY:\n";
    cout << "Item                    # left    Price\n";
    cout <<"------------------------ -------  -------\n";
    // loop through list
    for (int i = 0; i < count; i++)
    {
        // output values
        cout << setw(28) << p__pInventoryItems[i]->name;
        cout << setw(6) << p__pInventoryItems[i]->quantity;
        cout << "$" << p__pInventoryItems[i]->cost << endl;
    }

    cout << right << endl << endl;
}


void ManageInventory::PrintReceipt(vector<int> index, vector<int> numBought) const
{
    float totalItemCost;
    float totalCost = 0;
    float tax;
    float afterTax;

    cout << endl << endl << setprecision(2) << fixed;

    for (int i = 0; i < index.size(); i++)
    {
        totalItemCost = p__pInventoryItems[index.at(i)]->cost * numBought.at(i);

        cout << left << numBought.at(i) << " " << setw(26) << setfill('.') << p__pInventoryItems[index.at(i)]->name << "$" << totalItemCost << endl;
        totalCost += totalItemCost;
    };

    tax = totalCost * 0.0825;
    afterTax = totalCost + tax;

    cout << setw(15) << setfill('.') << "\nTotal" << "$" << totalCost;
    cout << setw(15) << setfill('.') <<"\nTax" << "$" << tax;
    cout << setw(15) << setfill('.') << "\nFinal" << "$" << afterTax;

    cout << "\n\nThank you for shopping with us!";

    cout << setprecision(6) << right << setfill(' ');
    cout.unsetf(ios::fixed);
}