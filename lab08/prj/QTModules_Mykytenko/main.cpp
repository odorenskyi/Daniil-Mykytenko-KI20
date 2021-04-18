#include <iostream>
#include <iomanip>
#include "QTModules_Mykytenko.h"

using namespace std;

double inputX()
{
    double x;
    cout << "Введiть Х: " << endl;
    cin >> x;
    return x;
}
double inputY()
{
    double y;
    cout << "Введiть Y: " << endl;
    cin >> y;
    return y;
}

double inputZ()
{
    double z;
    cout << "Введiть Z: " << endl;
    cin >> z;
    return z;
}

char inputA()
{
    char a;
    cout << "Введiть символ A: " << endl;
    cin >> a;
    return a;
}

char inputB()
{
    char b;
    cout << "Введiть символ B: " << endl;
    cin >> b;
    return b;
}

void booleanExpression(char a, char b)
{
    bool expression = a + 1 < b;
    string expressionResult;
    if (expression == true)
        expressionResult = "вiрним";
    else
        expressionResult = "хибним";
    cout << endl << expression << endl << "Вираз \"a + 1 < b\" є " << boolalpha << expressionResult << endl << endl;
}

void hexDecTransfer(double x, double y, double z)
{
    cout << "X, Y та Z в десятковiй системi числення:" << endl;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl << endl;

    cout << "В шiстнадцятковiй системi: " << endl;
    cout << "X = " << hex << x << endl;
    cout << "Y = " << hex << y << endl;
    cout << "Z = " << hex << z << endl << endl;
}

int main()
{
    localisation();
    AR(); // first demand


    double x, y, z;
    char a, b;
    x = inputX();
    y = inputY();
    z = inputZ();
    a = inputA();
    b = inputB();

    // second demand
    booleanExpression(a, b);

    // third demand
    hexDecTransfer(x, y, z);

    double s = s_calculation(y, z);
    cout << "S = " << s << endl;

    system("pause");
}
