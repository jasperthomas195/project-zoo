#include "Living_Animal.h"
#include <iostream>

// Constructor
Living_Animal::Living_Animal(const std::string& name, double height, double weight)
    : Living(name, false), hunger_level(100), happiness_level(100), is_dead(false), visitors_per_hour(10), height(height), weight(weight) {}

// Calculate hunger rate
float Living_Animal::hunger_rate() const {
    return (height * weight) / 100.0;
}

// Adjust happiness based on hunger level
void Living_Animal::hunger_happiness_relationship() {
    while (hunger_level < 50) {
        happiness_level--;
        std::cout << "Happiness level: " << happiness_level << std::endl;
    }
}

float Living_Animal::get_hunger_level() const {
    return hunger_level;
}


// Get happiness level
float Living_Animal::get_happiness_level() const {
    return happiness_level;
}

// Adjust happiness based on cleanliness
void Living_Animal::cleanliness_happiness_relationship(int cleanliness) {
    while (cleanliness < 50) {
        happiness_level--;
        std::cout << "Happiness level: " << happiness_level << std::endl;
    }
}

void Living_Animal::decrease_levels(int num_zookeepers) {
    int hunger_decrease = 10 - num_zookeepers; // Reduce hunger decrease by the number of zookeepers
    int happiness_decrease = 5 - num_zookeepers; // Reduce happiness decrease by the number of zookeepers

    if (hunger_decrease < 0) hunger_decrease = 0;
    if (happiness_decrease < 0) happiness_decrease = 0;

    hunger_level -= hunger_decrease;
    happiness_level -= happiness_decrease;

    if (hunger_level < 0) hunger_level = 0;
    if (happiness_level < 0) happiness_level = 0;
}

void Living_Animal::check_levels() {
    if (hunger_level < 0) {
        hunger_level = 0; // Ensure hunger level doesn't go below 0
    } else if (hunger_level == 100) {
        happiness_level = 100; // Reset happiness level to 100 when hunger level reaches 100
    }
}

// Feed the animal
void Living_Animal::feed(int food_amount) {
    hunger_level = 100;
}

int Living_Animal::get_visitors_per_hour() const {
return (hunger_level < 70) ? (visitors_per_hour / 2) : visitors_per_hour;
}

std::string Living_Animal::get_name() const {
    return name;
}