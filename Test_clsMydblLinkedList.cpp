#include <iostream>
#include "clsMydblLinkedList.h"

using namespace std;

int main()
{
    clsdblLinkedList<int> DLinkedList;

    if (DLinkedList.IsEmpty())
    {
        cout << "\nList is empty!\n";
    }
    else
    {
        cout << "\nList is not empty.\n";
    }

    // Adding nodes
    DLinkedList.InsertAtBeginning(5);
    DLinkedList.InsertAtBeginning(4);
    DLinkedList.InsertAtBeginning(3);
    DLinkedList.InsertAtBeginning(2);
    DLinkedList.InsertAtBeginning(1);

    // Printing list
    cout << "\nLinked list content: ";
    DLinkedList.PrintList();

    int searchvalue = 3;
    clsdblLinkedList<int>::Node *N1 = DLinkedList.Find(searchvalue);

    if (N1 != nullptr)
    {
        cout << "\nNode with value " << searchvalue << " is found.\n";
    }
    else
    {
        cout << "\nNode is not found!\n";
    }

    DLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter inserting 500 after " << searchvalue << " :\n";
    DLinkedList.PrintList();

    DLinkedList.InsertAtEnd(600);
    cout << "\nAfter inserting 600 at the end" << " :\n";
    DLinkedList.PrintList();

    searchvalue = 4;
    clsdblLinkedList<int>::Node *N2 = DLinkedList.Find(searchvalue);
    DLinkedList.DeleteNode(N2);
    cout << "\nAfter deleting " << searchvalue << ":\n";
    DLinkedList.PrintList();

    DLinkedList.DeleteFirstNode();
    cout << "\nAfter delete first node :\n";
    DLinkedList.PrintList();

    DLinkedList.DeleteLastNode();
    cout << "\nAfter deleting last node :\n";
    DLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << DLinkedList.Size() << endl;

    if (DLinkedList.IsEmpty())
    {
        cout << "\nList is empty!\n";
    }
    else
    {
        cout << "\nList is not empty.\n";
    }

    // cout << "\nExecuting .Clear \n";
    // DLinkedList.Clear();

    // cout << "\nNumber of items in the linked list = " << DLinkedList.Size() << endl;

    if (DLinkedList.IsEmpty())
    {
        cout << "\nList is empty!\n";
    }
    else
    {
        cout << "\nList is not empty.\n";
    }

    // Printing list
    cout << "\nLinked list content: ";
    DLinkedList.PrintList();

    DLinkedList.Reverse();
    cout << "\nLinked list content after being reversed: \n";
    DLinkedList.PrintList();

    clsdblLinkedList<int>::Node *N;
    N = DLinkedList.GetNode(2);

    cout << "\nNode value is: " << N->Value << "\n";

    cout << "\nItem (2) Value is: " << DLinkedList.GetItem(2) << endl;

    DLinkedList.UpdateItem(2, 600);
    cout << "\nList after update: ";
    DLinkedList.PrintList();

    DLinkedList.InsertAfter(1, 600);
    cout << "\nPrinting the list after inserting a new node after index 1: \n";
    DLinkedList.PrintList();

    return 0;
}