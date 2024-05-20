#include "Living_Animal_Mammal.h"

// Constructor
Living_Animal_Mammal::Living_Animal_Mammal(const std::string& name, double height, double weight, bool need_shelter)
    : Living_Animal(name, height, weight), need_shelter(need_shelter) {}

// Calculate cleanliness
int Living_Animal_Mammal::mammal_cleanliness() const {
    return (height + weight) / 100;
}
