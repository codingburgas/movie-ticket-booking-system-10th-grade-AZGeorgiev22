#include "User.h"
#include "CinemaSelection.h"
#include <iostream>

// Forward declaration of the admin menu function
void handleAdminMenu(CinemaSelection& cinemaSelector);
void handleUserMenu(CinemaSelection& cinemaSelector);

int main() {
    handleUserAuthentication();

    // In a real application, you'd have a global state or a return value from
    // handleUserAuthentication to know if it was a regular user or admin.
    // For this implementation, let's assume if the login is "admin", we show the admin menu.
    // This is a simple placeholder.
    std::cout << "Assuming 'admin' login grants admin privileges.\n";
    bool isAdmin = true; // For demonstration, let's assume it was an admin login. You can change this logic.

    CinemaSelection cinemaSelector;

    if (isAdmin) {
        handleAdminMenu(cinemaSelector);
    }
    else {
        handleUserMenu(cinemaSelector);
    }

    return 0;
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
            std::cout << "Exiting Admin Mode.\n";
            break; // Break out of the admin loop to go back to the main menu (or exit)
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
            break;
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}