#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Forum {
	map <string, string> Users;
	vector <string> signInUsers;

public:

	void signUp(string login, string pass);
	void signIn(string login, string pass);
	void signOut(string login);

	void showAllUsers() const;
	void showSignedInUsers() const;

};

