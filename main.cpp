#include <iostream>
#include <vector>
#include <memory>
#include "Zoo.h"
#include "Visitor.h"

void show_main_menu() {
    std::cout << "1. Open Zoo\n";
    std::cout << "2. Exit simulation\n";
}

void show_manage_animals_menu() {
    std::cout << "1. List animal quantity\n";
    std::cout << "2. Add new animal\n";
    std::cout << "3. Sell animal\n";
    std::cout << "4. Feed animals\n";
}

void show_add_animal_menu() {
    std::cout << "1. Add mammal\n";
    std::cout << "2. Add amphibian\n";
    std::cout << "3. Add avian\n";
}

void show_feed_animal_menu() {
    std::cout << "1. Feed mammals\n";
    std::cout << "2. Feed amphibians\n";
    std::cout << "3. Feed avians\n";
}

void show_sell_animal_menu() {
    std::cout << "1. Sell mammal\n";
    std::cout << "2. Sell amphibian\n";
    std::cout << "3. Sell avian\n";
}

void show_enclosure_menu() {
    std::cout << "1. List enclosure quantity\n";
    std::cout << "2. Add new enclosure\n";
    std::cout << "3. Clean enclosures\n";
}

void show_add_specific_animal_menu(const std::string& type) {
    if (type == "mammal") {
        std::cout << "1. Add elephant\n";
        std::cout << "2. Add lion\n";
        std::cout << "3. Add giraffe\n";
    } else if (type == "amphibian") {
        std::cout << "1. Add frog\n";
        std::cout << "2. Add axolotl\n";
        std::cout << "3. Add salamander\n";
    } else if (type == "avian") {
        std::cout << "1. Add eagle\n";
        std::cout << "2. Add kookaburra\n";
        std::cout << "3. Add falcon\n";
    }
}

int main() {
    Zoo zoo(10000);  // Starting with an initial balance of $10,000
    bool running = true;

    while (running) {
        show_main_menu();
        int main_choice;
        std::cin >> main_choice;

        if (main_choice == 1) {
            bool zoo_open = true;
            zoo.open_for_day();

            while (zoo_open) {
                std::cout << "\nZoo Management Menu:\n";
                std::cout << "1. Manage animals\n";
                std::cout << "2. Manage enclosures\n";
                std::cout << "3. Manage staff\n";
                std::cout << "4. Close zoo\n";
                int management_choice;
                std::cin >> management_choice;

                if (management_choice == 1) {
                    show_manage_animals_menu();
                    int animal_choice;
                    std::cin >> animal_choice;

                    switch (animal_choice) {
                        case 1:
                            // List animal quantity
                            std::cout << "Mammals: " << zoo.get_mammal_enclosure().get_animal_count() << "\n";
                            std::cout << "Amphibians: " << zoo.get_amphibian_enclosure().get_animal_count() << "\n";
                            std::cout << "Avians: " << zoo.get_avian_enclosure().get_animal_count() << "\n";
                            break;
                        case 2:
                            show_add_animal_menu();
                            int add_choice;
                            std::cin >> add_choice;
                            if (add_choice == 1) zoo.buy_mammal();
                            else if (add_choice == 2) zoo.buy_amphibian();
                            else if (add_choice == 3) zoo.buy_avian();
                            break;
                        case 3:
                            show_sell_animal_menu();
                            int sell_choice;
                            std::cin >> sell_choice;
                            if (sell_choice == 1) zoo.sell_animal("mammal");
                            else if (sell_choice == 2) zoo.sell_animal("amphibian");
                            else if (sell_choice == 3) zoo.sell_animal("avian");
                            break;
                        case 4:
                            show_feed_animal_menu();
                            int feed_choice;
                            std::cin >> feed_choice;
                            // Implement feeding functionality here
                            break;
                        default:
                            std::cout << "Invalid choice.\n";
                            break;
                    }
                } else if (management_choice == 2) {
                    show_enclosure_menu();
                    int enclosure_choice;
                    std::cin >> enclosure_choice;

                    switch (enclosure_choice) {
                        case 1:
                            // List enclosure quantity
                            std::cout << "Mammal Enclosures: " << zoo.get_mammal_enclosure().get_animal_count() << "\n";
                            std::cout << "Amphibian Enclosures: " << zoo.get_amphibian_enclosure().get_animal_count() << "\n";
                            std::cout << "Avian Enclosures: " << zoo.get_avian_enclosure().get_animal_count() << "\n";
                            break;
                        case 2:
                            // Add new enclosure functionality
                            break;
                        case 3:
                            // Clean enclosures functionality
                            break;
                        default:
                            std::cout << "Invalid choice.\n";
                            break;
                    }
                } else if (management_choice == 3) {
                    zoo.manage_staff();
                } else if (management_choice == 4) {
                    std::cout << "View financials? (1 for yes, 0 for no): ";
                    int view_financials;
                    std::cin >> view_financials;

                    if (view_financials == 1) {
                        std::cout << "Zoo balance: $" << zoo.get_zoo_balance() << "\n";
                    }
                    zoo.close_for_day();
                    zoo_open = false;
                } else {
                    std::cout << "Invalid choice.\n";
                }
            }
        } else if (main_choice == 2) {
            running = false;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
