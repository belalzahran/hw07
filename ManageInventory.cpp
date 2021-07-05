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
//    for (int i = 0; i < count; i++)
//    {
//        delete p__pInventoryItems[i];
//    }
    // deleting array
    delete [] p__pInventoryItems;
}


// copy constructor
ManageInventory::ManageInventory(const ManageInventory& invent)
{
    count = invent.count;
    size = invent.size;

    // creating new array of pointers to items
    p__pInventoryItems = new Item*[size];

    for (int i = 0; i < count; i++)
    {
        // adding in the contents of each item during iterations
        p__pInventoryItems[i] = invent.p__pInventoryItems[i];
    }


}





// method to add items to the array of items
void ManageInventory::addItem(string name, int quantity, float cost)
{
    // create new pointer
    Item *x = new Item{name, quantity, cost};
    // insert and increment count
    p__pInventoryItems[count++] = x;
}


 void ManageInventory::ItemPurchase(string name, int quantity)
{
    int i = 0;
    bool found = false;
    //loop through the array until the item is found or the count is reached
    while(i < count && !found)
    {
        if(p__pInventoryItems[i]->name == name)
        {

            if (p__pInventoryItems[i]->quantity >= quantity)
            {
                // if the item is found and there is enough of the item to fulfill the request then deduct
                cout << quantity << " " << name << " have been bought.\n";
                p__pInventoryItems[i]->quantity -= quantity;
            }
            else
            {
                // if there isnt enough print message
                cout << "Not enough " << name << " are in stock for your purchase.\n";
            }

            found = !found;
        }
        else
        {
            // increment loop variable
            i++;
        }
    }
}


int ManageInventory::GetIndex(string name) const
{
    int index = 0;
    bool found = false;
    // loop through the array to find the item with a matching name
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
        // if item is found return the index in the array
        return index;
    }
    else
    {
        // if item is not found return -1
        return -1;
    }
}
void ManageInventory::Shop()
{
    string product;        // IN & CALC & OUT - the name of the product being bought
    int numberOfProduct;   // IN & CALC & OUT - the number of the product being bought
    vector<int> *index = new vector<int>();     // CALC - vector of indexes
    vector<int> *numBought = new vector<int>(); // CALC - vector of quantities

    // prompt for name of product
    cout << "What would you like to buy(Enter 0 to exit): ";
    getline(cin, product);

    // user is not exiting SHOP run loop
    while (product != "0")
    {
        // prompt for quantity
        cout << "How many " << product << " would you like to buy: ";
        cin >> numberOfProduct;
        cin.ignore(1000,'\n');

        // if the item was found call itemPurchase and insert index and quantity into vectors
        if(GetIndex(product) != -1)
        {
            ItemPurchase(product, numberOfProduct);

            index->push_back(GetIndex(product));
            numBought->push_back(numberOfProduct);
        }
        else
        {
            // if getIndex returns negative one, item was not found and print the following msg
            cout << "Sorry, item was NOT found!\n";
        }

        // prompt user to change the loop variable
        cout << "What would you like to buy(Enter 0 to exit): ";
        getline(cin, product);
    }

    // print the receipt to the console
    PrintReceipt(index, numBought);
    delete index;
    delete numBought;

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


void ManageInventory::PrintReceipt(vector<int>* index, vector<int>* numBought) const
{
    float totalItemCost;
    float totalCost = 0;
    float tax;
    float afterTax;

    cout << endl << "RECEIPT: ";
    cout << endl << setprecision(2) << fixed;

    // loop through the vector
    for (int i = 0; i < index->size(); i++)
    {
        // calculate the cost by multiplying the quantity and the cost of one item
        totalItemCost = p__pInventoryItems[index->at(i)]->cost * numBought->at(i);

        // print the receipt line for the item
        cout << left << numBought->at(i) << " " << setw(26) << setfill('.') << p__pInventoryItems[index->at(i)]->name << "$" << totalItemCost << endl;
        cout << numBought->at(i) << " x $" << p__pInventoryItems[index->at(i)]->cost << endl;

        // add the cost to the total cost
        totalCost += totalItemCost;
    };

    // calculate tax
    tax = totalCost * 0.0825;

    // calculate final cost after tax
    afterTax = totalCost + tax;

    cout << setw(15) << setfill('.') << "\nTotal" << "$" << totalCost;
    cout << setw(15) << setfill('.') <<"\nTax" << "$" << tax;
    cout << setw(15) << setfill('.') << "\nFinal" << "$" << afterTax;

    cout << "\n\nThank you for shopping with us!";

    cout << setprecision(6) << right << setfill(' ');
    cout.unsetf(ios::fixed);
}