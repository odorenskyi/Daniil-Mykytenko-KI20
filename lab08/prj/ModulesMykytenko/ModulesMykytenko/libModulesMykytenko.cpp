#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <math.h>
#include "libModulesMykytenko.h"


void localisation()
{
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void AR()
{
    std::cout << "Daniyl Mykytenko, KI-20 student. CNTU 2021 ©" << std::endl;
}


double s_calculation(double x, double y, double z)
{
    double s = pow(z + y + z, 2) - 2 * 3.141592653589793 * sqrt(1 / 3 * z);
    return s;
}
