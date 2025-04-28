#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

void handleUserAuthentication() {
    int choice;
    bool successful = false;  // A flag to track success or failure

    // Loop to keep asking for login or registration until it's successful
    while (!successful) {
        cout << "1. Register\n2. Login\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            // Register functionality
            string username, password;
            cout << "Enter new username: ";
            cin >> username;
            cout << "Enter new password: ";
            cin >> password;

            // Save the user details to a file
            ofstream outFile("users.txt", ios::app);  // Open in append mode
            if (!outFile) {
                cout << "Error opening file!" << endl;
                return;
            }

            outFile << username << " " << password << endl;
            outFile.close();
            cout << "Registration successful!" << endl;
            successful = true;  // Registration successful, exit the loop
        }
        else if (choice == 2) {
            // Login functionality
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            // Open the file with stored users
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
                    successful = true;  // Login successful, exit the loop
                    found = true;
                    break;
                }
            }

            inFile.close();
            if (!found) {
                cout << "Invalid username or password! Please try again." << endl;
                system("CLS");
            }
        }
        else {
            cout << "Invalid option! Please choose either 1 (Register) or 2 (Login)." << endl;
        }
    }
}