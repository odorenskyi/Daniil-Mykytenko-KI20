#include <iostream>
#include "QTModules_Mykytenko.h"

using namespace std;

int main()
{
    localisation();
    AR();

    bool beepSound = false;
    char exit = '0';
    while(true)
    {
        char checkbox= ' ';
        cout << "Щоб викликати функцiю s_calculation, введiть s" <<endl << "Щоб викликати функцiю saleCost, введiть g" << endl << "Щоб викликати функцiю mensUnderwear, введiть f" << endl << "Щоб викликати функцiю bitCalculator, введiть h" << endl;
        cin >> checkbox;
        switch(checkbox)
        {
        case 's':
            beepSound = false;
            s_calculation(inputY(),inputZ());
            break;
        case 'g':
            beepSound = false;
            saleCost(inputCost());
            break;
        case 'f':
            beepSound = false;
            mensUnderwear(sizeInput());
            break;
        case 'h':
            beepSound = false;
            bitCalculator();
            break;
        default:
            beepSound = true;
            Beep(500,500);
            break;
        }
        if(beepSound == true)
            continue;
        else
        {
            beepSound = false;
            cout << endl << "Для виходу з програми натиснiть j" << endl;
            cin >> exit;
            if(exit == 'j' || exit =='J')
                return 0;
        }
    }
}
