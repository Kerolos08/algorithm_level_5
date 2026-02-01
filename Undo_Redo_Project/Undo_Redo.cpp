#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
    cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

    clsMyString S1;

    cout << "\nS1  = " << S1.Get_Value() << "\n";
    S1.Set_Value("Kero");
    cout << "\nS1  = " << S1.Get_Value() << "\n";
    S1.Set_Value("Kero2");
    cout << "\nS1  = " << S1.Get_Value() << "\n";
    S1.Set_Value("Kero3");
    cout << "\nS1  = " << S1.Get_Value() << "\n";

    cout << "\n\nUndo: ";
    cout << "\n__________\n";

    S1.Undo();
    cout << "\nS1  after undo = " << S1.Get_Value() << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Get_Value() << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Get_Value() << "\n";

    cout << "\n\nRedo: ";
    cout << "\n__________\n";

    S1.Redo();
    cout << "\nS1  after Redo = " << S1.Get_Value() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Get_Value() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Get_Value() << "\n";

    return 0;
}