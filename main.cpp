#include <iostream>
#include "Screens/LoginScreen.h"
#include "Global/Global.h"
using namespace std;

int main()
{
    while (true) {
        LoginScreen::show();
    }

    system("pause>0");
    return 0;
}
