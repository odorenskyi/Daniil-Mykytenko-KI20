#include <iostream>
#include <string.h>
#include <fstream>
#include "wModule.h"

using namespace std;

int main()
{
    wlocale();
    wstring copys;
    wstring bigword;
    wstring check;
    wstring check1;
    wchar_t checkbox=0;
    while(true){
        wcout<< wAR() <<endl;
        wcout<<L"---------Виберіть дію----------\n";
        wcout<<L"Введіть b для дозапису інформації у файл\n";
        wcout<<L"Для виконання функції переводу у двійкову систему введіть c\n";
        wcout<<L"Введіть d для виконання s_calculation\n";
        wcout<<L"Введіть x для виходу із программи\n";
        wcout<<L"==========>";
        wcin>>checkbox;
        switch (checkbox)
        {

        case 'b':
        {
            wifstream input;
            input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
            input.open("input.txt", ios_base::app);
            if(input.is_open())
                wcout<< L"Дозапис було створено у файлі input.Для коректної роботи функції (а) видаліть дозапис після перегляду";
            break;
        }
        case 'c':
        {
            wstring binarnik = binaryNumber(posInput(L'x'));
            wcout << binarnik;
            break;
        }
        case 'd':
        {
            wcout << s_calculation(intInput(L'x'), intInput(L'y'));
            break;
        }
        case 'x':
        {
            return 0;
            break;
        }
        }
    }
    system("pause");
    getchar();
    return 0;
}
