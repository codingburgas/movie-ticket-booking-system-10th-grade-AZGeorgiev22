#include "CinemaSelection.h"
#include <iostream>
#include <algorithm>
#include <limits> 
#include <iomanip> 

// Helper function to initialize a seating arrangement with ticket types and prices
void CinemaSelection::initializeSeating(Screening& screening, int rows, int cols) {
    screening.seatingArrangement.resize(rows, std::vector<Seat>(cols));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::string ticketType = "Silver";
            double price = 10.0;

            if (r + 1 == 3) {
                ticketType = "Platinum";
                price = 20.0;
            }
            else if (r + 1 == 2 || r + 1 == 4) {
                ticketType = "Gold";
                price = 15.0;
            }

            screening.seatingArrangement[r][c] = Seat(r + 1, c + 1, 'A', ticketType, price); // 'A' for Available
        }
    }
}

CinemaSelection::CinemaSelection() {
    cinemaList = {
        {
            "Grand Cinema", {
                {"Hall 1", {
                    {"The Matrix", "English", "Sci-Fi", "1999-03-31", "10:00 AM"},
                    {"Inception", "English", "Sci-Fi", "2010-07-16", "1:00 PM"}
                }},
                {"Hall 2", {
                    {"Interstellar", "English", "Sci-Fi", "2014-11-07", "11:00 AM"},
                    {"Dunkirk", "English", "War", "2017-07-21", "2:00 PM"}
                }},
                {"Hall 3", {
                    {"Tenet", "English", "Action", "2020-09-03", "3:00 PM"},
                    {"Oppenheimer", "English", "Biography", "2023-07-21", "6:00 PM"}
                }}
            }
        },
        {
            "Movie Palace", {
                {"Hall 1", {
                    {"Frozen", "English", "Animation", "2013-11-27", "9:00 AM"},
                    {"Moana", "English", "Animation", "2016-11-23", "12:00 PM"}
                }},
                {"Hall 2", {
                    {"Coco", "English", "Animation", "2017-11-22", "3:00 PM"},
                    {"Encanto", "English", "Animation", "2021-11-24", "5:00 PM"}
                }},
                {"Hall 3", {
                    {"Zootopia", "English", "Animation", "2016-03-04", "7:00 PM"},
                    {"Soul", "English", "Animation", "2020-12-25", "9:00 PM"}
                }}
            }
        },
        {
            "CineWorld", {
                {"Hall 1", {
                    {"Avatar", "English", "Sci-Fi", "2009-12-18", "10:30 AM"},
                    {"Titanic", "English", "Romance", "1997-12-19", "1:30 PM"}
                }},
                {"Hall 2", {
                    {"Aliens", "English", "Sci-Fi", "1986-07-18", "4:30 PM"},
                    {"The Abyss", "English", "Sci-Fi", "1989-08-09", "7:30 PM"}
                }},
                {"Hall 3", {
                    {"True Lies", "English", "Action", "1994-07-15", "10:00 PM"}
                }}
            }
        },
        {
            "Skyline Theatre", {
                {"Hall 1", {
                    {"John Wick", "English", "Action", "2014-10-24", "11:00 AM"},
                    {"Matrix Reloaded", "English", "Sci-Fi", "2003-05-15", "2:00 PM"}
                }},
                {"Hall 2", {
                    {"Mad Max", "English", "Action", "2015-05-15", "4:00 PM"},
                    {"Gladiator", "English", "Drama", "2000-05-05", "7:00 PM"}
                }},
                {"Hall 3", {
                    {"Braveheart", "English", "Drama", "1995-05-24", "9:30 PM"}
                }}
            }
        }
    };
    selectedCinemaIndex = -1;

    // Initialize seating for all screenings
    for (auto& cinema : cinemaList) {
        for (auto& hall : cinema.halls) {
            for (auto& screening : hall.screenings) {
                initializeSeating(screening, 5, 10); // 5 rows, 10 columns for all halls
            }
        }
    }
}

void CinemaSelection::displayCinemas() const {
    std::cout << "Available Cinemas:\n";
    for (size_t i = 0; i < cinemaList.size(); ++i) {
        std::cout << i + 1 << ". " << cinemaList[i].name << '\n';
    }
}

void CinemaSelection::selectCinema() {
    displayCinemas();
    std::cout << "Enter the number of the cinema you'd like to select: ";
    int choice;
    std::cin >> choice;
    system("cls");

    if (choice > 0 && static_cast<size_t>(choice) <= cinemaList.size()) {
        selectedCinemaIndex = choice - 1;
        std::cout << "You selected: " << cinemaList[selectedCinemaIndex].name << '\n';
    }
    else {
        std::cout << "Invalid selection.\n";
        selectedCinemaIndex = -1;
    }
}

void CinemaSelection::displayScreenings() const {
    if (selectedCinemaIndex < 0 || selectedCinemaIndex >= static_cast<int>(cinemaList.size())) {
        std::cout << "No cinema selected.\n";
        return;
    }

    const Cinema& cinema = cinemaList[selectedCinemaIndex];
    std::cout << "\nScreenings for " << cinema.name << ":\n";

    for (size_t i = 0; i < cinema.halls.size(); ++i) {
        const Hall& hall = cinema.halls[i];
        std::cout << "  " << (i + 1) << ". " << hall.hallName << ":\n";
        for (size_t j = 0; j < hall.screenings.size(); ++j) {
            const Screening& screening = hall.screenings[j];
            std::cout << "     " << (j + 1) << ". " << screening.movieTitle << " at " << screening.showTime << '\n';
        }
    }
}

void CinemaSelection::displaySeatingChart(const Screening& screening) const {
    std::cout << "\nSeating Chart ('A' = Available, 'R' = Reserved):\n";
    std::cout << "    "; // Extra space for alignment
    for (size_t col = 0; col < screening.seatingArrangement[0].size(); ++col) {
        std::cout << std::setw(3) << col + 1; // Use setw to set a fixed width for each column number
    }
    std::cout << "\n";

    for (size_t row = 0; row < screening.seatingArrangement.size(); ++row) {
        // Display only the row number with a fixed width for alignment
        std::cout << "R" << std::setw(2) << row + 1 << " ";
        for (size_t col = 0; col < screening.seatingArrangement[row].size(); ++col) {
            std::cout << "  " << screening.seatingArrangement[row][col].status;
        }
        // Display ticket type and price at the end of the line
        std::cout << "  - " << screening.seatingArrangement[row][0].ticketType << " ($" << std::fixed << std::setprecision(2) << screening.seatingArrangement[row][0].price << ")\n";
    }
}

bool CinemaSelection::reserveSeats(Screening& screening, const std::vector<std::pair<int, int>>& selectedSeats) {
    // A vector to hold seats that are invalid or already reserved
    std::vector<std::pair<int, int>> invalidSeats;
    std::vector<std::pair<int, int>> reservedSeats;

    // First, check all seats for validity and availability without changing the state
    for (const auto& seat : selectedSeats) {
        int row = seat.first;
        int col = seat.second;

        // Check if the seat is within bounds
        if (row < 1 || static_cast<size_t>(row) > screening.seatingArrangement.size() ||
            col < 1 || static_cast<size_t>(col) > screening.seatingArrangement[0].size()) {
            invalidSeats.push_back({ row, col });
        }
        // Check if the seat is already reserved
        else if (screening.seatingArrangement[row - 1][col - 1].status == 'R') {
            reservedSeats.push_back({ row, col });
        }
    }

    // Report all issues at once
    if (!invalidSeats.empty() || !reservedSeats.empty()) {
        if (!invalidSeats.empty()) {
            std::cout << "Error: The following seats are invalid:\n";
            for (const auto& seat : invalidSeats) {
                std::cout << "  - R" << seat.first << "C" << seat.second << '\n';
            }
        }
        if (!reservedSeats.empty()) {
            std::cout << "Error: The following seats are already reserved:\n";
            for (const auto& seat : reservedSeats) {
                std::cout << "  - R" << seat.first << "C" << seat.second << '\n';
            }
        }
        std::cout << "Please select different seats.\n";
        return false;
    }

    // If all seats are valid and available, mark them as reserved
    for (const auto& seat : selectedSeats) {
        screening.seatingArrangement[seat.first - 1][seat.second - 1].status = 'R';
    }

    return true;
}

bool CinemaSelection::makeReservation() {
    if (selectedCinemaIndex < 0 || selectedCinemaIndex >= static_cast<int>(cinemaList.size())) {
        std::cout << "No cinema selected. Cannot make reservation.\n";
        return false;
    }

    Cinema& cinema = cinemaList[selectedCinemaIndex]; // Use non-const reference
    int hallChoice = 0;
    int movieChoice = 0;

    std::cout << "\nSelect a hall by number (1-" << cinema.halls.size() << "): ";
    std::cin >> hallChoice;
    if (hallChoice < 1 || static_cast<size_t>(hallChoice) > cinema.halls.size()) {
        std::cout << "Invalid hall choice.\n";
        return false;
    }

    Hall& hall = cinema.halls[hallChoice - 1]; // Use non-const reference

    std::cout << "Select a movie by number (1-" << hall.screenings.size() << "): ";
    std::cin >> movieChoice;
    system("cls");
    if (movieChoice < 1 || static_cast<size_t>(movieChoice) > hall.screenings.size()) {
        std::cout << "Invalid movie choice.\n";
        return false;
    }

    Screening& selectedScreening = hall.screenings[movieChoice - 1]; // Use non-const reference

    // === Seating Selection Logic ===
    std::vector<std::pair<int, int>> seatsToReserve;
    int numSeats;
    double totalCost = 0.0;

    bool seatsSelectedSuccessfully = false;
    while (!seatsSelectedSuccessfully) {
        displaySeatingChart(selectedScreening);
        std::cout << "\nHow many seats would you like to reserve? ";
        std::cin >> numSeats;

        if (numSeats <= 0) {
            std::cout << "Invalid number of seats.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            continue;
        }

        seatsToReserve.clear(); // Clear previous selections
        std::cout << "Enter the row and column of each seat (e.g., '1 5' for row 1, column 5):\n";
        for (int i = 0; i < numSeats; ++i) {
            int row, col;
            std::cout << "Seat " << i + 1 << ": ";
            std::cin >> row >> col;
            seatsToReserve.push_back({ row, col });
        }
        system("cls");

        // Attempt to reserve the seats. If it fails, the loop continues.
        seatsSelectedSuccessfully = reserveSeats(selectedScreening, seatsToReserve);
        if (!seatsSelectedSuccessfully) {
            std::cout << "Please re-select your seats.\n";
        }
    }
    // === End of Seating Selection Logic ===

    // Calculate total cost
    for (const auto& seat : seatsToReserve) {
        totalCost += selectedScreening.seatingArrangement[seat.first - 1][seat.second - 1].price;
    }

    std::cout << "\nTotal cost for " << seatsToReserve.size() << " seat(s): $" << std::fixed << std::setprecision(2) << totalCost << '\n';

    std::cout << "\nChoose payment method:\n";
    std::cout << "1. Cash (Pay at cinema)\n";
    std::cout << "2. Card (Pay now)\n";
    int paymentOption;
    std::cin >> paymentOption;
    system("cls");

    std::string paymentMethod;
    if (paymentOption == 1) {
        paymentMethod = "Cash";
        std::cout << "Payment will be made at the cinema. Reservation held.\n";
    }
    else if (paymentOption == 2) {
        std::string cardNumber, expiryDate, cvv;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        std::cout << "Enter card number: ";
        std::getline(std::cin, cardNumber);
        std::cout << "Enter expiry date (MM/YY): ";
        std::getline(std::cin, expiryDate);
        std::cout << "Enter CVV: ";
        std::getline(std::cin, cvv);
        paymentMethod = "Card";
        std::cout << "Payment successful. Reservation confirmed.\n";
    }
    else {
        std::cout << "Invalid payment method.\n";
        return false;
    }

    currentReservation = {
        cinema.name,
        hall.hallName,
        selectedScreening,
        paymentMethod
    };

    std::cout << "\nReservation Summary:\n";
    std::cout << "Cinema: " << currentReservation.cinemaName << '\n';
    std::cout << "Hall: " << currentReservation.hallName << '\n';
    std::cout << "Movie: " << currentReservation.screening.movieTitle << '\n';
    std::cout << "Time: " << currentReservation.screening.showTime << '\n';
    std::cout << "Seats Reserved: ";
    for (const auto& seat : seatsToReserve) {
        std::cout << "R" << seat.first << "C" << seat.second << " (" << selectedScreening.seatingArrangement[seat.first - 1][seat.second - 1].ticketType << ") ";
    }
    std::cout << '\n';
    std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << totalCost << '\n';
    std::cout << "Payment Method: " << currentReservation.paymentMethod << '\n';

    return true;
}

std::string CinemaSelection::getSelectedCinemaName() const {
    if (selectedCinemaIndex >= 0 && selectedCinemaIndex < static_cast<int>(cinemaList.size())) {
        return cinemaList[selectedCinemaIndex].name;
    }
    return "No cinema selected.";
}

bool CinemaSelection::matchesCriteria(const Screening& screening,
    const std::string& title,
    const std::string& language,
    const std::string& genre,
    const std::string& releaseDate) const
{
    bool titleMatch = title.empty() || screening.movieTitle.find(title) != std::string::npos;
    bool languageMatch = language.empty() || screening.language == language;
    bool genreMatch = genre.empty() || screening.genre == genre;
    bool releaseDateMatch = releaseDate.empty() || screening.releaseDate == releaseDate;

    return titleMatch && languageMatch && genreMatch && releaseDateMatch;
}

void CinemaSelection::searchMovies() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    std::string title, language, genre, releaseDate;

    std::cout << "Enter movie title to search (leave empty for any): ";
    std::getline(std::cin, title);

    std::cout << "Enter language to search (leave empty for any): ";
    std::getline(std::cin, language);

    std::cout << "Enter genre to search (leave empty for any): ";
    std::getline(std::cin, genre);

    std::cout << "Enter release date to search (YYYY-MM-DD, leave empty for any): ";
    std::getline(std::cin, releaseDate);
    system("cls");

    bool foundAny = false;

    std::cout << "\nSearch Results:\n";

    for (const auto& cinema : cinemaList) {
        for (const auto& hall : cinema.halls) {
            for (const auto& screening : hall.screenings) {
                if (matchesCriteria(screening, title, language, genre, releaseDate)) {
                    foundAny = true;
                    std::cout << "Cinema: " << cinema.name
                        << ", Hall: " << hall.hallName
                        << ", Movie: " << screening.movieTitle
                        << ", Language: " << screening.language
                        << ", Genre: " << screening.genre
                        << ", Release Date: " << screening.releaseDate
                        << ", Show Time: " << screening.showTime
                        << '\n';
                }
            }
        }
    }

    if (!foundAny) {
        std::cout << "No movies matched your search criteria.\n";
    }
}


