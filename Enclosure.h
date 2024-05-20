#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include <vector>
#include "Living_Animal.h"
#include <iostream>

class Enclosure {
private:
    std::vector<Living_Animal*> animals; // Vector to store animals in the enclosure
    int capacity; // Maximum capacity of the enclosure

public:
    Enclosure(int initialCapacity = 15); // Constructor
    ~Enclosure(); // Destructor

    int getCapacity() const; // Getter for the maximum capacity of the enclosure
    int getAnimalCount() const; // Getter for the number of animals in the enclosure

    bool addAnimal(Animal* animal); // Add an animal to the enclosure
    bool removeAnimal(Animal* animal); // Remove an animal from the enclosure

    void upgradeCapacity(int additionalCapacity); // Upgrade the capacity of the enclosure
};

#endif