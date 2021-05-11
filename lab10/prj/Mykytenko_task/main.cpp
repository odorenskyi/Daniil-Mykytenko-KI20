#include <iostream>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <codecvt>
#include <cctype>
#include <mftransform.h>

using namespace std;

int main()
{
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);


    wstring author = {L"\n© Микитенко Даниїл: студент Центральноукраїнського Національного Технічного Університету\nУкраїна, 2021 рік."};

    wifstream input;
    wofstream output;

    input.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    input.open("input.txt", ios_base::in);
    output.open("output.txt", ios_base::out);

    if(!input.is_open())
    {
        wcout << L"Файл input.txt не знайдено.";
        return 0;
    }
    if(!output.is_open())
    {
        wcout << L"Файл output.txt не знайдено.";
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
    int length = inputText.length();
    int marker = 0;
    wstring outputText;
    for(int i = 0; i < length; i++)
    {
        if(inputText[i] == L':')
            marker++;
        if(!(inputText[i] == L'а' || inputText[i] == L'о' || inputText[i] == L'у' || inputText[i] == L'е' || inputText[i] == L'и' || inputText[i] == L'і'))
            outputText += inputText[i];
    }


    wchar_t ua[33] = {L'а',L'б',L'в',L'г',L'ґ',L'д',L'е',L'є',L'ж',L'з',L'и',L'і',L'ї',L'й',L'к',L'л',L'м',L'н',L'о',L'п',L'р',L'с',L'т',L'у',L'ф',L'х',L'ц',L'ч',L'ш',L'щ',L'ю',L'я',L' '};
    wstring eng[33] = {L"a",L"b",L"v",L"h",L"g",L"d",L"e",L"ie",L"zh",L"z",L"y",L"i",L"i",L"i",L"k",L"l",L"m",L"n",L"o",L"p",L"r",L"s",L"t",L"u",L"f",L"kh",L"ts",L"ch",L"sh",L"shch",L"iu",L"ia",L" "};

    wstring translitedText;
    wcout << "length is " << length << endl;
    for(int i = 0; i < length; i++)
    {
        if(inputText[i] >= L'А' && inputText[i] <= L'Я')
            inputText[i] += 32;
        for(int j = 0; j < 33; j++)
            if(inputText[i] == ua[j])
                translitedText += eng[j];
    }

    wstring markerText = L"\nКількість знаків двокрапки - ";
    outputText += markerText;
    outputText += to_wstring(marker);
    outputText += L"\nТранслітерований текст з файлу: ";
    outputText += translitedText;
    outputText += author;
    output << outputText;



}
