#include <iostream>
#include "Zoo.h"
#include "Visitor.h"
#include "Living_Zookeeper.h"
#include "Living_Animal_Mammal.h"
#include "Living_Animal_Amphibian.h"
#include "Living_Animal_Avian.h"

int main() {
    // Initialize the Zoo with an initial balance
    Zoo myZoo(5000.0);

    // Add some initial animals
    myZoo.buy_mammal();
    myZoo.buy_amphibian();
    myZoo.buy_avian();

    // Add some zookeepers
    myZoo.hire_zookeeper();
    myZoo.hire_zookeeper();

    // Simulate a few days at the zoo
    for (int day = 0; day < 5; ++day) {
        std::cout << "\nDay " << day + 1 << ":" << std::endl;

        // Open the zoo for the day
        myZoo.open_for_day();

        // Admit some visitors
        for (int i = 0; i < 50; ++i) {
            Visitor* visitor = new Visitor();
            myZoo.admit_visitor(visitor);
        }

        // Perform zoo operations
        myZoo.manage_animals();
        myZoo.manage_staff();

        // Close the zoo for the day
        myZoo.close_for_day();

        std::cout << "Total Visitors Today: " << myZoo.get_visitors_today() << std::endl;
        std::cout << "Average Visitor Satisfaction: " << myZoo.get_average_visitor_satisfaction() << std::endl;
        std::cout << "Zoo Balance: $" << myZoo.get_zoo_balance() << std::endl;
    }

    return 0;
}
