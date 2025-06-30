#include "Authentication.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>


bool handleUserAuthenticationAndCheckAdmin() {
    int choice;
    bool successful = false;

    while (!successful) {
        std::cout << "1. Register\n2. Login\nChoose an option: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Admin backdoor login
        if (choice == 740) {
            std::cout << "Admin access granted!\n";
            return true; // Return true for admin
        }
        // End of admin backdoor

        system("cls"); // Clears the console screen

        if (choice == 1) {
            std::string username, password;
            std::cout << "Enter new username: ";
            std::cin >> username;
            std::cout << "Enter new password: ";
            std::cin >> password;
            system("cls");

            std::ofstream outFile("users.txt", std::ios::app);
            if (!outFile) {
                std::cout << "Error opening file!" << std::endl;
                
                continue;
            }
            outFile << username << " " << password << std::endl;
            outFile.close();
            std::cout << "Registration successful!" << std::endl;
            successful = true;
        }
        else if (choice == 2) {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            system("cls");

            std::ifstream inFile("users.txt");
            if (!inFile) {
                std::cout << "Error opening file! Please register first.\n";
                continue;
            }

            std::string storedUsername, storedPassword;
            bool found = false;
            while (inFile >> storedUsername >> storedPassword) {
                if (storedUsername == username && storedPassword == password) {
                    found = true;
                    break;
                }
            }
            inFile.close();

            if (found) {
                std::cout << "Login successful!" << std::endl;
                successful = true;
            }
            else {
                std::cout << "Invalid username or password! Please try again." << std::endl;
            }
        }
        else {
            std::cout << "Invalid option! Please choose either 1 (Register) or 2 (Login).\n";
        }
    }
    return false; // Return false for a regular user
}