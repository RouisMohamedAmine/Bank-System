#include <iostream>
#include "clsLoginScreen.h"

int main()

{
    while (!LoginFailed) 
    {
        clsLoginScreen::ShowLoginScreen();

    }
    system("pause>0");
    return 0;
}