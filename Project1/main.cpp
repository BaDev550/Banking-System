#include <Windows.h>
#include <iostream>
#include "user.h"

int main() {
    user UserData;
    bool applicationShoudClose = false;
    char op;

    while (!applicationShoudClose)
    {
        UserData.login();
        
        Sleep(100);
        std::cout << "Do you want to close the app (y/n): ";
        std::cin >> op;

        if (op == 'y') {
            applicationShoudClose = true;
            break;
        }
        else
        {
            applicationShoudClose = false;
            system("cls");
        }
    }
	return 0;
}
