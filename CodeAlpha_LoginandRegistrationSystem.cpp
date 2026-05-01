#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
bool userExists(string username, string &storedPassword) {
    ifstream file("users.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username) {
            storedPassword = pass;
            return true;
        }
    }
    return false;
}
void registerOrLogin() {
    string username, password, storedPassword;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter username (no spaces): ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    if (userExists(username, storedPassword)) {
        if (storedPassword == password)
            cout << "Login successful (existing user)!\n";
        else
            cout << "Wrong password!\n";
        return;
    }
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration successful!\n";
}
void loginUser() {
    string username, password, user, pass;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter username (no spaces): ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    ifstream file("users.txt");
    bool found = false;

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Login successful!\n";
    else
        cout << "Invalid username or password!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Login System =====\n";
        cout << "1. Register / Login\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                registerOrLogin();
                break;

            case 2:
                loginUser();
                break;

            case 0:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid input! Try 0, 1, or 2.\n";
        }
    }
}
