#include "Living_Animal.h"
#include <iostream>

// Constructor
Living_Animal::Living_Animal(const std::string& name, double height, double weight)
    : Living(name, false), hunger_level(100), happiness_level(100), is_dead(false), visitors_per_hour(0), height(height), weight(weight) {}

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

// Adjust happiness based on cleanliness
void Living_Animal::cleanliness_happiness_relationship(int cleanliness) {
    while (cleanliness < 50) {
        happiness_level--;
        std::cout << "Happiness level: " << happiness_level << std::endl;
    }
}

// Feed the animal
void Living_Animal::feed(int food_amount) {
    hunger_level = 100;
}