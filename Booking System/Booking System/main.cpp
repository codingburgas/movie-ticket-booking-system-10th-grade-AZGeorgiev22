#include "User.h"
#include "CinemaSelection.h"
#include <iostream>
#include <fstream>

// Forward declaration of the menus and authentication function
void handleAdminMenu(CinemaSelection& cinemaSelector);
void handleUserMenu(CinemaSelection& cinemaSelector);
bool handleUserAuthenticationAndCheckAdmin(); // Function now returns a bool

int main() {
    CinemaSelection cinemaSelector;
    bool exitProgram = false;

    while (!exitProgram) {
        // Authenticate the user and check for admin access
        bool isAdmin = handleUserAuthenticationAndCheckAdmin();

        if (isAdmin) {
            // If admin, go to the admin menu
            handleAdminMenu(cinemaSelector);
            // After exiting the admin menu, the loop continues and goes back to authentication
            // so the user has to log in again.
        }
        else {
            // If regular user, go to the user menu
            handleUserMenu(cinemaSelector);
            // The user menu has an exit option that will break the main loop
            exitProgram = true; // This will be set by the user menu's exit choice
        }
    }

    return 0;
}

// Updated authentication function to return admin status
bool handleUserAuthenticationAndCheckAdmin() {
    int choice;
    bool successful = false;

    while (!successful) {
        std::cout << "1. Register\n2. Login\nChoose an option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // --- Admin backdoor login ---
        if (choice == 740) {
            std::cout << "Admin access granted!\n";
            return true; // Return true for admin
        }
        // --- End of admin backdoor ---

        system("cls");

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
                return false;
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

void handleAdminMenu(CinemaSelection& cinemaSelector) {
    while (true) {
        std::cout << "\nAdmin Menu:\n1. Add a Show\n2. Delete a Show\n3. Update a Show\n4. Delete a Movie\n5. Exit Admin Mode\nChoose an option: ";
        int option;
        std::cin >> option;
        system("cls");

        if (option == 1) {
            cinemaSelector.addShow();
        }
        else if (option == 2) {
            cinemaSelector.deleteShow();
        }
        else if (option == 3) {
            cinemaSelector.updateShow();
        }
        else if (option == 4) {
            cinemaSelector.deleteMovie();
        }
        else if (option == 5) {
            std::cout << "Exiting Admin Mode. Returning to login screen.\n";
            break; // Break out of the admin loop
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}

void handleUserMenu(CinemaSelection& cinemaSelector) {
    while (true) {
        std::cout << "\nMenu:\n1. Select Cinema & Make Reservation\n2. Search Movies\n3. Exit\nChoose an option: ";
        int option;
        std::cin >> option;
        system("cls");

        if (option == 1) {
            cinemaSelector.selectCinema();

            if (cinemaSelector.getSelectedCinemaName() != "No cinema selected.") {
                cinemaSelector.displayScreenings();

                bool reserved = cinemaSelector.makeReservation();
                if (!reserved) {
                    std::cout << "Reservation failed. Please try again.\n";
                }
            }
        }
        else if (option == 2) {
            cinemaSelector.searchMovies();
        }
        else if (option == 3) {
            std::cout << "Goodbye!\n";
            // This is where the user exits the program, so we don't need to return to login.
            // Returning from main will end the program.
            break;
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}