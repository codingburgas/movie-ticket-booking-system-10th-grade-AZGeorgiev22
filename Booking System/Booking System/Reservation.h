#pragma once
#include <string>
#include "Cinema.h"

struct Reservation {
    std::string cinemaName;
    std::string hallName;
    Screening screening;
    std::string paymentMethod;
};

