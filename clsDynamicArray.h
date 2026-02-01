#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:
    int _Size;
    T *_TempArray;

public:
    T *OriginalArray = nullptr;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            _Size = 0;

        _Size = Size;
        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray()
    {
        delete[] OriginalArray;
    }

    void SetItem(int Index, T Value)
    {
        if (Index < 0 || Index >= _Size)
        {
            return;
        }

        OriginalArray[Index] = Value;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return _Size == 0;
    }

    void PrintList()
    {
        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }
        cout << "\n";
    }

    void Resize(int NewSize)
    {
        if (NewSize < 0)
        {
            NewSize = 0;
        }

        _TempArray = new T[NewSize];

        if (NewSize < _Size)
        {
            _Size = NewSize;
        }

        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }

    void Reverse()
    {
        _TempArray = new T[_Size];

        for (int i = 0; i < _Size; i++)
        {
            _TempArray[_Size - 1 - i] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    void Clear()
    {
        _Size = 0;
        _TempArray = new T[_Size];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    void DeleteItemAt(int Index)
    {
        if (Index < 0 || Index >= _Size)
        {
            return;
        }

        _Size--;
        _TempArray = new T[_Size];
        // Copy array elements before index
        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        // Skip the index and copy the elements after it
        for (int i = Index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    void DeleteFirstItem()
    {
        // Will skip the first while loop before the Idex as the condition will not be true
        DeleteItemAt(0);
    }

    void DeleteLastItem()
    {
        // Will skip the Second while loop After the Idex as the condition will not be true
        DeleteItemAt(_Size - 1);
    }

    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
            {
                return i;
            }
        }
        return -1;
    }

    void DeleteItem(T Value)
    {
        int Index = Find(Value);
        if (Index == -1)
        {
            return;
        }
        DeleteItemAt(Index);
    }

    bool InsertAt(int Index, T Value)
    {
        if (Index < 0 || Index > _Size)
        {
            return false;
        }

        _TempArray = new T[_Size + 1];
        int i = 0;
        for (i; i < Index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[i] = Value;

        for (i = Index; i < _Size; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }

        _Size++;
        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;
    }

    bool InsertAtBeginning(T Value)
    {
        return InsertAt(0, Value);
    }

    bool InsertBefore(int Index, T Value)
    {
        if (Index < 0)
            return InsertAt(0, Value);
        else
            return InsertAt(Index - 1, Value);
    }

    bool InsertAfter(int Index, T Value)
    {
        if (Index > _Size)
            return InsertAt(_Size, Value);
        else
            return InsertAt(Index + 1, Value);
    }

    bool InsertAtEnd(T Value)
    {
        return InsertAt(_Size, Value);
    }
};