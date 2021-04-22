#include <iostream>
#include <iomanip>
#include "QTModules_Mykytenko.h"
#include <map>
#include <list>

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
    while(z < 0)
    {
        std::cout << "Помилка: неправильно введене число Z." << std::endl << "Введiть Z: " << std::endl;
        std::cin >> z;
    }
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

void decForm(double x, double y, double z)
{
    cout << "X, Y та Z в десятковiй системi числення:" << endl;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl << endl;
}

void hexConverter(int number)
{
    list<int> numberK;

    std::string numberKStr;
    std::map< int, char > numberDic;
    for ( char i = '0'; i <= '9'; ++i )
    {
        numberDic[ i - '0' ] = i;
    }
    for ( char i = 'A'; i <= 'Z'; ++i )
    {
        numberDic[ i - 'A' + 10 ] = i;
    }
    int k = 16;
    long hexNumber = number;
    while ( true )
    {
        numberK.push_front( hexNumber % k );
        if ( hexNumber < k )
            break;
        hexNumber /= k;
    }
    for ( list<int>::iterator i = numberK.begin(); i != numberK.end(); ++i )
    {
        numberKStr += numberDic[ *i ];
    }

    std::cout << number <<" у шiстнадцятковiй системi: " << numberKStr << std::endl;
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

    //s_calculation result
    double S = s_calculation(y, z);
    cout << "S = " << S << endl;

    // second demand
    booleanExpression(a, b);

    // third demand
    decForm(x, y, z);
    hexConverter(x);
    hexConverter(y);
    hexConverter(z);
    cout << endl;

    system("pause");
}
