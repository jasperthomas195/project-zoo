#ifndef LIVING_ANIMAL_AMPHIBIAN_H
#define LIVING_ANIMAL_AMPHIBIAN_H

#include "Living_Animal.h"

class Living_Animal_Amphibian : public Living_Animal {
public:
    bool need_tank;

    // Constructor
    Living_Animal_Amphibian(const std::string& name, double height, double weight, bool need_tank);

    // Member functions
    int amphibian_cleanliness() const;
};

#endif
