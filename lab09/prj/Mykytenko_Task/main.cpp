#include <iostream>
#include "QTModules_Mykytenko.h"

using namespace std;

int main()
{
    localisation();
    AR();

    while(true)
    {
        char checkbox= ' ';
        cout << "Щоб викликати функцiю s_calculation, введiть s" <<endl << "Щоб викликати функцiю saleCost, введiть g" << endl << "Щоб викликати функцiю mensUnderwear, введiть f" << endl << "Щоб викликати функцiю bitCalculator, введiть h" << endl << "Для виходу з програми натиснiть j" << endl;;
        cin >> checkbox;
        switch(checkbox)
        {
        case 's':
            s_calculation(intInput(),posInput());
            break;
        case 'g':
            saleCost(inputCost());
            break;
        case 'f':
            mensUnderwear(sizeInput());
            break;
        case 'h':
            bitCalculator();
            break;
        case 'j':
            return 0;
        default:
            Beep(500,500);
            continue;
        }
    }
}
