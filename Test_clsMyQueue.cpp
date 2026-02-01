#include <iostream>
#include "clsMyQueue.h"

using namespace std;

int main()
{
    clsMyQueue<int> Queue;

    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);

    cout << "\nQueue: \n";
    Queue.Print();

    cout << "\nQueue Size: ";
    cout << Queue.Size();

    cout << "\nQueue Front: ";
    cout << Queue.front();

    cout << "\nQueue Back: ";
    cout << Queue.back();

    Queue.pop();

    cout << "\n\nQueue After pop(): \n";
    Queue.Print();

    // Extension #1
    cout << "\n\nItem(2) : " << Queue.GetItem(2) << endl;

    // Extension #2
    Queue.Reverse();
    cout << "\n\nQueue Reversing : \n";
    Queue.Print();

    // Extension #3
    Queue.UpdateItem(2, 600);
    cout << "\n\nQueue after updating item(2) to 600\n";
    Queue.Print();

    // Extension #4
    Queue.InsertAfter(2, 800);
    cout << "\n\nQueue after Inserting 800 after item(2)\n";
    Queue.Print();

    // Extension #5
    Queue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front\n";
    Queue.Print();

    // Extension #6
    Queue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at Back\n";
    Queue.Print();

    // Extension #7
    Queue.Clear();
    cout << "\n\nQueue after Clear() : \n";
    Queue.Print();

    return 0;
}