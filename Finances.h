#ifndef FINANCES_H
#define FINANCES_H

class Finances {
private:
    double total_income;
    double total_expenses;

public:
    // Constructor
    Finances();

    // Function to record income
    void record_income(double dollar_amount);

    // Function to record expenses
    void record_expense(double dollar_amount);

    // Function to calculate net profit
    double calculate_net_profit() const;
};

#endif // FINANCES_H
