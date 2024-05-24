#ifndef FINANCES_H
#define FINANCES_H

#include <sstream>
#include <iomanip>

class Finances {

public:
    double total_income;
    double total_expenses;
    // Constructor
    Finances();

    // Function to record income
    void record_income(double dollar_amount);

    // Function to record expenses
    void record_expense(double dollar_amount);

    // Function to calculate net profit
    double calculate_net_profit() const;

    // Function to get the balance
    double get_balance() const;

    void set_balance(double new_balance);
    
    // Virtual function to get financial summary
    virtual std::string get_financial_summary() const;
};

#endif // FINANCES_H