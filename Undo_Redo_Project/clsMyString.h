#pragma once
#include <iostream>
#include <stack>

using namespace std;

class clsMyString
{
private:
    string _Value;
    stack<string> _Undo;
    stack<string> _Redo;

public:
    clsMyString()
    {
        _Value = " ";
        _Undo.push(_Value);
    }

    void Set_Value(const string &NewValue)
    {
        _Undo.push(_Value);
        _Value = NewValue;
    }

    string Get_Value() const
    {
        return _Value;
    }

    void Undo()
    {
        _Redo.push(_Value);
        if (!_Undo.empty())
        {
            _Value = _Undo.top();
            _Undo.pop();
        }
    }

    void Redo()
    {
        if (!_Redo.empty())
        {
            _Undo.push(_Value);
            _Value = _Redo.top();
            _Redo.pop();
        }
    }
};