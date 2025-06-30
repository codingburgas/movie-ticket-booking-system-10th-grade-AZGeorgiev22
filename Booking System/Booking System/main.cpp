#include "User.h" 
#include "CinemaSelection.h" 
#include "Authentication.h" 
#include "Menus.h" 
#include <iostream>

int main() {
    CinemaSelection cinemaSelector;
    bool exitProgram = false;

    while (!exitProgram) {
        bool isAdmin = handleUserAuthenticationAndCheckAdmin();

        if (isAdmin) {
            handleAdminMenu(cinemaSelector);
        }
        else {
            handleUserMenu(cinemaSelector);
            exitProgram = true;
        }
    }

    return 0;
}