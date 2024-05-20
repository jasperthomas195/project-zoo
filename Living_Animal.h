#ifndef LIVING_ANIMAL_H
#define LIVING_ANIMAL_H

#include "Living.h"

class Living_Animal : public Living {
public:
    int hunger_level;
    int happiness_level;
    bool is_dead;
    int visitors_per_hour;
    double height;
    double weight;

    // Constructor
    Living_Animal(const std::string& name, double height, double weight);

    // Member functions
    float hunger_rate() const;
    void hunger_happiness_relationship();
    void cleanliness_happiness_relationship(int cleanliness);
    void feed(int food_amount);
};

#endif
