#ifndef WMODULE_H
#define WMODULE_H
#include <iostream>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <codecvt>
#include <cctype>
#include <ctime>
#include <math.h>

using namespace std;

void wlocale()
{
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

wstring wAR()
{
    wstring author = {L"----- © Микитенко Даниїл: студент Центральноукраїнського Національного Технічного Університету -----\nУкраїна, 2021 рік."};
    return author;
}

int s_calculation(double y, double z)
{
    double s = pow(z + y + z, 2) - 2 * 3.141592653589793 * sqrt(1 / 3 * z);
    return s;
}

double intInput(wchar_t y)
{
    double x;
    wcout << L"Введіть число " << y << L": ";
    wcin.clear();
    fflush(stdin);
    wcin >> x;
    return x;
}

double posInput(wchar_t y)
{
    double x;
    wcout << L"Введіть число " << y << L": ";
    wcin.clear();
    fflush(stdin);
    wcin >> x;
    double copyx = x;
    while(copyx < 0)
    {
        wcout << L"Число не може бути меншим нуля. Введіть число " << y << L": ";
        wcin >> copyx;
    }
    return copyx;
}

wstring inputGetter()
{

    wifstream input;
    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input.open("input.txt", ios_base::in);

    if(!input.is_open())
    {
        wcout << L"Файл input.txt не знайдено.";
        return 0;
    }

    wstring inputText;
    wstring copys;
    while(input.good())
    {
        getline(input, copys);
        inputText += copys;
        inputText += '\n';
    }
    return inputText;
}

int markerGetter(wstring inputText)
{
    int length = inputText.length();
    int marker = 0;
    for(int i = 0; i < length; i++)
    {
        if(inputText[i] == L':')
            marker++;
    }
    return marker;
}

wstring outputGetter()
{
    wstring inputText = inputGetter();
    int length = inputText.length();
    wstring outputText;
    for(int i = 0; i < length; i++)
    {
        if(!(inputText[i] == L'а' || inputText[i] == L'о' || inputText[i] == L'у' || inputText[i] == L'е' || inputText[i] == L'и' || inputText[i] == L'і'))
            outputText += inputText[i];
    }
    return outputText;
}

wstring translitor()
{
    wstring inputText = inputGetter();
    int length = inputText.length();

    wchar_t ua[33] = {L'а',L'б',L'в',L'г',L'ґ',L'д',L'е',L'є',L'ж',L'з',L'и',L'і',L'ї',L'й',L'к',L'л',L'м',L'н',L'о',L'п',L'р',L'с',L'т',L'у',L'ф',L'х',L'ц',L'ч',L'ш',L'щ',L'ю',L'я',L' '};
    wstring eng[33] = {L"a",L"b",L"v",L"h",L"g",L"d",L"e",L"ie",L"zh",L"z",L"y",L"i",L"i",L"i",L"k",L"l",L"m",L"n",L"o",L"p",L"r",L"s",L"t",L"u",L"f",L"kh",L"ts",L"ch",L"sh",L"shch",L"iu",L"ia",L" "};

    wstring translitedText;
    for(int i = 0; i < length; i++)
    {
        if(inputText[i] >= L'А' && inputText[i] <= L'Я')
            inputText[i] += 32;
        for(int j = 0; j < 33; j++)
            if(inputText[i] == ua[j])
                translitedText += eng[j];
    }
    return translitedText;
}

wstring binaryNumber(long long num)
{
    wstring concatenance = L"";
    int k = 0;
    while(num)
    {
        k = num % 2;
        num = num / 2;
        concatenance = to_wstring(k) + concatenance;
    }
    concatenance = L"Число b в двійковому коді дорівнює: " + concatenance;
    return concatenance;
}

string timeNow()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}

wstring timeConverter()
{
    string times = timeNow();
    wstring wtime(times.begin(), times.end());
    return wtime;
}

#endif // WMODULE_H
