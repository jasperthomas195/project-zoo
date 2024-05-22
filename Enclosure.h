#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include <vector>
#include <algorithm>
#include "Living_Animal.h"

class Enclosure {
private:
    std::vector<Living_Animal*> animals; // Vector to store animals in the enclosure
    int capacity; // Maximum capacity of the enclosure

public:
    Enclosure(int initialCapacity = 15); // Constructor
    ~Enclosure(); // Destructor

    int get_capacity() const; // Getter for the maximum capacity of the enclosure
    int get_animal_count() const; // Getter for the number of animals in the enclosure

    bool add_animal(Living_Animal* animal); // Add an animal to the enclosure
    bool remove_animal(Living_Animal* animal); // Remove an animal from the enclosure

    void upgrade_capacity(int additionalCapacity); // Upgrade the capacity of the enclosure
};

#endif
