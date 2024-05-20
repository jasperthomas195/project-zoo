#include "Living_Zookeeper.h"
#include <iostream>

// Constructor
Living_Zookeeper::Living_Zookeeper(const std::string& name, double hourly_rate)
    : Living(name, true), hourly_rate(hourly_rate) {}

// Perform duties
void Living_Zookeeper::perform_duties() {
    std::cout << "Zookeeper " << name << " is performing their duties." << std::endl;
}
