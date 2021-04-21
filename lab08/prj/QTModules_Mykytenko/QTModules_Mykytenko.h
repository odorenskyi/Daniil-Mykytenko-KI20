#ifndef QTMODULES_MYKYTENKO_H
#define QTMODULES_MYKYTENKO_H

#include <Windows.h>
#include <math.h>
#include <iostream>

void localisation()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
}

void AR()
{
    std::cout << "Daniyl Mykytenko, KI-20 student. CNTU 2021 (c)" << std::endl;
}

double s_calculation(double y, double z)
{
    while(z < 0)
    {
        std::cout << "Помилка: неправильно введене число Z." << std::endl << "Введ?ть Z: " << std::endl;
        std::cin >> z;
    }
    double s = pow(z + y + z, 2) - 2 * 3.141592653589793 * sqrt(1 / 3 * z);
    return s;
}

float saleCost(float cost)
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
        return cost - cost * sale;
}

#endif // QTMODULES_MYKYTENKO_H
