#include <iostream>
#include "Zoo.h"
#include "Visitor.h"
#include "Living_Zookeeper.h"
#include "Living_Animal_Mammal.h"
#include "Living_Animal_Amphibian.h"
#include "Living_Animal_Avian.h"

void display_menu() {
    std::cout << "\nZoo Management Menu:\n";
    std::cout << "1. Open Zoo for Day\n";
    std::cout << "2. Close Zoo for Day\n";
    std::cout << "3. Admit Visitors\n";
    std::cout << "4. Manage Animals\n";
    std::cout << "5. Manage Staff\n";
    std::cout << "6. View Zoo Status\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Zoo myZoo(5000.0);

    // Add some initial animals
    myZoo.buy_mammal();
    myZoo.buy_amphibian();
    myZoo.buy_avian();

    // Add some zookeepers
    myZoo.hire_zookeeper();
    myZoo.hire_zookeeper();

    bool running = true;
    int choice;

    while (running) {
        display_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nOpening the zoo for the day...\n";
                myZoo.open_for_day();
                break;
            
            case 2:
                std::cout << "\nClosing the zoo for the day...\n";
                myZoo.close_for_day();
                break;

            case 3: {
                int num_visitors;
                std::cout << "\nEnter the number of visitors to admit: ";
                std::cin >> num_visitors;
                for (int i = 0; i < num_visitors; ++i) {
                    Visitor* visitor = new Visitor();
                    myZoo.admit_visitor(visitor);
                }
                break;
            }

            case 4:
                std::cout << "\nManaging animals...\n";
                myZoo.manage_animals();
                break;

            case 5:
                std::cout << "\nManaging staff...\n";
                myZoo.manage_staff();
                break;

            case 6:
                std::cout << "\nZoo Status:\n";
                std::cout << "Total Visitors Today: " << myZoo.get_visitors_today() << std::endl;
                std::cout << "Average Visitor Satisfaction: " << myZoo.get_average_visitor_satisfaction() << std::endl;
                std::cout << "Zoo Balance: $" << myZoo.get_zoo_balance() << std::endl;
                break;

            case 7:
                running = false;
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    std::cout << "Exiting Zoo Management System.\n";
    return 0;
}
