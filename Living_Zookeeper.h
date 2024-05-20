#ifndef LIVING_ZOOKEEPER_H
#define LIVING_ZOOKEEPER_H

#include "Living.h"

class Living_Zookeeper : public Living {
public:
    double hourly_rate;

    // Constructor
    Living_Zookeeper(const std::string& name, double hourly_rate);
    
    // Perform duties
    void perform_duties();
};

#endif
