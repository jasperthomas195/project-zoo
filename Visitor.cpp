#include "Visitor.h"
#include <cstdlib>

// Constructor
Visitor::Visitor() : satisfaction_level(1000 + rand() % 6501), money_spent(20) {
    // Initial money spent includes the admission fee
}

// Get the visitor's current satisfaction level
int Visitor::get_SatisfactionLevel() const {
    return satisfaction_level;
}

// Set the visitor's satisfaction level
void Visitor::set_SatisfactionLevel(int level) {
    if (level < 1) {
        satisfaction_level = 1;
    } else if (level > 100) {
        satisfaction_level = 100;
    } else {
        satisfaction_level = level;
    }
}

// Get the amount of money the visitor has spent
int Visitor::get_MoneySpent() const {
    return money_spent;
}

// Set the amount of money the visitor has spent
void Visitor::set_MoneySpent(int amount) {
    if (amount < 0) {
        money_spent = 0;
    } else {
        money_spent = amount;
    }
}

// Simulate a visitor visiting an enclosure
void Visitor::visitEnclosure(Enclosure* enclosure) {
    // TO DO: Implement this function based on the enclosure and animals' state
}

// Handle a visitor making a purchase
void Visitor::makePurchase(double dollar_amount) {
    if (satisfaction_level > 90) {
        // There is a 20% chance to make a $10 donation if the visitor is very satisfied
        if (rand() % 100 < 20) { 
            money_spent += dollar_amount;
        }
    }
}