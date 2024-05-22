#include "Zoo.h"
#include "Visitor.h"
#include <algorithm>

// Constructor
Zoo::Zoo(double initial_balance)
    : visitors_today(0),
      average_visitor_satisfaction(0.0),
      finances() {
    finances.record_income(initial_balance); // Initialize zoo with starting balance
    mammal_enclosure = Enclosure(15); // Default capacity
    amphibian_enclosure = Enclosure(10); // Default capacity
    avian_enclosure = Enclosure(20); // Default capacity
}

// Destructor
Zoo::~Zoo() {
    for (Visitor* visitor : visitors) {
        delete visitor;
    }
    for (Living_Zookeeper* zookeeper : staff) {
        delete zookeeper;
    }
}

// Open the zoo for the day
void Zoo::open_for_day() {
    visitors_today = 0;
    visitors.clear();
    std::cout << "Zoo is now open for the day." << std::endl;
}

// Close the zoo for the day
void Zoo::close_for_day() {
    double daily_income = 0.0;
    for (Visitor* visitor : visitors) {
        daily_income += visitor->get_money_spent();
    }
    daily_income += calculate_daily_donations();  // Add donations to daily income
    finances.record_income(daily_income);
    average_visitor_satisfaction = calculate_average_visitor_satisfaction();
    std::cout << "Zoo is now closed for the day." << std::endl;
}

// Admit a visitor to the zoo
void Zoo::admit_visitor(Visitor* visitor) {
    visitors_today++;
    visitors.push_back(visitor);
}

// Manage animals in the zoo
void Zoo::manage_animals() {
    int choice;
    std::cout << "Manage Animals Menu:\n";
    std::cout << "1. Buy Amphibian\n";
    std::cout << "2. Buy Mammal\n";
    std::cout << "3. Buy Avian\n";
    std::cout << "4. Sell an animal\n";
    std::cout << "5. Feed animals\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            buy_amphibian();
            break;
        case 2:
            buy_mammal();
            break;
        case 3:
            buy_avian();
            break;
        case 4: {
            std::cout << "Enter the type of animal to sell (mammal, amphibian, avian): ";
            std::string type;
            std::cin >> type;
            sell_animal(type);
            break;
        }
        default:
            std::cout << "Invalid choice\n";
    }
}

// Manage staff in the zoo
void Zoo::manage_staff() {
    int choice;
    std::cout << "Manage Staff Menu:\n";
    std::cout << "1. Hire Zookeeper\n";
    std::cout << "2. Fire Zookeeper\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            hire_zookeeper();
            break;
        case 2:
            fire_zookeeper();
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

// Sell an animal from the zoo
void Zoo::sell_animal(const std::string& type) {
    if (type == "mammal") {
        if (mammals.empty()) {
            std::cout << "Error: No mammals available for sale.\n";
            return;
        }
        std::cout << "Mammals available for sale:\n";
        for (size_t i = 0; i < mammals.size(); ++i) {
            std::cout << i + 1 << " | " << mammals[i]->name << std::endl;
        }
        std::cout << "Enter the index of the mammal you want to sell (1 - " << mammals.size() << "): ";
        size_t index;
        std::cin >> index;
        if (index >= 1 && index <= mammals.size()) {
            Living_Animal* animalSold = mammals[index - 1];
            double animalValue = 0.90 * 5000; // Assuming getValue() method exists in Living_Animal
            finances.record_income(animalValue);
            delete animalSold;
            mammals.erase(mammals.begin() + index - 1);
            std::cout << "Mammal sold successfully, balance increased by $" << animalValue << ".\n";
        } else {
            std::cout << "Invalid index\n";
        }
    } else if (type == "amphibian") {
        if (amphibians.empty()) {
            std::cout << "Error: No amphibians available for sale.\n";
            return;
        }
        std::cout << "Amphibians available for sale:\n";
        for (size_t i = 0; i < amphibians.size(); ++i) {
            std::cout << i + 1 << " | " << amphibians[i]->name << std::endl;
        }
        std::cout << "Enter the index of the amphibian you want to sell (1 - " << amphibians.size() << "): ";
        size_t index;
        std::cin >> index;
        if (index >= 1 && index <= amphibians.size()) {
            Living_Animal* animalSold = amphibians[index - 1];
            double animalValue = 0.90 * 100; // Assuming getValue() method exists in Living_Animal
            finances.record_income(animalValue);
            delete animalSold;
            amphibians.erase(amphibians.begin() + index - 1);
            std::cout << "Amphibian sold successfully, balance increased by $" << animalValue << ".\n";
        } else {
            std::cout << "Invalid index\n";
        }
    } else if (type == "avian") {
        if (avians.empty()) {
            std::cout << "Error: No avians available for sale.\n";
            return;
        }
        std::cout << "Avians available for sale:\n";
        for (size_t i = 0; i < avians.size(); ++i) {
            std::cout << i + 1 << " | " << avians[i]->name << std::endl;
        }
        std::cout << "Enter the index of the avian you want to sell (1 - " << avians.size() << "): ";
        size_t index;
        std::cin >> index;
        if (index >= 1 && index <= avians.size()) {
            Living_Animal* animalSold = avians[index - 1];
            double animalValue = 0.90 * 500; // Assuming getValue() method exists in Living_Animal
            finances.record_income(animalValue);
            delete animalSold;
            avians.erase(avians.begin() + index - 1);
            std::cout << "Avian sold successfully, balance increased by $" << animalValue << ".\n";
        } else {
            std::cout << "Invalid index\n";
        }
    } else {
        std::cout << "Error: Unknown animal type.\n";
    }
}

// Calculate daily donations from visitors
int Zoo::calculate_daily_donations() const {
    return Visitor::calculate_donations(visitors);
}

// Get the number of visitors today
int Zoo::get_visitors_today() const {
    return visitors_today;
}

// Get the average visitor satisfaction
double Zoo::get_average_visitor_satisfaction() const {
    return average_visitor_satisfaction;
}

// Get the zoo's balance
double Zoo::get_zoo_balance() const {
    return finances.get_balance();
}

// Private member functions to hire and fire zookeepers
void Zoo::hire_zookeeper() {
    Living_Zookeeper* zookeeper = new Living_Zookeeper("John", 20.0);
    staff.push_back(zookeeper);
    finances.record_expense(zookeeper->hourly_rate * 8); // Assume an 8-hour workday
    std::cout << "Hired a new zookeeper." << std::endl;
}

void Zoo::fire_zookeeper() {
    if (!staff.empty()) {
        finances.record_expense(-staff.back()->hourly_rate * 8); // Refund the expense for the fired zookeeper
        delete staff.back();
        staff.pop_back();
        std::cout << "Fired a zookeeper." << std::endl;
    } else {
        std::cout << "No zookeepers to fire." << std::endl;
    }
}

// Private member functions to buy animals
void Zoo::buy_amphibian() {
    double price = 100;
    if (finances.get_balance() >= price) {
        Living_Animal_Amphibian* newAmphibian = new Living_Animal_Amphibian("Amphibian", 1.0, 1.0, true); // Example: all mammals need shelter
        if (amphibian_enclosure.add_animal(newAmphibian)) {
            amphibians.push_back(newAmphibian);
            finances.record_expense(price);
            std::cout << "Bought a new amphibian!" << std::endl;
            std::cout << "Current number of amphibians: " << amphibians.size() << std::endl;
        } else {
            std::cout << "Enclosure is full, cannot add new amphibian!" << std::endl;
            delete newAmphibian;
        }
    } else {
        std::cout << "Not enough funds to buy a new mammal!" << std::endl;
    }
}

void Zoo::buy_mammal() {
    double price = 5000;
    if (finances.get_balance() >= price) {
        Living_Animal_Mammal* newMammal = new Living_Animal_Mammal("Mammal", 5.0, 4.0, true); // Example: all mammals need shelter
        if (mammal_enclosure.add_animal(newMammal)) {
            mammals.push_back(newMammal);
            finances.record_expense(price);
            std::cout << "Bought a new mammal!" << std::endl;
            std::cout << "Current number of mammals: " << mammals.size() << std::endl;
        } else {
            std::cout << "Enclosure is full, cannot add new mammal!" << std::endl;
            delete newMammal;
        }
    } else {
        std::cout << "Not enough funds to buy a new mammal!" << std::endl;
    }
}

void Zoo::buy_avian() {
    double price = 500;
    if (finances.get_balance() >= price) {
        Living_Animal_Avian* newAvian = new Living_Animal_Avian("Avian", 2.0, 1.0, true); // Example: all mammals need shelter
        if (avian_enclosure.add_animal(newAvian)) {
            avians.push_back(newAvian);
            finances.record_expense(price);
            std::cout << "Bought a new avian!" << std::endl;
            std::cout << "Current number of avians: " << avians.size() << std::endl;
        } else {
            std::cout << "Enclosure is full, cannot add new avian!" << std::endl;
            delete newAvian;
        }
    } else {
        std::cout << "Not enough funds to buy a new avian!" << std::endl;
    }
}

// Helper function to calculate average visitor satisfaction
double Zoo::calculate_average_visitor_satisfaction() const {
    if (visitors.empty()) return 0.0;
    double total_satisfaction = 0.0;
    for (const Visitor* visitor : visitors) {
        total_satisfaction += visitor->get_satisfaction_level();
    }
    return total_satisfaction / visitors.size();
}
