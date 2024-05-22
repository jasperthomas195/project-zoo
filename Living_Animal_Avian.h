#ifndef LIVING_ANIMAL_AVIAN_H
#define LIVING_ANIMAL_AVIAN_H

#include "Living_Animal.h"

class Living_Animal_Avian : public Living_Animal {
public:
    bool need_aviary;

    // Constructor
    Living_Animal_Avian(const std::string& name, double height, double weight, bool need_aviary);

    // Member functions
    int avian_cleanliness() const;
};

#endif