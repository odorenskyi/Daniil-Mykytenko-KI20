#ifndef QTMODULES_MYKYTENKO_H
#define QTMODULES_MYKYTENKO_H

#include <Windows.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <iomanip>

using namespace std;

void localisation()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
}

void AR()
{
    cout << "----- Daniyl Mykytenko, KI-20 student. CNTU 2021 (c) -----" << endl << endl << endl;
}

void s_calculation(double y, double z)
{
    double s = pow(z + y + z, 2) - 2 * 3.141592653589793 * sqrt(1 / 3 * z);
    cout << s << endl << endl;
}

double intInput()
{
    double x;
    cout << "Введiть число: ";
    cin.clear();
    fflush(stdin);
    cin >> x;
    return x;
}

double posInput()
{
    double x;
    cout << "Введiть число: ";
    cin.clear();
    fflush(stdin);
    cin >> x;
    double copyx = x;
    while(copyx < 0)
    {
        cout << "Число не може бути меншим нуля." << endl << "Введiть число: ";
        cin >> copyx;
    }
    return copyx;
}

void saleCost(double cost)
{
    double sale;
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
    cout << "Сума до сплати: ";
    printf("%0.2f", cost - saleSum);
    cout << endl << endl;
}

double inputCost()
{
    double cost;
    cout << "Введiть суму товару: ";
    cin.clear();
    fflush(stdin);
    cin >> cost;
    double copyCost = cost;
    while(copyCost < 0)
    {
        cout << "Сума товару не може бути меншою за нуль." << endl << "Введiть суму товару: ";
        cin >> copyCost;
    }
    return copyCost;
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

    if(frSize[index] == 0)
        cout << "В системi Францiї такого розмiру не iснує." << endl;
    else
        cout << "В системi Францiї ваш розмiр: " << frSize[index] << endl;
    cout << "В системi Великобританiї ваш розмiр: " << gbSize[index] << endl;
    cout << "В мiжнароднiй системi ваш розмiр: " << internationalSize[index] << endl << endl;
}

int sizeInput()
{
    int uaSize[6] = {44, 46, 48, 50, 52, 54};
    int size;
    cout << "Введiть розмiр за українською системою: ";
    cin >> size;
    int inputSize = size;
    bool a = false;
    for(int i = 0; i != 6; i++)
    {
        if(inputSize == uaSize[i])
            a = true;
    }
    if(a == false)
    {
        cout << "Такого розмiру не iснує." << endl;
        sizeInput();
    }
    return inputSize;
}

string binaryNumber(long long num)
{
    string concatenance = "";
    int k = 0;
    while(num)
    {
        k = num % 2;
        num = num / 2;
        concatenance = to_string(k) + concatenance;
    }
    return concatenance;
}

void bitCalculator()
{
    long long number;
    cout << "Введiть натуральне число вiд 0 до 80000: " << endl;
    cin >> number;
    while(number < 0 || number > 80000)
    {
        cout << "Помилка: число не належить заданому промiжку." << endl << "Введiть натуральне число вiд 0 до 80000: " << endl;
        cin >> number;
    }
    string binNumber = binaryNumber(number);

    int trueSum = 0;
    int falseSum = 0;
    for(int i = 0; binNumber[i]; i++)
    {
        if(binNumber[i] == '1')
            trueSum++;
        else
            falseSum++;
    }
    if(binNumber.length() < 5)
        cout << "Число на має 5 бiту" << endl << endl;
    else
    {
        cout << "П'ятий бiт числа є " << binNumber[binNumber.length() - 4] << endl;
        if(binNumber[binNumber.length() - 4] == '1')
            cout << "Кiлькiсть одиниць в числi: " << trueSum << endl << endl;
        else
            cout << "Кiлькiсть нулiв в числi: " << falseSum << endl << endl;
    }
}

#endif // QTMODULES_MYKYTENKO_H
