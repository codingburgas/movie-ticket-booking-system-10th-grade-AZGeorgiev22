#pragma once
#include <string>

struct Seat {
    int row;
    int column;
    char status; // A available  R reserved
    std::string ticketType; // Silve, Gold, Platinum
    double price;

    // Default constructor
    Seat() : row(0), column(0), status('A'), ticketType(""), price(0.0) {}

    // Parameterized constructor
    Seat(int r, int c, char s, const std::string& type, double p) : row(r), column(c), status(s), ticketType(type), price(p) {}
};

