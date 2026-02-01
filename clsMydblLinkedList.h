#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsdblLinkedList
{
public:
    class Node
    {
    public:
        T Value;
        Node *Prev;
        Node *Next;
    };

protected:
    Node *_HEAD = nullptr;
    int _Size = 0;

public:
    void InsertAtBeginning(T value)
    {
        Node *NewNode = new Node();
        NewNode->Value = value;
        NewNode->Prev = nullptr;
        NewNode->Next = _HEAD;
        if (_HEAD != nullptr)
        {
            _HEAD->Prev = NewNode;
        }
        _HEAD = NewNode;
        _Size++;
    }

    void PrintList()
    {
        Node *TempHEAD = _HEAD;
        while (TempHEAD != nullptr)
        {
            cout << TempHEAD->Value << " ";
            TempHEAD = TempHEAD->Next;
        }
        cout << "\n";
    }

    Node *Find(T value)
    {
        Node *TempHEAD = _HEAD;
        while (TempHEAD != nullptr)
        {
            if (TempHEAD->Value == value)
            {
                return TempHEAD;
            }
            TempHEAD = TempHEAD->Next;
        }
        return nullptr;
    }

    void InsertAfter(Node *Current, T value)
    {
        if (Current == nullptr)
        {
            return;
        }

        Node *NewNode = new Node();
        NewNode->Value = value;
        NewNode->Next = Current->Next;
        NewNode->Prev = Current;

        if (Current->Next != nullptr)
        {
            Current->Next->Prev = NewNode;
        }

        Current->Next = NewNode;
        _Size++;
    }

    void InsertAtEnd(T value)
    {
        Node *NewNode = new Node();
        NewNode->Value = value;
        NewNode->Next = nullptr;

        if (_HEAD == nullptr)
        {
            NewNode->Prev = nullptr;
            _HEAD = NewNode;
            _Size++;
            return;
        }

        Node *LastNode = _HEAD;
        while (LastNode->Next != nullptr)
        {
            LastNode = LastNode->Next;
        }
        LastNode->Next = NewNode;
        NewNode->Prev = LastNode;
        _Size++;
    }

    void DeleteNode(Node *&NodeToDelete)
    {
        if (_HEAD == nullptr || NodeToDelete == nullptr)
        {
            return;
        }

        if (_HEAD == NodeToDelete)
        {
            _HEAD = _HEAD->Next;
        }

        if (NodeToDelete->Prev != nullptr)
        {
            NodeToDelete->Prev->Next = NodeToDelete->Next;
        }

        if (NodeToDelete->Next != nullptr)
        {
            NodeToDelete->Next->Prev = NodeToDelete->Prev;
        }

        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (_HEAD == nullptr)
        {
            return;
        }

        Node *NodeToDelete = _HEAD;
        _HEAD = _HEAD->Next;
        if (_HEAD != nullptr)
        {
            _HEAD->Prev = nullptr;
        }

        delete NodeToDelete;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (_HEAD == nullptr)
        {
            return;
        }

        if (_HEAD->Next == nullptr)
        {
            delete _HEAD;
            _HEAD = nullptr;
            _Size--;
            return;
        }

        Node *NewLastNode = _HEAD;
        while (NewLastNode->Next->Next != nullptr)
        {
            NewLastNode = NewLastNode->Next;
        }
        Node *Temp = NewLastNode->Next;
        NewLastNode->Next = nullptr;
        delete Temp;
        _Size--;
    }

    int Size() const
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_HEAD == nullptr);
    }

    void Clear()
    {
        while (_HEAD != nullptr)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node *Current = _HEAD;
        Node *Temp = nullptr;
        while (Current != nullptr)
        {
            Temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = Temp;

            Current = Current->Prev;
        }

        if (Temp != nullptr)
        {
            _HEAD = Temp->Prev;
        }
    }

    Node *GetNode(short Index)
    {
        if (Index > _Size - 1 || Index < 0)
        {
            return nullptr;
        }

        short counter = 0;
        Node *TempHead = _HEAD;
        while (TempHead != nullptr)
        {
            if (counter == Index)
            {
                return TempHead;
            }
            TempHead = TempHead->Next;
            counter++;
        }
        return nullptr;
    }

    T GetItem(short Index)
    {
        Node *ItemNode = GetNode(Index);

        if (ItemNode == nullptr)
            return T();
        else
            return ItemNode->Value;
    }

    bool UpdateItem(short Index, T NewValue)
    {
        Node *ItemNode = GetNode(Index);
        if (ItemNode != nullptr)
        {
            ItemNode->Value = NewValue;
            return true;
        }
        else
            return false;
    }

    bool InsertAfter(short Index, T value)
    {
        Node *ItemNode = GetNode(Index);
        if (ItemNode != nullptr)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
            
        else
            return false;
    }
};