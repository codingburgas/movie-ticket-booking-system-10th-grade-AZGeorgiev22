#ifndef CINEMASELECTION_H
#define CINEMASELECTION_H

#include <vector>
#include <string>
#include "Cinema.h"
#include "Reservation.h"

class CinemaSelection {
public:
    CinemaSelection();
    void displayCinemas() const;
    void selectCinema();
    void displayScreenings() const;
    bool makeReservation();
    std::string getSelectedCinemaName() const;

    void searchMovies();

private:
    std::vector<Cinema> cinemaList;
    int selectedCinemaIndex;
    Reservation currentReservation;

    bool matchesCriteria(const Screening& screening,
        const std::string& title,
        const std::string& language,
        const std::string& genre,
        const std::string& releaseDate) const;
};

#endif // CINEMASELECTION_H
