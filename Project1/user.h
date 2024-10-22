#pragma once
#include <vector>
#include <string>
#include <limits>
#include "accountIDCreator.h"

class user
{
	struct User_S
	{
		std::string name;
		std::string pin;
		std::string accID;
		int permision;
		double balance;

		User_S() : name(""), pin(""), accID(""), permision(0), balance(0.0) {}

		User_S(std::string UserName, std::string UserPin, std::string AccountNumber, int permision, double InitialBalance)
			: name(UserName), pin(UserPin), accID(AccountNumber), permision(permision), balance(InitialBalance) {}
	};
public:
	std::vector<User_S> Users;

	user() {
		Users.push_back(User_S("Admin", "1234", "0000000000", 1, 1000));
		Users.push_back(User_S("Baran", "3152", "2519025172", 0, 1000));
	}
	void login();

	void registerUser();
	void GetAllUsers();
private:
	User_S LoggedUser;
	std::string createPin();
	void doOpperation();
};

