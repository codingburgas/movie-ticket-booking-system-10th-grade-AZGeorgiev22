#include <iostream>
#include"cinemaSelection.h"

void CinemaSelection::addShow() {
    std::cout << "--- Add a New Show ---\n";
    displayCinemas();
    std::cout << "Select a cinema by number: ";
    int cinemaChoice;
    std::cin >> cinemaChoice;
    system("cls");
    if (cinemaChoice < 1 || static_cast<size_t>(cinemaChoice) > cinemaList.size()) {
        std::cout << "Invalid cinema selection.\n";
        return;
    }

    Cinema& cinema = cinemaList[cinemaChoice - 1];

    std::cout << "Select a hall in " << cinema.name << " by number:\n";
    for (size_t i = 0; i < cinema.halls.size(); ++i) {
        std::cout << i + 1 << ". " << cinema.halls[i].hallName << '\n';
    }
    int hallChoice;
    std::cin >> hallChoice;
    system("cls");
    if (hallChoice < 1 || static_cast<size_t>(hallChoice) > cinema.halls.size()) {
        std::cout << "Invalid hall selection.\n";
        return;
    }

    Hall& hall = cinema.halls[hallChoice - 1];
    Screening newScreening;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter movie title: ";
    std::getline(std::cin, newScreening.movieTitle);
    std::cout << "Enter language: ";
    std::getline(std::cin, newScreening.language);
    std::cout << "Enter genre: ";
    std::getline(std::cin, newScreening.genre);
    std::cout << "Enter release date (YYYY-MM-DD): ";
    std::getline(std::cin, newScreening.releaseDate);
    std::cout << "Enter show time (e.g., 2:00 PM): ";
    std::getline(std::cin, newScreening.showTime);

    initializeSeating(newScreening, 5, 10); // Default 5x10 seating for new shows

    hall.screenings.push_back(newScreening);
    system("cls");
    std::cout << "Show for '" << newScreening.movieTitle << "' added to " << cinema.name << " - " << hall.hallName << ".\n";
}

void CinemaSelection::deleteShow() {
    std::cout << "--- Delete a Show ---\n";
    displayCinemas();
    std::cout << "Select a cinema by number: ";
    int cinemaChoice;
    std::cin >> cinemaChoice;
    system("cls");
    if (cinemaChoice < 1 || static_cast<size_t>(cinemaChoice) > cinemaList.size()) {
        std::cout << "Invalid cinema selection.\n";
        return;
    }

    Cinema& cinema = cinemaList[cinemaChoice - 1];
    std::cout << "Select a hall in " << cinema.name << " by number:\n";
    for (size_t i = 0; i < cinema.halls.size(); ++i) {
        std::cout << i + 1 << ". " << cinema.halls[i].hallName << '\n';
    }
    int hallChoice;
    std::cin >> hallChoice;
    system("cls");
    if (hallChoice < 1 || static_cast<size_t>(hallChoice) > cinema.halls.size()) {
        std::cout << "Invalid hall selection.\n";
        return;
    }

    Hall& hall = cinema.halls[hallChoice - 1];
    if (hall.screenings.empty()) {
        std::cout << "No shows to delete in this hall.\n";
        return;
    }

    std::cout << "Select a show to delete:\n";
    for (size_t i = 0; i < hall.screenings.size(); ++i) {
        std::cout << i + 1 << ". " << hall.screenings[i].movieTitle << " at " << hall.screenings[i].showTime << '\n';
    }
    int showChoice;
    std::cin >> showChoice;
    system("cls");
    if (showChoice < 1 || static_cast<size_t>(showChoice) > hall.screenings.size()) {
        std::cout << "Invalid show selection.\n";
        return;
    }

    std::string deletedMovieTitle = hall.screenings[showChoice - 1].movieTitle;
    hall.screenings.erase(hall.screenings.begin() + showChoice - 1);
    std::cout << "Show for '" << deletedMovieTitle << "' has been deleted.\n";
}

void CinemaSelection::updateShow() {
    std::cout << "--- Update a Show's Time ---\n";
    displayCinemas();
    std::cout << "Select a cinema by number: ";
    int cinemaChoice;
    std::cin >> cinemaChoice;
    system("cls");
    if (cinemaChoice < 1 || static_cast<size_t>(cinemaChoice) > cinemaList.size()) {
        std::cout << "Invalid cinema selection.\n";
        return;
    }

    Cinema& cinema = cinemaList[cinemaChoice - 1];
    std::cout << "Select a hall in " << cinema.name << " by number:\n";
    for (size_t i = 0; i < cinema.halls.size(); ++i) {
        std::cout << i + 1 << ". " << cinema.halls[i].hallName << '\n';
    }
    int hallChoice;
    std::cin >> hallChoice;
    system("cls");
    if (hallChoice < 1 || static_cast<size_t>(hallChoice) > cinema.halls.size()) {
        std::cout << "Invalid hall selection.\n";
        return;
    }

    Hall& hall = cinema.halls[hallChoice - 1];
    if (hall.screenings.empty()) {
        std::cout << "No shows to update in this hall.\n";
        return;
    }

    std::cout << "Select a show to update:\n";
    for (size_t i = 0; i < hall.screenings.size(); ++i) {
        std::cout << i + 1 << ". " << hall.screenings[i].movieTitle << " at " << hall.screenings[i].showTime << '\n';
    }
    int showChoice;
    std::cin >> showChoice;
    system("cls");
    if (showChoice < 1 || static_cast<size_t>(showChoice) > hall.screenings.size()) {
        std::cout << "Invalid show selection.\n";
        return;
    }

    Screening& screeningToUpdate = hall.screenings[showChoice - 1];
    std::string oldShowTime = screeningToUpdate.showTime;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the new show time for '" << screeningToUpdate.movieTitle << "' (e.g., 5:00 PM): ";
    std::getline(std::cin, screeningToUpdate.showTime);
    system("cls");

    std::cout << "Show time for '" << screeningToUpdate.movieTitle << "' updated from " << oldShowTime << " to " << screeningToUpdate.showTime << ".\n";
}

void CinemaSelection::addMovie() {
    std::cout << "--- Add a New Movie to all Halls ---\n";
    Screening newMovie;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter movie title: ";
    std::getline(std::cin, newMovie.movieTitle);
    std::cout << "Enter language: ";
    std::getline(std::cin, newMovie.language);
    std::cout << "Enter genre: ";
    std::getline(std::cin, newMovie.genre);
    std::cout << "Enter release date (YYYY-MM-DD): ";
    std::getline(std::cin, newMovie.releaseDate);

    // This function adds a new movie, but doesn't add it as a show to any hall.
    std::cout << "Movie '" << newMovie.movieTitle << "' added to the system. You can now add a show for it.\n";
}

void CinemaSelection::deleteMovie() {
    std::cout << "--- Delete a Movie from all Shows ---\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the title of the movie to delete: ";
    std::string movieTitleToDelete;
    std::getline(std::cin, movieTitleToDelete);
    system("cls");

    bool found = false;
    for (auto& cinema : cinemaList) {
        for (auto& hall : cinema.halls) {
            //  remove_if  finds and removes all screenings with the given movie title
            auto it = std::remove_if(hall.screenings.begin(), hall.screenings.end(),
                [&](const Screening& screening) {
                    if (screening.movieTitle == movieTitleToDelete) {
                        found = true;
                        return true; // Mark for removal
                    }
                    return false;
                });
            hall.screenings.erase(it, hall.screenings.end());
        }
    }

    if (found) {
        std::cout << "All shows for '" << movieTitleToDelete << "' have been deleted from the schedule.\n";
    }
    else {
        std::cout << "Movie '" << movieTitleToDelete << "' not found in any show schedule.\n";
    }
}