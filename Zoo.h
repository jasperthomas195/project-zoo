#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <vector>
#include "Living.h"
#include "Visitor.h"
#include "Living_Animal.h"
#include "Living_Animal_Mammal.h"
#include "Living_Zookeeper.h"
#include "Finances.h"
#include "Enclosure.h" 

class Zoo {
private:
    int visitors_today;
    double average_visitor_satisfaction;
    std::vector<Visitor*> visitors;
    std::vector<Living_Zookeeper*> staff;
    std::vector<Living_Animal_Mammal*> mammals;
    std::vector<Living_Animal_Amphibian*> amphibians;
    std::vector<Living_Animal_Avian*> avians;
    Finances finances;
    Enclosure mammalEnclosure;
    Enclosure amphibianEnclosure;
    Enclosure avianEnclosure;

    void hire_zookeeper();
    void fire_zookeeper();
    void buy_amphibian();
    void buy_mammal();
    void buy_avian();

public:
    Zoo(double initialBalance);
    ~Zoo();

    void open_for_day();
    void close_for_day();
    void admit_visitor(Visitor* visitor);
    void manage_animals();
    void manage_staff();
    void save_game();
    void sell_animal();

    int getVisitorsToday() const;
    double getAverageVisitorSatisfaction() const;
};

#endif
