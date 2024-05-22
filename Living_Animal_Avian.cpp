#include "Living_Animal_Avian.h"

// Constructor
Living_Animal_Avian::Living_Animal_Avian(const std::string& name, double height, double weight, bool need_aviary)
    : Living_Animal(name, height, weight), need_aviary(need_aviary) {}

// Calculate cleanliness
int Living_Animal_Avian::avian_cleanliness() const {
    return (height + weight) / 100;
}
