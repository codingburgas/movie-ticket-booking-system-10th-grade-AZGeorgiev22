#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>

struct Screening {
    std::string movieTitle;
    std::string language;
    std::string genre;
    std::string releaseDate;  // Format: YYYY-MM-DD or any consistent format
    std::string showTime;
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
