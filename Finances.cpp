#include "Finances.h"

// Constructor
Finances::Finances() : total_income(0), total_expenses(0) {}

// Function to record income
void Finances::record_income(double dollar_amount) {
    total_income += dollar_amount;
}

// Function to record expenses
void Finances::record_expense(double dollar_amount) {
    total_expenses += dollar_amount;
}

// Function to calculate net profit
double Finances::calculate_net_profit() const {
    return total_income - total_expenses;
}

// Function to get the balance
double Finances::get_balance() const {
    return calculate_net_profit();
}

void Finances::set_balance(double new_balance) {
    double net_profit = calculate_net_profit();
    double adjustment = new_balance - net_profit;
    if (adjustment > 0) {
        total_income += adjustment;
    } else {
        total_expenses -= adjustment;
    }
}
