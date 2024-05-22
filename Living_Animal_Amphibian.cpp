#include "Living_Animal_Amphibian.h"

// Constructor
Living_Animal_Amphibian::Living_Animal_Amphibian(const std::string& name, double height, double weight, bool need_tank)
    : Living_Animal(name, height, weight), need_tank(need_tank) {}

// Calculate cleanliness
int Living_Animal_Amphibian::amphibian_cleanliness() const {
    return (height + weight) / 100;
}
