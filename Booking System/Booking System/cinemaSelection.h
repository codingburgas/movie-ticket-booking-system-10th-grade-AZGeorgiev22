#ifndef CINEMASELECTION_H
#define CINEMASELECTION_H

#include <vector>
#include <string>
#include "Cinema.h"
#include "Reservation.h"
#include "Seat.h"

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

    // New helper function to initialize seating
    void initializeSeating(Screening& screening, int rows, int cols);
    // New helper function to display seating
    void displaySeatingChart(const Screening& screening) const;
    // New helper function for validating and reserving seats
    bool reserveSeats(Screening& screening, const std::vector<std::pair<int, int>>& selectedSeats);

    bool matchesCriteria(const Screening& screening,
        const std::string& title,
        const std::string& language,
        const std::string& genre,
        const std::string& releaseDate) const;
};

#endif // CINEMASELECTION_H