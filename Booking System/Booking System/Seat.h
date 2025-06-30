#ifndef SEAT_H
#define SEAT_H

struct Seat {
    int row;
    int column;
    char status; // 'A' for Available, 'R' for Reserved

    // Default constructor
    Seat() : row(0), column(0), status('A') {}

    // Parameterized constructor
    Seat(int r, int c, char s) : row(r), column(c), status(s) {}
};

#endif // SEAT_H