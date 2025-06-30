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

    // Admin functions
    void addMovie();
    void deleteMovie();
    void updateShow(); // Renamed from updateMovie to be more clear
    void addShow();
    void deleteShow();

private:
    std::vector<Cinema> cinemaList;
    int selectedCinemaIndex;
    Reservation currentReservation;

    // Helper functions
    void initializeSeating(Screening& screening, int rows, int cols);
    void displaySeatingChart(const Screening& screening) const;
    bool reserveSeats(Screening& screening, const std::vector<std::pair<int, int>>& selectedSeats);

    bool matchesCriteria(const Screening& screening,
        const std::string& title,
        const std::string& language,
        const std::string& genre,
        const std::string& releaseDate) const;
};

#endif // CINEMASELECTION_H