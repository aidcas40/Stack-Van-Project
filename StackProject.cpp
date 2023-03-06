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
    void push(string itemNameVan, double itemWeightVan) // put item on top
    {
        stackVan[++top] = new Item(itemNameVan, itemWeightVan); // increment top
        cout << stackVan[top]->getName() << " has been loaded to the van." << endl;
    } // insert item

    Item *pop() // take item from top
    {
        cout << stackVan[top]->getName() << " has been unloaded from the van." << endl; // displays grocery item deleted from the top
        return stackVan[top--];                                                        // access item,
    }                                                                                  // decrement 
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
    string peekName()
    {
        return stackVan[top]->getName();
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
    void push(string nameUnload, double weightUnload) // put item on top
    {
        stackUn[++top] = new Item(nameUnload, weightUnload); // increment top
        //cout << stackUn[top]->getName() << " has been added to the van." << endl;
    } // insert item
    Item *pop()
    {
        return stackUn[top--];
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
            for (int i = top; i >= 0; i--)  // for each item
            {
                stackUn[i]->displayItem(); // display it, both the grocery name and price
            }
            cout << endl;
        }
    }
};

int main()
{
    int maxSize = 100;             // array size
    ClassItemArray arr(maxSize); // array
    VanStack van(maxSize);
    UnloadStack unload(maxSize);
    int choice;
    string itemName;
    double itemWeight;
    double capacity;
    int numItems;

    cout << "Enter van's maximum storage capacity: ";
    cin >> capacity;
    cout << "//--------------------------------------------------------------//\n";  

    arr.menu();
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
        {
            if(!van.isFull())
            {
                cout << endl;
                char yn;
                cout << "Loading Item onto Van? [Y|N] : ";
                cin >> yn;
                if(yn == 'Y' || yn == 'y')
                {
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
                    }while(yn == 'Y' || yn == 'y');
                }
                else
                {
                    cout << "//--------------------------------------------------------------//\n";  
                    break;
                }
                
                cout << "//--------------------------------------------------------------//\n";  
                
                //Sorting Items before Entering them into Van.
                cout << "~Items Sorted Via Weigth~" << endl;
                numItems = arr.getnumItems();
                arr.Quicksort(0, numItems - 1);
                arr.displayClassItems();
                cout << endl;
                
                /*if(!van.isEmpty())
                {
                    for(int i = 0; i <numItems; i++)
                    {
                        van.pop();
                    }
                }*/
                
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
                
                
                cout << "//--------------------------------------------------------------//\n"; 
            }
            else
            {
                cout << "Van is Full!" << endl;
                cout << "//--------------------------------------------------------------//\n"; 
            }
            
            break;
        }
        case 2:
        {
            cout << endl;
            if(!van.isEmpty() )
            {
                string popName;
                double popWeight;
                int choice;
                cout << "~Unloading Item~\n"
                "1. Via Search\n"
                "2. Via Pop\n"
                "Enter Option: ";
                cin >> choice;
                cout << "//--------------------------------------------------------------//\n"; 
                
                cout << endl;
                if(choice ==  1)
                {
                    string rem;
                    cout << "Search Item Name: ";
                    cin >> rem;
                    cout << "//--------------------------------------------------------------//\n"; 
                    
                    do
                    {
                        cout << endl;
                        cout << "Item is not ontop!" << endl;
                        cout << "Unloading Items..." << endl;
                        //Getting the name & weigth of the item thats about to be popped.
                        popName = van.popName();
                        popWeight = van.popWeight();
                        van.pop();
                    
                        unload.push(popName, popWeight);
                    }while(rem != van.peekName());
                    
                    //Popping the item at the top since its the one being searched for.
                    cout << "//--------------------------------------------------------------//\n";  
                    cout << "Found Item!" << endl;
                    van.pop();
                    cout << "//--------------------------------------------------------------//\n"; 
                      
                    cout << "Loading Items..." << endl;
                    do
                    {   //Inserting everything back onto the van.
                        popName = unload.popName();
                        popWeight = unload.popWeight();
                        unload.pop();
                        
                        van.push(popName, popWeight);
                        
                    }while(!unload.isEmpty());//Doing this while there are items in the unload stack.
                    cout << "//--------------------------------------------------------------//\n"; 
                }
                else
                {
                    char ask;
                    cout << "Peek before Popping? [Y|N] : ";
                    cin >> ask;
                    if(ask == 'Y' || ask == 'y')
                    {   //Asking the user to confirm if they want to check the top before popping.
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
                    else
                    {   //Popping since they don't want to know.
                        van.pop();
                    }
                    
                    cout << "//--------------------------------------------------------------//\n"; 
                }
            }
            else
            {
                cout << "Van is Empty!" << endl;
                cout << "//--------------------------------------------------------------//\n"; 
            }
    
            break;
        }
        case 3:
        {
            cout << endl;
            if(! van.isEmpty())
            {
                //Displaying the stack
                van.displayStackVan();
            }
            else
            {
                cout << "Van is Empty!" << endl;
                cout << "//--------------------------------------------------------------//\n"; 
            }
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
    cout << endl;
    cout << "Thanks for Using Stack Van Project!";
    return 0;
}
