#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <vector>
#include "Living.h"
#include "Visitor.h"
#include "Living_Animal.h"
#include "Living_Animal_Mammal.h"
#include "Living_Animal_Amphibian.h"
#include "Living_Animal_Avian.h"
#include "Living_Zookeeper.h"
#include "Finances.h"
#include "Enclosure.h"
#include <string>

class Zoo {
private:
    int visitors_today;
    double average_visitor_satisfaction;
    std::vector<Living_Zookeeper*> staff;
    std::vector<Visitor*> visitors;
    std::vector<Living_Animal_Mammal*> mammals;
    std::vector<Living_Animal_Amphibian*> amphibians;
    std::vector<Living_Animal_Avian*> avians;
    Enclosure mammal_enclosure;
    Enclosure amphibian_enclosure;
    Enclosure avian_enclosure;
    Finances finances;

    double calculate_average_visitor_satisfaction() const;

public:
    Zoo(double initial_balance);
    ~Zoo();

    void open_for_day();
    void close_for_day();
    void admit_visitor(Visitor* visitor);
    void manage_animals();
    void manage_staff();
    void sell_animal();
    int calculate_daily_donations() const;

    int get_visitors_today() const;
    double get_average_visitor_satisfaction() const;
    double get_zoo_balance() const;

    void hire_zookeeper();
    void fire_zookeeper();
    void zookeeper_status();
    void buy_amphibian(const std::string& name);
    void buy_mammal(const std::string& name);
    void buy_avian(const std::string& name);
    void feed_animals();
    void save_game(const std::string& filename) const;
    void load_game(const std::string& filename);

    const Enclosure& get_mammal_enclosure() const { return mammal_enclosure; }
    const Enclosure& get_amphibian_enclosure() const { return amphibian_enclosure; }
    const Enclosure& get_avian_enclosure() const { return avian_enclosure; }
    void show_animal_status();
    double calculate_animal_income() const;

};

#endif