#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool userExists(string username) {
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username) {
            return true;
        }
    }
    return false;
}
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "Username or Password cannot be empty"<<endl;
        return;
    }

    if (userExists(username)) {
        cout << "Username already exists"<<endl;
        return;
    }
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration successful"<<endl;
}
void loginUser() {
    string username, password;
    string user, pass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream file("users.txt");
    bool found = false;

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Login successful!\n";
    } else {
        cout << "Invalid username or password!\n";
    }
}
int main() {
    int choice;

    while (true) {
        cout << "===== Login System ====="<<endl;
        cout << "1. Register"<<endl;
        cout << "2. Login"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
