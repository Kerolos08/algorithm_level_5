#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
    clsDynamicArray<T> _MyArr;

public:
    void push(T Item)
    {
        _MyArr.InsertAtEnd(Item);
    }

    void pop()
    {
        _MyArr.DeleteFirstItem();
    }

    int Size()
    {
        return _MyArr.Size();
    }

    bool IsEmpty()
    {
        return _MyArr.IsEmpty();
    }

    T front()
    {
        return _MyArr.GetItem(0);
    }

    T back()
    {
        return _MyArr.GetItem(_MyArr.Size() - 1);
    }

    void Print()
    {
        _MyArr.PrintList();
    }

    T GetItem(int Index)
    {
        return _MyArr.GetItem(Index);
    }

    void Reverse()
    {
        _MyArr.Reverse();
    }

    void UpdateItem (int Index, T Value)
    {
        _MyArr.SetItem(Index, Value);
    }

    void InsertAfter (int Index, T Value)
    {
        _MyArr.InsertAfter(Index, Value);
    }

    void InsertAtFront (T Value)
    {
        _MyArr.InsertAtBeginning(Value);
    }

    void InsertAtBack (T Value)
    {
        _MyArr.InsertAtEnd(Value);
    }

    void Clear()
    {
        _MyArr.Clear();
    }
};