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
    // Implementation of manage_animals
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
    // Implementation of sell_animal based on type
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
