#include <iostream>
#include<windows.h>
#include <locale.h>
#include <math.h>

using namespace std;

void localisation ()
{
    setlocale(LC_ALL,"");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int inputX()
{
    int x = 0;
    cout << "Ââåä³òü Õ: " << endl;
    cin >> x;
    return x;
}

int inputY()
{
    int y = 0;
    cout << "Ââåä³òü Ó: " << endl;
    cin >> y;
    return y;
}

int inputZ()
{
    int z = 0;
    cout << "Ââåä³òü Z: " << endl;
    cin >> z;
    return z;
}

void calculate(int z,int y,int x)
{
    int s = 0;
    s = pow(z + y + z, 2) - 2 * M_PI * sqrt(1/3 * z);
    cout << s;
}

int main()
{
    localisation();

    calculate(inputZ(), inputY(), inputX());

    return 0;
}
