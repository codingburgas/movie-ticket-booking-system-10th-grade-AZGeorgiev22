#ifndef SEAT_H
#define SEAT_H

#include <string>

struct Seat {
    int row;
    int column;
    char status; // 'A' for Available, 'R' for Reserved
    std::string ticketType; // e.g., "Silver", "Gold", "Platinum"
    double price;

    // Default constructor
    Seat() : row(0), column(0), status('A'), ticketType(""), price(0.0) {}

    // Parameterized constructor
    Seat(int r, int c, char s, const std::string& type, double p) : row(r), column(c), status(s), ticketType(type), price(p) {}
};

#endif // SEAT_H