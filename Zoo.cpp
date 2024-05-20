#include "Zoo.h"

Zoo::Zoo(double initialBalance)
    : finances(initialBalance), mammalEnclosure(15), amphibianEnclosure(15), avianEnclosure(15),
      visitors_today(0){}


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
    for (auto enclosure : enclosure) {
        delete enclosure;
    }
}

void Zoo::open_for_day() {
    double zookeeperCost = staff.size() * 240.0;
    finances.deductExpense(zookeeperCost);
    std::cout << "Current balance of the zoo: $" << finances.getBalance() << std::endl;
    std::cout << "Number of Mammals: " << mammals.size() << std::endl;
    std::cout << "Number of Amphibians: " << amphibians.size() << std::endl;
    std::cout << "Number of Avians: " << avians.size() << std::endl;
    std::cout << "Current number of zookeepers: " << staff.size() << std::endl;
    visitors.clear();
    visitors_today = 0; 
}

void Zoo::close_for_day() {
    finances.updateBalance(visitors.size());
    std::cout << "Current balance of the zoo: $" << finances.getBalance() << std::endl;
    std::cout << "Number of Mammals: " << mammals.size() << std::endl;
    std::cout << "Number of Amphibians: " << amphibians.size() << std::endl;
    std::cout << "Number of Avians: " << avians.size() << std::endl;
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
    double price = finances.getAmphibianPrice();
    if (finances.getBalance() >= price) {
        Living_Animal_Amphibian* newAmphibian = new Living_Animal_Amphibian("Amphibian", 1.0, 1.0, true);
        if (enclosure.addAnimal(newAmphibian)) {
            animals.push_back(newAmphibian);
            finances.deductExpense(price);
            std::cout << "Bought a new Amphibian!" << std::endl;
        } else {
            std::cout << "Enclosure is full, cannot add new Amphibian!" << std::endl;
            delete newAmphibian;
        }
    } else {
        std::cout << "Not enough funds to buy a new amphibian!" << std::endl;
    }
}

void Zoo::buy_mammal() {
    double price = finances.getMammalPrice();
    if (finances.getBalance() >= price) {
        Living_Animal_Mammal* newMammal = new Living_Animal_Mammal("Mammal", 1.0, 1.0, true); // Example: all mammals need shelter
        if (mammalEnclosure.addAnimal(newMammal)) {
            mammals.push_back(newMammal);
            finances.deductExpense(price);
            std::cout << "Bought a new mammal!" << std::endl;
        } else {
            std::cout << "Enclosure is full, cannot add new mammal!" << std::endl;
            delete newMammal;
        }
    } else {
        std::cout << "Not enough funds to buy a new mammal!" << std::endl;
    }
}
void Zoo::buy_avian() {
    if (finances.getBalance() < avianPrice) {
        std::cout << "Not enough funds to buy an avian.\n";
        return;
    }
    finances.deductExpense(avianPrice);
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
        finances.updateBalance(animalValue);
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
    if (finances.getBalance() < finances.getZookeeperPrice()) {
        std::cout << "Not enough funds to hire a zookeeper.\n";
        return;
    }
    finances.deductExpense(finances.getZookeeperPrice());
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
