#include "Finances.h"

// Constructor
Finances::Finances() : total_income(0), total_expenses(0) {}

// Functions to record income and expenses
void Finances::record_income(double dollar_amount) {
    total_income += dollar_amount;
}

void Finances::record_expense(double dollar_amount) {
    total_expenses += dollar_amount;
}

// Function to calculate net profit
double Finances::calculate_net_profit() const {
    return total_income - total_expenses;
}