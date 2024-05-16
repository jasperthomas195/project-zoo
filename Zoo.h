#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <vector>
#include "Visitor.h"
#include "Living_Animal.h"
#include "Living_Zookeeper.h"
#include "Finances.h"
#include "Enclosure.h" 

class Zoo {
private:
    std::vector<Visitor*> visitors;
    std::vector<Living_Animal*> animals;
    std::vector<Living_Zookeeper*> staff;
    Finances finances;
    std::vector<Enclosure*> enclosures;

    int visitors_today;
    double average_visitor_satisfaction;

    void hire_zookeeper();
    void fire_zookeeper();
    void buy_amphibian();
    void buy_mammal();
    void buy_avian();

public:
    Zoo();
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
