#include <iostream>
#include "QTModules_Mykytenko.h"

using namespace std;

int main()
{
    double y[10] = {2, 2, 3, 0, -1, 0, -200, -2, 1, 1.5};
    double z[10] = {3, 1, 3, 1, -1, 0, 200, 2, 1, 1.5};
    double s[10] = {64, 16, 81, 4, 9, 0, 40000, 4, 9, 20.25};

    for (int i = 0; i < 10; i++)
    {
        if (s_calculation(y[i], z[i]) == s[i])
            cout << "Test suite " << i + 1 << " is passed." << endl;
        else
            cout << "Test suite " << i + 1 << " is failed." << endl;
    }
    system("pause");
}
