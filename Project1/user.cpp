#include "user.h"
#include <iostream>

void user::login()
{
    if (LoggedUser.name != "") {
        std::cout << LoggedUser.name << " Name " << LoggedUser.accID << " ID " << LoggedUser.balance << " Balance\n";
        doOpperation();
    }
    else
    {
        std::string username;
        std::string pin;

        std::cout << "Please enter you username: ";
        std::cin >> username;
        std::cout << "Plase enter your PIN: ";
        std::cin >> pin;

        for (const auto& user : Users) {
            if (user.name == username && user.pin == pin) {
                std::cout << "You Logged in\n";
                LoggedUser = user;
                system("cls");
                std::cout << user.name << " Name " << user.accID << " ID " << user.balance << " Balance\n";
                doOpperation();
                break;
            }
            else
            {
                std::cout << "invalid information\n";
            }
        }
    }
}

void user::registerUser()
{
    RandomAccountIDCreator rAIDC;
    std::string name, accID, pin;
    double balance;

    std::cout << "Enter the account name: ";
    std::cin >> name;

    std::cin.get();
    pin = createPin();

    for (int i = 0; i < 10; ++i) {
        accID = rAIDC.generateAccountID();
    }

    std::cout << "Enter the balance: ";
    std::cin >> balance;

    Users.emplace_back(name, pin, accID, 0, balance);
}

std::string user::createPin()
{
    std::string pin;
    char ch;

    std::cout << "Create your PIN (numbers only): ";

    while (true) {
        ch = std::cin.get();

        if (ch == '\n') {
            break;
        }
        else if (ch == '\b' || ch == 127) {
            if (!pin.empty()) {
                pin.pop_back();
                std::cout << "\b \b";
            }
        }
        else if (isdigit(ch)) {
            pin += ch;
        }
        else {
            std::cout << "\nInvalid input. Please enter numbers only.\n";
        }
    }
    return pin;
}

void user::doOpperation()
{
    User_S &LU = LoggedUser;
    int requestedCount;
    char op;
    int opID;

    if (LU.permision == 1) {
        std::cout << "1. Register User\n2. Delete User\n3. Update Users Rank\n4. Logout\n";
        std::cin >> opID;

        switch (opID)
        {
        case 1:
            system("cls");
            registerUser();
            break;
        case 2:
            system("cls");
            GetAllUsers();
            std::cout << "Select user by typing the index of the user: ";
            std::cin >> requestedCount;

            std::cout << "Selected user is " << Users[requestedCount].name << " is it correct (y/n): ";
            std::cin >> op;

            if (op == 'y' || op == 'Y')
            {
                system("cls");
                std::cout << "User " << Users[requestedCount].name << " is removed from data\n";
                Users.erase(Users.begin() + requestedCount);
                GetAllUsers();
                break;
            }
            else {
                system("cls");
                break;
            }
            break;
        case 3:
            system("cls");
            GetAllUsers();
            std::cout << "Select user by typing the index of the user: ";
            std::cin >> requestedCount;

            std::cout << "Selected user is " << Users[requestedCount].name << " is it correct (y/n): ";
            std::cin >> op;

            if (op == 'y' || op == 'Y')
            {
                User_S &SelectedUserData = Users.at(requestedCount);
                int perm;
                std::cout << "Change the permision (0 User, 1 Admin): ";
                std::cin >> perm;
                system("cls");
                SelectedUserData.permision = perm;
                GetAllUsers();
                break;
            }
            else {
                system("cls");
                break;
            }
            break;
        case 4:
            LoggedUser = User_S("", "", "0000000000", 0, 0);
            break;
        default:
            break;
        }
    }
    else
    {
        std::cout << "1. Widraw\n2. Deposit\n3. Delete Acount\n4. Logout\n";
        std::cin >> opID;

        switch (opID)
        {
        case 1:
            std::cout << "type \"0\" for going back\n";
            std::cout << "How much do you widraw: ";
            std::cin >> requestedCount;

            if (requestedCount > 15)
            {
                LU.balance -= requestedCount;
                for (size_t i = 0; i < Users.size(); ++i) {
                    if (Users[i].name == LU.name) {
                        Users[i].balance = LU.balance;
                        std::cout << "New Balance " << Users[i].balance << std::endl;
                    }
                }
            }
            else if (requestedCount == 0) {
                break;
            }
            break;
        case 2:
            std::cout << "type \"0\" for going back\n";
            std::cout << "How much do you deposit: ";
            std::cin >> requestedCount;

            if (requestedCount > 15)
            {
                LU.balance += requestedCount;
                for (size_t i = 0; i < Users.size(); ++i) {
                    if (Users[i].name == LU.name) {
                        Users[i].balance = LU.balance;
                        std::cout << "New Balance " << Users[i].balance << std::endl;
                    }
                }
            }
            else if (requestedCount == 0) {
                break;
            }
            break;
        case 3:
            std::cout << "on work\n";
            break;
        case 4:
            LoggedUser = User_S("", "", "0000000000", 0, 0);
            break;
        default:
            break;
        }
    }
}

void user::GetAllUsers() {
    int index = 0;
	for (const auto& user : Users) {
        if (user.name != "Admin" || user.permision != 1)
        {
            std::string Perm;
            if (user.permision == 0)
            {
                Perm = "User";
            }
            else {
                Perm = "Admin";
            }
            index++;
		    std::cout << index << " Name: " << user.name << " Account ID: " << user.accID << " Balance: " << user.balance
                <<  " User Perm: " << Perm << std::endl;
        }
	}
}