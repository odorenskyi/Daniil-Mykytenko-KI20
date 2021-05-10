#include <iostream>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <codecvt>
#include <map>

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
    wstring markerText = L"\nКількість знаків двокрапки - ";
    outputText += markerText;
    outputText += to_wstring(marker);
    outputText += author;
    output << outputText;

    map <wstring, wstring> translitor =
    {
        {L"а", L"a"},
        {L"б", L"b"},
        {L"в", L"v"},
        {L"г", L"h"},
        {L"ґ", L"g"},
        {L"д", L"d"},
        {L"е", L"e"},
        {L"є", L"ie"},
        {L"ж", L"zh"},
        {L"з", L"z"},
        {L"и", L"y"},
        {L"і", L"i"},
        {L"ї", L"i"},
        {L"й", L"i"},
        {L"к", L"k"},
        {L"л", L"l"},
        {L"м", L"m"},
        {L"н", L"n"},
        {L"о", L"o"},
        {L"п", L"p"},
        {L"р", L"r"},
        {L"с", L"s"},
        {L"т", L"t"},
        {L"у", L"u"},
        {L"ф", L"f"},
        {L"х", L"kh"},
        {L"ц", L"ts"},
        {L"ч", L"ch"},
        {L"ш", L"sh"},
        {L"щ", L"shch"},
        {L"ю", L"iu"},
        {L"я", L"ia"}
    };

    wstring translitedText;
    for(int i = 0; input.good(); i++)
    {
        translitedText += translitor[inputText[i]];
    }
}
