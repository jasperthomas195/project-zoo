#ifndef VISITOR_H
#define VISITOR_H

#include <vector>

class Visitor {
private:
    int satisfaction_level;
    int money_spent;

public:
    // Constructor
    Visitor();

    // Getters and setters for class attributes
    int get_satisfaction_level() const;
    void set_satisfaction_level(int level);

    int get_money_spent() const;
    void set_money_spent(int amount);

    // Extra class functions
    void make_purchase(double dollar_amount);
    static int calculate_donations(const std::vector<Visitor*>& visitors);
};

#endif