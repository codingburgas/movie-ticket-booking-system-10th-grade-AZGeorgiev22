#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

void handleUserAuthentication() {
    int choice;
    bool successful = false;

    while (!successful) {
        cout << "1. Register\n2. Login\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter new username: ";
            cin >> username;
            cout << "Enter new password: ";
            cin >> password;
            system("cls");
            ofstream outFile("users.txt", ios::app);
            if (!outFile) {
                cout << "Error opening file!" << endl;
                return;
            }
            outFile << username << " " << password << endl;
            outFile.close();
            cout << "Registration successful!" << endl;
            successful = true;
        }
        else if (choice == 2) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            system("cls");

            ifstream inFile("users.txt");
            if (!inFile) {
                cout << "Error opening file!" << endl;
                return;
            }

            string storedUsername, storedPassword;
            bool found = false;
            while (inFile >> storedUsername >> storedPassword) {
                if (storedUsername == username && storedPassword == password) {
                    inFile.close();
                    cout << "Login successful!" << endl;
                    successful = true;
                    found = true;
                    break;
                }
            }
            inFile.close();

            if (!found) {
                cout << "Invalid username or password! Please try again." << endl;
#ifdef _WIN32
                system("CLS");
#else
                system("clear");
#endif
            }
        }
        else {
            cout << "Invalid option! Please choose either 1 (Register) or 2 (Login)." << endl;
        }
    }
}
