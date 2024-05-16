#ifndef VISITOR_H
#define VISITOR_H

#include "Enclosure.h" // Make sure this gels well with these files

class Visitor {
private:
    int visitors;
    int satisfaction_level;
    int money_spent;

public:
    // Constructor
    Visitor();

    // Getters and setters for class attributes
    int get_Satisfaction_Level() const;
    void set_Satisfaction_Level(int level);

    int get_Money_Spent() const;
    void set_Money_Spent(int amount);

    // Extra class functions
    void visit_Enclosure(Enclosure* enclosure);

    void make_Purchase(double dollar_amount);
};

#endif