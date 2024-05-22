#include "Visitor.h"
#include <cstdlib>
#include <vector>

// Constructor
Visitor::Visitor() : satisfaction_level(70), money_spent(20) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Set a random satisfaction level between 50 and 100
    satisfaction_level = std::rand() % 51 + 50;
    // Initial money spent includes the admission fee
}

// Get the visitor's current satisfaction level
int Visitor::get_satisfaction_level() const {
    return satisfaction_level;
}

// Set the visitor's satisfaction level
void Visitor::set_satisfaction_level(int level) {
    if (level < 1) {
        satisfaction_level = 1;
    } else if (level > 100) {
        satisfaction_level = 100;
    } else {
        satisfaction_level = level;
    }
}

// Get the amount of money the visitor has spent
int Visitor::get_money_spent() const {
    return money_spent;
}

// Set the amount of money the visitor has spent
void Visitor::set_money_spent(int amount) {
    if (amount < 0) {
        money_spent = 0;
    } else {
        money_spent = amount;
    }
}

// Handle a visitor making a purchase
void Visitor::make_purchase(double dollar_amount) {
    money_spent += static_cast<int>(dollar_amount);
}

// Calculate total donations based on visitor satisfaction
int Visitor::calculate_donations(const std::vector<Visitor*>& visitors) {
    int total_donations = 0;
    for (const Visitor* visitor : visitors) {
        if (visitor->get_satisfaction_level() > 90) {
            // There is a 10% chance to make a $10 donation if the visitor is very satisfied
            if (rand() % 100 < 10) {
                total_donations += 10;
            }
        }
    }
    return total_donations;
}