#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "Cinema.h"

struct Reservation {
    std::string cinemaName;
    std::string hallName;
    Screening screening;
};

#endif // RESERVATION_H
