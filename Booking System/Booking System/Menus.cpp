#include "Menus.h"
#include <iostream>
#include <cstdlib> 


void handleAdminMenu(CinemaSelection& cinemaSelector) {
    while (true) {
        std::cout << "\nAdmin Menu:\n1. Add a Show\n2. Delete a Show\n3. Update a Show\n4. Delete a Movie\n5. Exit Admin Mode\nChoose an option: ";
        int option;
        std::cin >> option;
        system("cls");

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

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

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

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
            break; // Break out of the user loop
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
}