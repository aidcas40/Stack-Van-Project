#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
private:
    string itemID, itemName;
    double itemWeight;

public:
    Item(string id, string iname, double iweight) : itemID(id), itemName(iname), itemWeight(iweight)
    {
    }

    //--------------------------------------------------------------

    string getID()
    {
        return itemID;
    }
    string getName() // get item name
    {
        return itemName;
    }

    double getWeight() // get item weight
    {
        return itemWeight;
    }

    //--------------------------------------------------------------

    void displayItem()
    {
        cout << "ID: " << itemID;
        cout << " Name: " << itemName;
        cout << ", Weight:" << itemWeight << endl;
    }

}; // end class Item

class ClassItemArray
{
private:
    vector<Item *> v;
    int numItems;

public:
    ClassItemArray(int max) : numItems(0) // constructor
    {
        v.resize(max);
    } // create the array

    int getnumItems()
    {
        return numItems;
    }
    // Getting the name
    string returnID(int pos)
    {
        string ID;
        ID = v[pos]->getID();
        return ID;
    }
    string returnName(int pos)
    {
        string name;
        name = v[pos]->getName();
        return name;
    }
    double returnWeight(int pos)
    {
        double weight;
        weight = v[pos]->getWeight();
        return weight;
    }
    //--------------------------------------------------------------
    void insert(string itemID, string itemName, double itemWeight)
    {
        v[numItems] = new Item(itemID, itemName, itemWeight);
        numItems++; // increment size
    }

    //--------------------------------------------------------------
    // Quick Sort
    void swap(int pos1, int pos2)
    {
        Item *temp;
        temp = v[pos1];
        v[pos1] = v[pos2];
        v[pos2] = temp;
    }

    int Partition(int low, int high, Item *pivot)
    {
        int j = low;
        int i = low;
        while (i <= high)
        {
            if (v[i]->getWeight() < pivot->getWeight()) // orginal: (v[i]->getWeight() > pivot->getWeight()), change to < for descending order
            {
                i++;
            }
            else
            {
                swap(i, j);
                i++;
                j++;
            }
        }
        return j - 1;
    }

    void Quicksort(int low, int high)
    {
        if (low < high)
        {
            Item *pivot = v[high];
            int pos = Partition(low, high, pivot);
            Quicksort(low, pos - 1);
            Quicksort(pos + 1, high);
        }
    }

    //-------------------------------------------------------------
    void displayClassItems() // displays array contents
    {
        for (int j = 0; j < numItems; j++) // for each element,
            v[j]->displayItem();           // display it
    }

    //-------------------------------------------------------------
    double capTotalCalc()
    {
        double capTotal = 0;
        for (int j = 0; j < numItems; j++) // for each item
        {
            capTotal += v[j]->getWeight(); // calculate total weight by using getWeight()
        }
        return capTotal;
    }

    //--------------------------------------------------------------
    void menu() // displays menu options
    {
        cout << "Menu: " << endl;
        cout << "1. Load Items" << endl;
        cout << "2. Unload Items" << endl;
        cout << "3. Show All Items" << endl;
        cout << "4. Exit" << endl;
        cout << "//--------------------------------------------------------------//\n";
    }
};

class VanStack
{
private:
    int capacity;            // size of stack vector
    vector<Item *> stackVan; // stack vector
    int top;

public:
    VanStack(int c) : capacity(c), top(-1) // constructor
    {
        stackVan.reserve(capacity); // size the vector
    }
    
    //--------------------------------------------------------------
    void push(string itemIDVan, string itemNameVan, double itemWeightVan) // put item on top
    {
        stackVan[++top] = new Item(itemIDVan, itemNameVan, itemWeightVan); // increment top
        cout << stackVan[top]->getName() << " has been loaded to the van." << endl;
    } // insert item

    Item *pop() // take item from top
    {
        cout << stackVan[top]->getName() << " has been unloaded from the van." << endl; 
        return stackVan[top--];                                                         
    }                                                                                   
    string popID()
    {
        return stackVan[top]->getID();
    }
    string popName()
    {
        return stackVan[top]->getName();
    }
    double popWeight()
    {
        return stackVan[top]->getWeight();
    }
    //--------------------------------------------------------------
    void peek() // peek at top of stack
    {
        return stackVan[top]->displayItem();
    }
    string peekID()
    {
        return stackVan[top]->getID();
    }
    //--------------------------------------------------------------
    bool isEmpty() // true if stack is empty
    {
        return (top == -1);
    }
    //--------------------------------------------------------------
    bool isFull() // true if stack is full
    {
        return (top == capacity - 1);
    }

    //--------------------------------------------------------------
    void displayStackVan() // display items in the stack
    {
        if (top >= 0)
        {
            cout << "~Items Loaded~" << endl;
            for (int i = top; i >= 0; i--)  // for each item
                stackVan[i]->displayItem(); // display it
            cout << endl;
        }
    }
}; // end class VanStack

class UnloadStack
{
private:
    int capacity;
    vector<Item *> stackUn;
    int top;

public:
    UnloadStack(int c) : capacity(c), top(-1) // constructor
    {
        stackUn.reserve(capacity); // size the vector
    }
    void push(string idUnload, string nameUnload, double weightUnload) // put item on top
    {
        stackUn[++top] = new Item(idUnload, nameUnload, weightUnload); // increment top
        // cout << stackUn[top]->getName() << " has been added to the van." << endl;
    } // insert item
    Item *pop()
    {
        return stackUn[top--];
    }
    string popID()
    {
        return stackUn[top]->getID();
    }
    string popName()
    {
        return stackUn[top]->getName();
    }
    double popWeight()
    {
        return stackUn[top]->getWeight();
    }
    void peek() // peek at top of stack
    {
        return stackUn[top]->displayItem();
    }

    //--------------------------------------------------------------
    bool isEmpty() // true if stack is empty
    {
        return (top == -1);
    }
    //--------------------------------------------------------------
    bool isFull() // true if stack is full
    {
        return (top == capacity - 1);
    }

    //--------------------------------------------------------------
    void displayUnload() // display items in the stack
    {
        if (top >= 0)
        {
            cout << "~Items Unloaded~" << endl;
            for (int i = top; i >= 0; i--) // for each item
            {
                stackUn[i]->displayItem(); // display it
            }
            cout << endl;
        }
    }
};

int main()
{
    int maxSize = 100;           // array size
    ClassItemArray arr(maxSize); // array
    VanStack van(maxSize);
    UnloadStack unload(maxSize);
    char choice;
    string itemID, itemName;
    double itemWeight, TotalCapacity;
    double capacity;
    int numItems;

    // Hardcoding 5 items
    arr.insert("3203", "Cabinet", 70);
    arr.insert("2145", "Shelf", 50);
    arr.insert("6952", "Fridge", 240);
    arr.insert("2014", "Computer", 10);
    arr.insert("1025", "Stove", 280);

    // Sorting before entering into array.
    numItems = arr.getnumItems();
    arr.Quicksort(0, numItems - 1);

    // Inserting the items into stack.
    for (int j = 0; j < arr.getnumItems(); j++)
    {
        TotalCapacity = arr.capTotalCalc();
        van.push(arr.returnID(j), arr.returnName(j), arr.returnWeight(j));
    }

    cout << "//--------------------------------------------------------------//\n";
    cout << "Van Currently Holds: " << TotalCapacity << endl;
    cout << "Enter van's maximum storage capacity: ";
    cin >> capacity;
    while (capacity <= TotalCapacity)
    { // Making sure user inputs weight higher than the hardcoded items.
        cout << "Warning: Weight must be higher than " << TotalCapacity << "!" << endl;
        cout << endl;
        cout << "Enter van's maximum storage capacity: ";
        cin >> capacity;
    }

    cout << "//--------------------------------------------------------------//\n";

    arr.menu();
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != '4')
    {
        switch (choice)
        {
        case '1':
        {
            if (!van.isFull())
            {
                cout << endl;
                char yn;
                cout << "Loading Item onto Van? [Y|N] : ";
                cin >> yn;
                if (yn == 'Y' || yn == 'y')
                {
                    do
                    {
                        cout << "Enter the Item's ID: ";
                        cin >> itemID;
                        // Checking if the ID is unique
                        for (int i = 0; i < arr.getnumItems(); i++)
                        {
                            string check;
                            check = arr.returnID(i);
                            if (itemID == check)
                            {
                                cout << "Warning: ID is already in us!" << endl;
                                cout << endl;
                                cout << "Enter the Item's ID: ";
                                cin >> itemID;
                            }
                        }
                        cout << "Enter the Item's Name: ";
                        cin >> itemName;
                        cout << "Enter the Item's Weight: ";
                        cin >> itemWeight;

                        TotalCapacity = arr.capTotalCalc();
                        if ((TotalCapacity + itemWeight > capacity) || ((itemWeight > capacity)))
                        {
                            cout << endl;
                            cout << "Warning: Item wasn't added as total capacity will be exceeded!" << endl;

                            cout << "Remaing Space: " << capacity - TotalCapacity << endl;
                            cout << endl;
                        }
                        else if (TotalCapacity <= capacity)
                        {
                            arr.insert(itemID, itemName, itemWeight);
                        }
                        cout << endl;
                        cout << "Continue Loading Items onto Van? [Y|N] : ";
                        cin >> yn;
                    } while (yn == 'Y' || yn == 'y');
                }
                else
                {
                    cout << "//--------------------------------------------------------------//\n";
                    break;
                }

                cout << "//--------------------------------------------------------------//\n";

                // Sorting Items before Entering them into Van.
                cout << "~Items Sorted Via Weigth~" << endl;
                numItems = arr.getnumItems();
                arr.Quicksort(0, numItems - 1);
                arr.displayClassItems();
                cout << endl;

                while (!van.isEmpty())
                {
                    van.pop();
                }
                cout << "//--------------------------------------------------------------//\n";
                // Entering Items onto van.
                cout << "Loading All Items onto Van!" << endl;
                string vanItemID, vanItemName;
                double vanItemWeight;

                for (int j = 0; j < arr.getnumItems(); j++)
                {
                    vanItemID = arr.returnID(j);
                    vanItemName = arr.returnName(j);
                    vanItemWeight = arr.returnWeight(j);
                    van.push(vanItemID, vanItemName, vanItemWeight);
                }
                cout << endl;
                van.displayStackVan();

                cout << "//--------------------------------------------------------------//\n";
            }
            else
            {
                cout << "Warning: Van is Full!" << endl;
                cout << "//--------------------------------------------------------------//\n";
            }

            break;
        }
        case '2':
        {
            cout << endl;
            if (!van.isEmpty())
            {
                string popID, popName;
                double popWeight;
                int choice;
                cout << "~Unloading Item~\n"
                        "1. Via Search\n"
                        "2. Via Pop\n"
                        "Enter Option: ";
                cin >> choice;
                cout << "//--------------------------------------------------------------//\n";

                cout << endl;
                if (choice == 1)
                {
                    string rem;
                    cout << "Search Item ID: ";
                    cin >> rem;
                    cout << "//--------------------------------------------------------------//\n";

                    do
                    {
                        cout << endl;
                        cout << "Item is not ontop!" << endl;
                        cout << "Unloading Items..." << endl;
                        // Getting the name & weigth of the item thats about to be popped.
                        popID = van.popID();
                        popName = van.popName();
                        popWeight = van.popWeight();
                        van.pop();

                        unload.push(popID, popName, popWeight);
                    } while (rem != van.peekID());

                    // Popping the item at the top since its the one being searched for.
                    cout << "//--------------------------------------------------------------//\n";
                    cout << "Found Item!" << endl;
                    van.pop();
                    cout << "//--------------------------------------------------------------//\n";

                    cout << "Loading Items..." << endl;
                    do
                    { // Inserting everything back onto the van.
                        popID = unload.popID();
                        popName = unload.popName();
                        popWeight = unload.popWeight();
                        unload.pop();

                        van.push(popID, popName, popWeight);

                    } while (!unload.isEmpty()); // Doing this while there are items in the unload stack.
                    cout << "//--------------------------------------------------------------//\n";
                }
                else
                {
                    char ask;
                    cout << "Peek before Popping? [Y|N] : ";
                    cin >> ask;
                    if (ask == 'Y' || ask == 'y')
                    { // Asking the user to confirm if they want to check the top before popping.
                        char yn;
                        van.peek();
                        cout << endl;
                        cout << "Still Pop It? [Y|N] : ";
                        cin >> yn;
                        if (yn == 'Y' || yn == 'y')
                        {
                            van.pop();
                            cout << endl;
                        }
                    }
                    else
                    { // Popping since they don't want to know.
                        van.pop();
                    }

                    cout << "//--------------------------------------------------------------//\n";
                }
            }
            else
            {
                cout << "Warning: Van is Empty!" << endl;
                cout << "//--------------------------------------------------------------//\n";
            }

            break;
        }
        case '3':
        {
            cout << endl;
            if (!van.isEmpty())
            {
                // Displaying the stack
                van.displayStackVan();
            }
            else
            {
                cout << "Warning: Van is Empty!" << endl;
                cout << "//--------------------------------------------------------------//\n";
            }
            break;
        }
        default:
        {
            cout << endl;
            cout << "Warning: Invalid choice!" << endl;
            break;
        }
        }
        arr.menu();
        cout << "Enter your choice: ";
        cin >> choice;
    }
    cout << endl;
    cout << "Thanks for Using Stack Van Project!";
    return 0;
}
