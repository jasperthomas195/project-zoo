#include "Enclosure.h"


Enclosure::Enclosure(int initialCapacity) : capacity(initialCapacity) {}

Enclosure::~Enclosure() {
    for (Living_Animal* animal : animals) {
        delete animal;
    }
animals.clear();
}

int Enclosure::getCapacity() const {
    return capacity;
}

int Enclosure::getAnimalCount() const {
    return animals.size();
}

bool Enclosure::addAnimal(Living_Animal* animal) {
    if (animals.size() < capacity) {
        animals.push_back(animal);
        return true;
    }
    return false; // Unable to add animal, enclosure at maximum capacity
}

bool Enclosure::removeAnimal(Living_Animal* animal) {
    auto it = std::find(animals.begin(), animals.end(), animal);
    if (it != animals.end()) {
        animals.erase(it);
        return true;
    }
    return false; // Animal not found in enclosure
}

void Enclosure::upgradeCapacity(int additionalCapacity) {
    capacity += additionalCapacity;
}