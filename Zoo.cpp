#include "Zoo.h"

Zoo::Zoo() : visitors_today(0), average_visitor_satisfaction(0.0) {
}

// Example prices, can be changed later
const double COST_ZOOKEEPER = 1500.0;
const double SELL_ZOOKEEPER = 1250.0;

Zoo::~Zoo() {
    for (auto visitor : visitors) {
        delete visitor;
    }
    for (auto animal : animals) {
        delete animal;
    }
    for (auto staff : staff) {
        delete staff;
    }
    for (auto enclosure : enclosures) {
        delete enclosure;
    }
}

void Zoo::open_for_day() {
    std::cout << "Current balance of the zoo: $" << finances.getBalance() << std::endl;
    std::cout << "Current number of animals: " << animals.size() << std::endl;
    std::cout << "Current number of zookeepers: " << staff.size() << std::endl;
    visitors.clear();
    visitors_today = 0; 
}

void Zoo::close_for_day() {
    finances.update_balance(visitors.size());
    std::cout << "Current balance of the zoo: $" << finances.getBalance() << std::endl;
    std::cout << "Current number of animals: " << animals.size() << std::endl;
    std::cout << "Current number of zookeepers: " << staff.size() << std::endl;
}

void Zoo::admit_visitor(Visitor* visitor) {
    visitors.push_back(visitor);

    visitors_today = visitors_size();
}

void Zoo::manage_animals() {
    int choice;
    std::cout << "Manage Animals Menu:\n";
    std::cout << "1. Buy Amphibian\n";
    std::cout << "2. Buy Mammal\n";
    std::cout << "3. Buy Avian\n";
    std::cout << "4. Sell an animal\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            buy_amphibian();
            break;
        case 2:
            buy_mammal();
            break;
        case 3:
            buy_avian();
            break;
        case 4:
            sell_animal();
            break;
        default:
            std::cout << "Invalid choice\n";
    }
}
void Zoo::buy_amphibian() {
    if (finances.getBalance() < amphibianPrice) {
        std::cout << "Not enough funds to buy an amphibian.\n";
        return;
    }
    finances.deduct_expense(amphibianPrice);
    Living_Animal_Amphibian* amphibian = new Living_Animal_Amphibian();
    animals.push_back(amphibian);
    std::cout << "Amphibian bought successfully.\n";
}
void Zoo::buy_mammal() {
    if (finances.getBalance() < mammalPrice) {
        std::cout << "Not enough funds to buy a mammal.\n";
        return;
    }
    finances.deduct_expense(mammalPrice);
    Living_Animal_Mammal* mammal = new Living_Animal_Mammal();
    animals.push_back(mammal);
    std::cout << "Mammal bought successfully.\n";
}
void Zoo::buy_avian() {
    if (finances.getBalance() < avianPrice) {
        std::cout << "Not enough funds to buy an avian.\n";
        return;
    }
    finances.deduct_expense(avianPrice);
    Living_Animal_Avian* avian = new Living_Animal_Avian();
    animals.push_back(avian);
    std::cout << "Avian bought successfully.\n";
}
void Zoo::sell_animal() {
    if (animals.empty()) {
        std::cout << "There are no animals to sell.\n";
        return;
    }

    int index;
    std::cout << "Animals available for sale:\n";
    for (int i = 0; i < animals.size(); i++) {
        std::cout << i + 1 << " | " << animals[i]->getName() << std::endl;
    }

    std::cout << "Enter the index of the animal you want to sell (1 - " << animals.size() << "): ";
    std::cin >> index;

    if (index >= 1 && index <= animals.size()) {
        Living_Animal* animalSold = animals[index - 1];
        double animalValue = animalSold->getValue();
        finances.update_balance(animalValue);
        delete animalSold;
        animals.erase(animals.begin() + index - 1);
        std::cout << "Animal sold successfully, balance increased by $" << animalValue << ".\n";
    } else {
        std::cout << "Invalid index\n";
    }
}

void Zoo::manage_staff() {
    int choice;
    std::cout << "Manage Staff Menu:\n";
    std::cout << "1. Hire Zookeeper\n";
    std::cout << "2. Fire Zookeeper\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            hire_zookeeper();
            break;
        case 2:
            fire_zookeeper();
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}
void Zoo::hire_zookeeper() {
    if (finances.getBalance() < zookeeperPrice) {
        std::cout << "Not enough funds to hire a zookeeper.\n";
        return;
    }
    finances.deduct_expense(zookeeperPrice);
    Living_Zookeeper* zookeeper = new Living_Zookeeper();
    staff.push_back(zookeeper);
    std::cout << "Zookeeper hired successfully.\n";
}
void Zoo::fire_zookeeper() {
if (staff.empty()) {
    std::cout << "There are no zookeepers to fire.\n";
    return;
    }
    int index;
    std::cout << "Zookeepers available for firing:\n";
    for (int i = 0; i < staff.size(); i++) {
        std::cout << i + 1 << " | " << staff[i] << std::endl;
    }

    std::cout << "Enter the index of the zookeeper you want to fire (1 - " << staff.size() << "): ";
    std::cin >> index;

    if (index >= 1 && index <= staff.size()) {
        finances.update_balance(SELL_ZOOKEEPER);
        Living_Zookeeper* zookeeperFired = staff[index - 1];
        delete zookeeperFired;
        staff.erase(staff.begin() + index - 1);
        std::cout << "Zookeeper fired successfully. Balance increased by $" << SELL_ZOOKEEPER << ".\n";
    } else {
        std::cout << "Invalid index\n";
    }
}

void Zoo::save_game() {
}

int Zoo::getVisitorsToday() const {
    std::cout << "Visitors today:" << visitors_today;
}

double Zoo::getAverageVisitorSatisfaction() const {
    std::cout << "Average visitor satisfaction today:" << average_visitor_satisfaction;
}
