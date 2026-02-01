#pragma once
#include <iostream>
#include "clsMydblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue
{
    protected:
    clsdblLinkedList <T> _MyList;
public:
    void push (T Item)
    {
        _MyList.InsertAtEnd(Item);
    }

    void pop ()
    {
        _MyList.DeleteFirstNode();
    }

    int Size ()
    {
        return _MyList.Size();
    }

    bool IsEmpty ()
    {
        return _MyList.IsEmpty();
    }

    T front ()
    {
        return _MyList.GetItem(0);
        
    }

    T back ()
    {
        return _MyList.GetItem(_MyList.Size() - 1);
    }

    void Print ()
    {
        _MyList.PrintList();
    }

    T GetItem (short Index)
    {
        return _MyList.GetItem(Index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    void UpdateItem (short Index, T value)
    {
        _MyList.UpdateItem(Index, value);
    }

    void InsertAfter (short Index, T value)
    {
        _MyList.InsertAfter(Index, value);
    }

    void InsertAtFront (T value)
    {
        _MyList.InsertAtBeginning(value);
    }

    void InsertAtBack (T value)
    {
        _MyList.InsertAtEnd(value);
    }

    void Clear ()
    {
        _MyList.Clear();
    }
};