#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
private:
    string itemName;
    double itemWeight;

public:
    Item(string iname, double iweight) : itemName(iname), itemWeight(iweight)
    {
    }

    //--------------------------------------------------------------

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
    //Getting the name
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
    void insert(string itemName, double itemWeight)
    {
        v[numItems] = new Item(itemName, itemWeight);
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
        cout << endl;
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
    void push(string itemNameVan, double itemWeightVan) // put item on top
    {
        stackVan[++top] = new Item(itemNameVan, itemWeightVan); // increment top
        cout << stackVan[top]->getName() << " has been added to the van." << endl;
    } // insert item

    Item *pop() // take item from top
    {
        cout << stackVan[top]->getName() << " has been removed from the van." << endl; // displays grocery item deleted from the top
        return stackVan[top--];                                                        // access item,
    }                                                                                  // decrement top
    //--------------------------------------------------------------
    void peek() // peek at top of stack
    {
        return stackVan[top]->displayItem();
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
                stackVan[i]->displayItem(); // display it, both the grocery name and price
            cout << endl;
        }
    }
}; // end class groceryItem

int main()
{

    
    int maxSize = 3;             // array size
    ClassItemArray arr(maxSize); // array
    VanStack van(maxSize);
    int choice;
    string itemName;
    double itemWeight;
    double capacity;
    int numItems;

    cout << "Enter van's maximum storage capacity: ";
    cin >> capacity;

    cout << endl;
    arr.menu();
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
        {
            char yn;
            cout << "Loading Item onto Van? [Y|N] : ";
            cin >> yn;
            
            do
            {
                cout << "Enter the item's name: ";
                cin >> itemName;
                cout << "Enter the item's weight: ";
                cin >> itemWeight;

                double TotalCapacity = arr.capTotalCalc();
                if ((TotalCapacity + itemWeight> capacity) || ((itemWeight > capacity)))
                {
                    cout << endl;
                    cout << "Previous item added exceeds the van's total capacity so it wasn't added!" << endl;
                    
                    cout << "Remaing Space: " << capacity - TotalCapacity << endl;
                    cout << endl;
                }
                else if (TotalCapacity <= capacity)
                {
                    arr.insert(itemName, itemWeight);
                }
                cout << "Continue Loading Items onto Van? [Y|N] : ";
                cin >> yn;
            }while(yn == 'Y');
            
            cout << endl;
            
            //Sorting Items before Entering them into Van.
            cout << "~Items Sorted Via Weigth~" << endl;
            numItems = arr.getnumItems();
            arr.Quicksort(0, numItems - 1);
            arr.displayClassItems();
            cout << endl;
            
            
            //Entering Items onto van.
            cout << "Loading All Items onto Van!" << endl;
            string vanItemName;
            double vanItemWeight;

            for (int j = 0; j < arr.getnumItems(); j++)
            {
                vanItemName = arr.returnName(j);
                vanItemWeight = arr.returnWeight(j);
                van.push(vanItemName, vanItemWeight);
            }
            cout << endl;
            van.displayStackVan();
            break;
        }
        case 2:
        {
            int choice;
            cout << "~Unloading Item~\n"
            "1. Via Search\n"
            "2. Via Pop\n"
            "Enter Option: ";
            cin >> choice;
            if(choice ==  1)
            {
                
            }
            else
            {
                char ask;
                cout << "Peek before Popping? [Y|N] : ";
                cin >> ask;
                if(ask == 'Y' || ask == 'y')
                {
                    char yn;
                    van.peek();
                    cout << endl;
                    cout << "Still Pop It? [Y|N] : ";
                    cin >> yn;
                    if(yn == 'Y' || yn == 'y')
                    {
                        van.pop();
                        cout << endl;
                    }
                    
                }
                
            }
            break;
        }
        case 3:
        {
            van.displayStackVan();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
        arr.menu();
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return 0;
}
