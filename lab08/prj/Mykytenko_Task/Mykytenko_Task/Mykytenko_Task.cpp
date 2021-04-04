// Mykytenko_Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include "libModulesMykytenko.h"
#include <iomanip>
#pragma comment(lib, "ModulesMykytenko.lib")

using namespace std;

double inputX()
{
	double x;
	cout << "Введіть Х: " << endl;
	cin >> x;
	return x;
}
double inputY()
{
	double y;
	cout << "Введіть Y: " << endl;
	cin >> y;
	return y;
}

double inputZ()
{
	double z;
	cout << "Введіть Z: " << endl;
	cin >> z;
	return z;
}

char inputA()
{
	char a;
	cout << "Введіть символ A: " << endl;
	cin >> a;
	return a;
}

char inputB()
{
	char b;
	cout << "Введіть символ B: " << endl;
	cin >> b;
	return b;
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
	bool expression = a + 1 < b;
	cout << endl << "Expression \"a + 1 < b\" is " << boolalpha << expression << endl << endl;

	// third demand
	cout << "X, Y and Z in decimal form is:" << endl;
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	cout << "Z = " << z << endl << endl;

	cout << "In hexadecimal form is: " << endl; 
	cout << "X = " << hex << x << endl;
	cout << "Y = " << hex << y << endl;
	cout << "Z = " << hex << z << endl << endl;

	double s = s_calculation(x, y, z);
	cout << "S = " << s << endl;

	system("pause");
}
