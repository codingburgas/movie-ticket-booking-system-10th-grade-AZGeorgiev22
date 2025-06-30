#pragma once

#include <string>
#include <vector>
#include "Seat.h" 

struct Screening {
    std::string movieTitle;
    std::string language;
    std::string genre;
    std::string releaseDate;
    std::string showTime;
    std::vector<std::vector<Seat>> seatingArrangement; // 2D vector for seatig
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

