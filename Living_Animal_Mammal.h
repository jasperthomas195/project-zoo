#ifndef LIVING_ANIMAL_MAMMAL_H
#define LIVING_ANIMAL_MAMMAL_H

#include "Living_Animal.h"

class Living_Animal_Mammal : public Living_Animal {
public:
    bool need_shelter;

    // Constructor
    Living_Animal_Mammal(const std::string& name, double height, double weight, bool need_shelter);

    // Member functions
    int mammal_cleanliness() const;
};

#endif
