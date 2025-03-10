#include <iostream>
#include "citySelection.h"

void selectCinemasInSofia() {
    int cinemaChoice;

    std::cout << "Choose a cinema in Sofia by entering a number (1-3):" << std::endl;
    std::cout << "1. Cinema City" << std::endl;
    std::cout << "2. Arena Cinema" << std::endl;
    std::cout << "3. Cine Grand" << std::endl;

    std::cin >> cinemaChoice;

    switch (cinemaChoice) {
    case 1:
        std::cout << "You chose Cinema City!" << std::endl;
        break;
    case 2:
        std::cout << "You chose Arena Cinema!" << std::endl;
        break;
    case 3:
        std::cout << "You chose Cine Grand!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice! Please select a valid cinema." << std::endl;
        break;
    }
}

void selectCinemasInPlovdiv() {
    int cinemaChoice;

    std::cout << "Choose a cinema in Plovdiv by entering a number (1-2):" << std::endl;
    std::cout << "1. Cinema City Plovdiv" << std::endl;
    std::cout << "2. Lucky Cinema" << std::endl;

    std::cin >> cinemaChoice;

    switch (cinemaChoice) {
    case 1:
        std::cout << "You chose Cinema City Plovdiv!" << std::endl;
        break;
    case 2:
        std::cout << "You chose Lucky Cinema!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice! Please select a valid cinema." << std::endl;
        break;
    }
}

void selectCinemasInVarna() {
    int cinemaChoice;

    std::cout << "Choose a cinema in Varna by entering a number (1-2):" << std::endl;
    std::cout << "1. Cinema City Varna" << std::endl;
    std::cout << "2. G8 Cinema" << std::endl;

    std::cin >> cinemaChoice;

    switch (cinemaChoice) {
    case 1:
        std::cout << "You chose Cinema City Varna!" << std::endl;
        break;
    case 2:
        std::cout << "You chose G8 Cinema!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice! Please select a valid cinema." << std::endl;
        break;
    }
}

void selectCinemasInBurgas() {
    int cinemaChoice;

    std::cout << "Choose a cinema in Burgas by entering a number (1-2):" << std::endl;
    std::cout << "1. Cinema City Burgas" << std::endl;
    std::cout << "2. Arena Burgas" << std::endl;

    std::cin >> cinemaChoice;

    switch (cinemaChoice) {
    case 1:
        std::cout << "You chose Cinema City Burgas!" << std::endl;
        break;
    case 2:
        std::cout << "You chose Arena Burgas!" << std::endl;
        break;
    default:
        std::cout << "Invalid choice! Please select a valid cinema." << std::endl;
        break;
    }
}

void selectCinemasInRuse() {
    int cinemaChoice;

    std::cout << "Choose a cinema in Ruse by entering a number (1-2):" << std::endl;
    std::cout << "1. Cinema City Ruse" << std::endl;
    std::cout << "2. Ruse Cinema" << std::endl;


    while (true) {
        std::cin >> cinemaChoice;

        if (cinemaChoice >= 1 && cinemaChoice <= 2) {
            switch (cinemaChoice) {
            case 1:
                std::cout << "You chose Cinema City Ruse!" << std::endl;
                break;
            case 2:
                std::cout << "You chose Ruse Cinema!" << std::endl;
                break;
           
            }
        }
        else {
            std::cout << "Invalid choice! Please enter a number between 1 and 3." << std::endl;

        }
    }
}

void selectCity() {
    int cityChoice;

    while (true) { 
        std::cout << "Choose a city in Bulgaria by entering a number (1-5):" << std::endl;
        std::cout << "1. Sofia" << std::endl;
        std::cout << "2. Plovdiv" << std::endl;
        std::cout << "3. Varna" << std::endl;
        std::cout << "4. Burgas" << std::endl;
        std::cout << "5. Ruse" << std::endl;

        std::cin >> cityChoice;

        if (cityChoice >= 1 && cityChoice <= 5) {
            switch (cityChoice) {
            case 1:
                selectCinemasInSofia(); 
                break;
            case 2:
                selectCinemasInPlovdiv();
                break;
            case 3:
                selectCinemasInVarna(); 
                break;
            case 4:
                selectCinemasInBurgas(); 
                break;
            case 5:
                selectCinemasInRuse(); 
                break;
            }
            break; 
        }
        else {
            system("CLS");
            std::cout << "Invalid choice! Please enter a number between 1 and 5." << std::endl;
        }
    }
}