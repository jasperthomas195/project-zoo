#include "Zoo.h"
#include <iostream>
#include <cstdlib>

int main() {
    double initial_balance;
    std::cout << "Enter initial balance for the zoo: ";
    std::cin >> initial_balance;

    if (std::cin.fail()) {
    std::cerr << "Invalid initial balance. Exiting program.\n";
    return 1;
    }

    Zoo myZoo(initial_balance);
    int choice;

    do {
        myZoo.clearScreen();
        myZoo.displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
            myZoo.clearScreen();
            std::cout << "Invalid choice. Please enter a number.\n";
            std::cout << "\nPress Enter to continue...";
            std::cin.get(); // Wait for the user to press Enter
            continue; // Skip the rest of the loop and show the menu again
        }

        myZoo.clearScreen();

        switch (choice) {
            case 1:
                myZoo.open_for_day();
                break;
            case 2:
                myZoo.manage_animals();
                break;
            case 3:
                myZoo.manage_staff();
                break;
            case 4:
                myZoo.close_for_day();
                break;
            case 5:
                std::cout << "Financial summary: \n" << myZoo.get_financial_summary() << std::endl;
                break;
            case 6:
                myZoo.save_game("save_file.txt");
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        if (choice != 6) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(); // Ignore the previous newline character
            std::cin.get(); // Wait for the user to press Enter
        }

    } while (choice != 6);

    return 0;
}