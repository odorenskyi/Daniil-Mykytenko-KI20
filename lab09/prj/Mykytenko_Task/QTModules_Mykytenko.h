#ifndef QTMODULES_MYKYTENKO_H
#define QTMODULES_MYKYTENKO_H

#include <Windows.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

void localisation()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
}

void AR()
{
    cout << "Daniyl Mykytenko, KI-20 student. CNTU 2021 (c)" << std::endl;

    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(497, 500);
    Sleep(500);
    Beep(497, 500);
    Beep(277, 500);
    Beep(277, 500);
    Beep(440, 500);
    Beep(440, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(329, 500);
    Beep(247, 500);
    Beep(417, 500);
    Beep(417, 500);
    Beep(370, 500);
    Beep(417, 500);
    Beep(329, 500);
}

double s_calculation(double y, double z)
{
    double s = pow(z + y + z, 2) - 2 * 3.141592653589793 * sqrt(1 / 3 * z);
    return s;
}

double inputY()
{
    int y;
    cout << "Введiть Y: ";
    cin >> y;
    return y;
}

double inputZ()
{
    int z;
    cout << "Введiть Z: ";
    cin >> z;
    return z;
}

void saleCost(float cost)
{
    int sale;
    if (cost < 1000)
        sale = 1;
    else
    {
        if (cost < 2000)
            sale = 5;
        else
        {
            if (cost < 3000)
                sale = 7;
            else
            {
                if (cost < 5000)
                    sale = 10;
                else
                {
                    if (cost < 10000)
                        sale = 15;
                    else
                        sale = 20;
                }
            }
        }
    }
    double saleSum = cost * sale / 100;
    cout << "Сума до сплати: " << cost - saleSum;
}
double inputCost()
{
    int cost;
    cout << "Введiть суму товару: ";
    cin >> cost;
    return cost;
}

void mensUnderwear(int size)
{
    int checkSize[6] = {6, 7, 8, 9, 10, 0};
    int gbSize[6] = {34, 36, 38, 40, 42, 44};
    int gerSize[6] = {0, 4, 5, 7, 8, 9};
    int frSize[6] = {2, 3, 4, 5, 6, 0};
    int uaSize[6] = {44, 46, 48, 50, 52, 54};

    string internationalSize[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};

    int index = 0;

    for(int i = 0; i < 6; i++)
    {
        if(size == uaSize[i])
            index = i;
    }

    cout << "В системi Францiї ваш розмiр: " << frSize[index] << endl;
    cout << "В системi Великобританiї ваш розмiр: " << gbSize[index] << endl;
    cout << "В мiжнароднiй системi ваш розмiр: " << internationalSize[index] << endl;
}

int sizeInput()
{
    int size;
    cout << "Введiть розмiр за українською системою: ";
    cin >> size;
    return size;
}

int binaryNumber(int num)
{
    int t=0, d = 1;
    while(num)
    {
        t += (num % 2)* d;
        num = num/2;
        d = d*10;
    }
    return t;
}

int binaryLength(int num)
{
    int t=0, d = 1, length = 0;
    while(num)
    {
        t += (num % 2)* d;
        num = num/2;
        d = d*10;
        length++;
    }
    return length;
}

void bitCalculator()
{
    int number;
    cout << "Введiть натуральне число вiд 0 до 80000: " << endl;
    cin >> number;
    int binNumber = binaryNumber(number);
    int length = binaryLength(number);

    int arr[length];

    int trueSum = 0;
    int falseSum = 0;
    for(int i = 0; binNumber != 0; i++)
    {
        arr[i] = binNumber % 10;
        if(binNumber % 10 == 1)
            trueSum++;
        else
            falseSum++;
        binNumber /= 10;
    }
    cout << "П'ятий бiт числа є " << arr[length - 4] << endl;
    if(arr[length-4] == 1)
        cout << "Кiлькiсть одиниць в числi: " << trueSum << endl;
    else
        cout << "Кiлькiсть нулiв в числi: " << falseSum << endl;
}

#endif // QTMODULES_MYKYTENKO_H
