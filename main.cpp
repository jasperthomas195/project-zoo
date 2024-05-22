#include "Zoo.h"
#include <iostream>
#include <cstdlib> // For system("clear") or system("cls")

void clearScreen() {
#ifdef _WIN32
    system("cls");  // Use "cls" command on Windows
#else
    system("clear");  // Use "clear" command on Unix-like systems
#endif
}

void displayMenu() {
    std::cout << "Zoo Management System:\n";
    std::cout << "1. Open the zoo for the day\n";
    std::cout << "2. Manage animals\n";
    std::cout << "3. Manage staff\n";
    std::cout << "4. Close the zoo for the day\n";
    std::cout << "5. Check current balance\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    double initial_balance;
    std::cout << "Enter initial balance for the zoo: ";
    std::cin >> initial_balance;

    Zoo myZoo(initial_balance);
    int choice;

    do {
        clearScreen();
        displayMenu();
        std::cin >> choice;

        clearScreen(); // Clear screen before displaying the result

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
                std::cout << "Current balance: $" << myZoo.get_zoo_balance() << std::endl;
                break;
            case 6:
                std::cout << "Exiting the zoo management system.\n";
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