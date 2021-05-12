#include <iostream>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <codecvt>
#include <cctype>
#include <ctime>
#include "wModule.h"

using namespace std;

int main()
{
    wlocale();

    wofstream output;

    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    output.open("output.txt", ios_base::out);

    if(!output.is_open())
    {
        wcout << L"Файл output.txt не знайдено.";
        return 0;
    }

    output << wAR() << endl << endl << L"Текст з input.txt - " << inputGetter() << L"\nКількість знаків двокрапки - " << markerGetter() << endl << L"\nТранслітерований текст: " << translitor() << endl << L"Результат функції s_calculation: " << s_calculation(intInput(L'x'), intInput(L'y')) << endl << binaryNumber(posInput(L'b')) << endl << endl << timeConverter();


}
