#include <iostream>
#include "clsMyStack.h"

using namespace std;

int main()
{
    clsMyStack<int> Stack;

    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.push(40);
    Stack.push(50);

    cout << "\nStack: \n";
    Stack.Print();

    cout << "\nStack Size: ";
    cout << Stack.Size();

    cout << "\nStack Top: ";
    cout << Stack.top();

    cout << "\nStack Bottom: ";
    cout << Stack.bottom();

    Stack.pop();

    cout << "\n\nStack After pop(): \n";
    Stack.Print();

    // Extension #1
    cout << "\n\nItem(2) : " << Stack.GetItem(2) << endl;

    // Extension #2
    Stack.Reverse();
    cout << "\nStack Reversing : \n";
    Stack.Print();

    // Extension #3
    Stack.UpdateItem(2, 600);
    cout << "\n\nStack after updating item(2) to 600\n";
    Stack.Print();

    // Extension #4
    Stack.InsertAfter(2, 800);
    cout << "\n\nStack after Inserting 800 after item(2)\n";
    Stack.Print();

    // Extension #5
    Stack.InsertAtFront(1000);
    cout << "\n\nStack after Inserting 1000 at Top\n";
    Stack.Print();

    // Extension #6
    Stack.InsertAtBack(2000);
    cout << "\n\nStack after Inserting 2000 at Bottom\n";
    Stack.Print();

    // Extension #7
    Stack.Clear();
    cout << "\n\nStack after Clear() : \n";
    Stack.Print();

    return 0;
}