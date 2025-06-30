#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>
#include "Seat.h" // Include the new Seat header

struct Screening {
    std::string movieTitle;
    std::string language;
    std::string genre;
    std::string releaseDate;
    std::string showTime;
    std::vector<std::vector<Seat>> seatingArrangement; // 2D vector for seating
};

struct Hall {
    std::string hallName;
    std::vector<Screening> screenings;
};

class Cinema {
public:
    std::string name;
    std::vector<Hall> halls;
};

#endif // CINEMA_H