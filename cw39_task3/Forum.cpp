#include "Forum.h"

void Forum::signUp(string login, string pass)
{
	if (Users.find(login) == Users.end()) {
		Users[login] = pass;
		cout << "New user added successfuly";
	}
	else {
		cout << "Error. This user already exists.";
	}
}

void Forum::signIn(string login, string pass)
{
	if (Users.find(login) == Users.end()) {
		cout << "Error. This does not exist.";
	}
	else {
		if (find(signInUsers.begin(), signInUsers.end(), login) != signInUsers.end()) {
			cout << "You are already logged in.";
			return;
		}
		if (Users[login] == pass) {
			cout << "You've logged in.";
			signInUsers.push_back(login);
		}
		else {
			cout << "The password is incorrect. Try again";
		}
	}
}

void Forum::signOut(string login)
{
	if (Users.find(login) == Users.end()) {
		cout << "Error. This does not exist.";
	}
	else {
		if (find(signInUsers.begin(), signInUsers.end(), login) != signInUsers.end()) {
			auto it = find(signInUsers.begin(), signInUsers.end(), login);
			signInUsers.erase(it);
			cout << "You've logged out.";
			
		}
		else {
			cout << "You are not logged in.";
			return;
		}


	}
}

void Forum::showAllUsers() const
{
	for (auto item : Users) {
		cout << "Login: " << item.first << endl;
		cout << "Password: " << item.second << endl << endl;
	}
}

void Forum::showSignedInUsers() const
{
	cout << "Signed in users: " << endl;
	for (auto login : signInUsers) {
		cout << "Login: " << login << endl;
	}
}
