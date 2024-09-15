#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file;
    file.open("users.txt", ios::app);

    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful! Your account has been created.\n";
    } else {
        cout << "Error: Unable to open file.\n";
    }
}

bool loginUser() {
    string username, password, u, p;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("users.txt");
    bool loginSuccess = false;

    if (file.is_open()) {
        while (file >> u >> p) {
            if (u == username && p == password) {
                loginSuccess = true;
                break;
            }
        }
        file.close();

        if (loginSuccess) {
            cout << "Login successful! Welcome, " << username << ".\n";
            return true;
        } else {
            cout << "Invalid username or password. Please try again.\n";
            return false;
        }
    } else {
        cout << "Error: Unable to open file.\n";
        return false;
    }
}

void displayMenu() {
    int choice;

    while (true) {
        cout << "\n===== Login and Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "You are now logged in.\n";
                }
                break;
            case 3:
                cout << "Exiting the system. Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please select again.\n";
        }
    }
}

int main() {
    displayMenu();
    return 0;
}
