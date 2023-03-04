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
    vector<Item*>v;
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

    //--------------------------------------------------------------
    void insert(string itemName, double itemWeight)
    {
        v[numItems] = new Item(itemName, itemWeight);
        numItems++; // increment size
    }

    //--------------------------------------------------------------
    // Selection Sort
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
            if (v[i]->getWeight() > pivot->getWeight())
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
            v[j]->displayItem();       // display it
    }

    //--------------------------------------------------------------
    void menu() // displays menu options
    {
        cout << "Menu: " << endl;
        cout << "1. Insert item" << endl;
        cout << "2. Sort Items" << endl;
        cout << "3. Exit" << endl;
        cout << endl;
    }
};

/*class VanStack
{
    private:
        string itemName;
        double itemWeight;

    public:
//--------------------------------------------------------------
        GroceryItem(string iname, double iweight) :                       //constructor
            itemName(iname), itemWeight(iweight)
            { }
//--------------------------------------------------------------
    void displayGrocery()                                           //function that displays the groceries items
    {
        cout<<"\n";
        cout << "Grocery Item: " << groceryName;                    //displays grocery name
        cout<<", ";
        cout << "Price: " << price;                                 //displays grocery price
    }
//--------------------------------------------------------------

    string getName()                                                //get grocery name
        {return groceryName;}

    double getPrice()                                               //get grocery price
        {return price;}

};                                                                  //end class groceryItem

class StackX
{
    private:
        int maxSize;                                                //size of stack vector
        vector<GroceryItem*> stackVect;                             //stack vector
        int top;                                                    //top of stack

    public:
//--------------------------------------------------------------
        StackX(int s) : maxSize(s), top(-1)                         //constructor
        {
            stackVect.reserve(maxSize);                             //size the vector
        }
//--------------------------------------------------------------
    void push(string name, double p)                                //put item on top
    {
        stackVect[++top] = new GroceryItem(name, p);                //increment top
        cout << stackVect[top]->getName() << " has been inserted into the stack." << endl;  //displays grocery item name inserted from the top
    }                                                               //insert item

    GroceryItem* pop()                                              //take item from top
    {
        cout << stackVect[top]->getName() << " has been deleted from the stack." << endl;   //displays grocery item deleted from the top
        return stackVect[top--];                                    //access item,
    }                                                               //decrement top
//--------------------------------------------------------------
    GroceryItem* peek()                                             //peek at top of stack
    {
        return stackVect[top];
    }
//--------------------------------------------------------------
    bool isEmpty()                                                  //true if stack is empty
    {
        return (top == -1);
    }
//--------------------------------------------------------------
    bool isFull()                                                   //true if stack is full
    {
        return (top == maxSize-1);
    }
//--------------------------------------------------------------
    void displayStack()                                             //display items in the stack
    {
        if(top >= 0)
        {
            cout << endl << "The grocery items are:";
            for(int i = top; i >= 0; i--)                           //for each item
                stackVect[i]->displayGrocery();                     //display it, both the grocery name and price
            cout<< endl;
        }
    }
//--------------------------------------------------------------
    void menu()                                                     //displays menu options
    {
        cout << "Menu: " << endl;
        cout << "1. Insert item into the van" << endl;
        cout << "2. Remove item from the van" << endl;
        cout << "3. Peek for the item at the top" << endl;
        cout << "4. Display items loaded into the van" << endl;
        cout << "5. Exit the program" << endl;
        cout << endl;
    }
};                                                                  //end class StackX*/

int main()
{
    int maxSize = 100; //array size
    ClassItemArray arr(maxSize); //array
    int choice;
    string itemName;
    double itemWeight;
    int numItems;

    arr.insert("Cabinet", 45.43);
    arr.insert("Lamp", 10.43);

    cout << endl;
    arr.menu();
    cout << "Enter your choice: ";
    cin >> choice;

     while(choice != 3)
    {
        switch (choice) 
                {
                    case 1:                                                 //case for inserting an element
                        cout << endl;
                        cout << "Enter the item's name: ";
                        cin >> itemName;
                        cout << "Enter the item's weight: ";
                        cin >> itemWeight;
                        arr.insert(itemName, itemWeight);                      
                        cout << endl;
                        arr.displayClassItems();                                          //displays the array
                        cout << endl;
                        break;                                                      
                    case 2:
                        cout << "Sorting by Weight" << endl << endl;
                        numItems = arr.getnumItems();
                        arr.Quicksort(0, numItems - 1);
                        arr.displayClassItems();
                        cout << endl;
                        break;
                    default:                                                
                        cout << "Invalid choice!" << endl;
                }
                arr.menu();
                cout << "Enter your choice: ";
                cin >> choice;
    }
    return 0;
}