#include "User.h"
#include "CinemaSelection.h"
#include <iostream>

int main() {
    handleUserAuthentication();

    CinemaSelection cinemaSelector;

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

    return 0;
}
