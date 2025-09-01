#include "auth.h"
#include <iostream>
#include <conio.h>

using namespace std;

bool login() {
    string username, password;
    cout << "Login\n------\n";
    cout << "Username: "; cin >> username;
    cout << "Password: ";
    char ch;
    password = "";
    while ((ch = _getch()) != '\r') {
    if (ch == '\b') {
            if (!password.empty()) {
                password = password.substr(0, password.length() - 1);
                cout << " ";
            }
        } else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    if (username == "admin" && password == "1234") {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid credentials!\n";
        return false;
    }
}

void logout() {
    cout << "You have been logged out.\n";
}
