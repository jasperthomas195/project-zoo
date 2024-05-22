#ifndef LIVING_H
#define LIVING_H

#include <iostream>
#include <string>

class Living {
public:
    std::string name;
    bool is_zookeeper;

    // Constructor
    Living(const std::string& name, bool is_zookeeper);
    
    // Destructor
    virtual ~Living() = default;
};

#endif