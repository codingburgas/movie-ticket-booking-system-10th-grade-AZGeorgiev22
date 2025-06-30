#include "User.h"
#include <iostream>
#include <fstream>
#include <limits> // For std::numeric_limits

using namespace std;

void handleUserAuthentication() {
    int choice;
    bool successful = false;

    while (!successful) {
        cout << "1. Register\n2. Login\nChoose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // --- Admin backdoor login ---
        if (choice == 740) {
            cout << "Admin access granted!\n";
            successful = true;
            return; // Exit the function to proceed to the main menu as admin
        }
        // --- End of admin backdoor ---

        system("cls");

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
                cout << "Error opening file! Please register first.\n";
                continue;
            }

            string storedUsername, storedPassword;
            bool found = false;
            while (inFile >> storedUsername >> storedPassword) {
                if (storedUsername == username && storedPassword == password) {
                    found = true;
                    break;
                }
            }
            inFile.close();

            if (found) {
                cout << "Login successful!" << endl;
                successful = true;
            }
            else {
                cout << "Invalid username or password! Please try again." << endl;
            }
        }
        else {
            cout << "Invalid option! Please choose either 1 (Register) or 2 (Login).\n";
        }
    }
}