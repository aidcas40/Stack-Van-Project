#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GroceryItem

{
    private:
        string groceryName;
        double price;

    public:
//--------------------------------------------------------------
        GroceryItem(string gname, double p) :                       //constructor
            groceryName(gname), price(p)                            
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

    { return groceryName; }
    
    double getPrice()                                               //get grocery price

    { return price; }

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
    double groceryCalc()
    {
        double total = 0;
        for(int j = 0; j <= top; j++)                               //for each item
        {
            total += stackVect[j]->getPrice();                      //calculate total price by using getPrice()
        }
        return total;
    }
//--------------------------------------------------------------
    void menu()                                                     //displays menu options
    {                                                         
        cout << "Menu: " << endl;
        cout << "1. Insert a grocery item" << endl;
        cout << "2. Delete a grocery item" << endl;
        cout << "3. Peek for the grocery item at the top" << endl;
        cout << "4. Display all grocery items in the stack" << endl;
        cout << "5. Checkout for the total" << endl;
        cout << "6. Exit the program" << endl;
        cout << endl;
    }
};                                                                  //end class StackX
    
int main()
{
    int choice;
    string gname;
    GroceryItem* item;
    double price;
    double totalPrice;
    
    int numItems;                                                   //stores number of items to be inputted in the stack
    cout << "Enter the number of grocery items that you wish to insert: ";
    cin >> numItems;                                                //receives input for number of items
    
    StackX theStack(numItems);                                      //Stack created with numItems determining the size
    
    cout << endl;
    theStack.menu();                                                //displays menu
    cout << "Enter your choice: ";
    cin >> choice;                                                  //receives input for choice
    
    while(choice != 6)
    {
        switch (choice) 
        {
            case 1:                                                 //case for inserting an item
                if(!theStack.isFull())
                {
                    cout << endl;
                    cout << "Enter the name of the grocery item: ";
                    cin >> gname;    
                    cout << "Enter the price of the grocery item: ";
                    cin >> price;
                    theStack.push(gname, price);                    //pushes grocery name and price into the stack
                    cout << endl;
                    break;
                }
                else
                    cout << "Can't insert anymore, the stack is FULL." << endl << endl;
                break;
            case 2:                                                 //case for deleting an item
                if(!theStack.isEmpty())
                {
                    theStack.pop();                                 //pops item from the stack
                    cout << endl;
                }
                else
                    cout << "The stack is EMPTY" << endl << endl;
                break;
            case 3:                                                 //case for peeking for the item at the top of the stack
                item = theStack.peek();
                cout<< endl;
                cout << "The item at the top of the groceries is: ";
                item->displayGrocery();                             //displays item at the top of the stacl
                cout << endl << endl;
                break;
            case 4:                                                 //case for displaying the stack
                cout << endl;
                theStack.displayStack();                            //displays all items in the stack
                cout << endl;
                break;
            case 5:                                                 //case for displaying the total price
                cout << "The total price for all the grocery items will be $" << theStack.groceryCalc() << endl;    //displays total price
                cout << endl;
                break;
            default:                                                
                cout << "Invalid choice!" << endl;
        }
        theStack.menu();                                            //displays menu
        cout << "Enter your choice: ";
        cin >> choice;
    }
    
    return 0;
}