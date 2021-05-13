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
    wcout << L"Якщо ви запускаєте застосунок вперше - створіть у теці с проєктом текстовий файл \"input.txt\", запишіть туди інформацію й після цього запустіть застосунок." << endl;

    wifstream startInput;
    startInput.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    startInput.open("input.txt", ios_base::in);
    wstring inputText = inputGetter();
    startInput.close();


    wofstream input;
    wofstream output;

    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    input.open("input.txt", ios_base::out);
    output.open("output.txt", ios_base::out);

    if(!output.is_open())
    {
        wcout << L"Файл output.txt не знайдено.";
        return 0;
    }

    if(!input.is_open())
    {
        wcout << L"Файл input.txt не знайдено.";
        return 0;
    }

    output << wAR() << endl << endl << L"Текст з input.txt - " << inputText << L"Кількість знаків двокрапки - " << markerGetter(inputText) << endl << timeConverter();
    input << inputText << endl << L"\nТранслітерований текст: " << translitor()<< endl << L"Результат функції s_calculation: " << s_calculation(intInput(L'x'), intInput(L'y')) << endl << binaryNumber(posInput(L'b')) << endl << endl << timeConverter();

}
