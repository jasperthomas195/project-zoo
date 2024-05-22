#include "Enclosure.h"

// Constructor
Enclosure::Enclosure(int initialCapacity) : capacity(initialCapacity) {}

// Destructor
Enclosure::~Enclosure() {
    for (Living_Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

// Getter for the maximum capacity of the enclosure
int Enclosure::get_capacity() const {
    return capacity;
}

// Getter for the number of animals in the enclosure
int Enclosure::get_animal_count() const {
    return animals.size();
}

// Add an animal to the enclosure
bool Enclosure::add_animal(Living_Animal* animal) {
    if (animals.size() < capacity) {
        animals.push_back(animal);
        return true;
    }
    return false; // Unable to add animal, enclosure at maximum capacity
}

// Remove an animal from the enclosure
bool Enclosure::remove_animal(Living_Animal* animal) {
    auto it = std::find(animals.begin(), animals.end(), animal);
    if (it != animals.end()) {
        animals.erase(it);
        return true;
    }
    return false; // Animal not found in enclosure
}

void Enclosure::feed_animals() {
    for (Living_Animal* animal : animals) {
        animal->feed(100);  // Reset hunger level
    }
}

void Enclosure::show_animal_status() const {
    for (size_t i = 0; i < animals.size(); ++i) {
        std::cout << i + 1 << " | " << animals[i]->name
                  << " | Hunger Level: " << animals[i]->get_hunger_level()
                  << " | Happiness Level: " << animals[i]->get_happiness_level() << std::endl;
    }
}

// Upgrade the capacity of the enclosure
void Enclosure::upgrade_capacity(int additionalCapacity) {
    capacity += additionalCapacity;
}