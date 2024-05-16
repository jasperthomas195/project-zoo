#include "Finances.h"

Finances::Finances() : balance(0.0), amphibianPrice(100.0), mammalPrice(200.0), avianPrice(150.0) {
}

Finances::~Finances() {
}

double Finances::getBalance() const {
    return balance;
}

double Finances::getAmphibianPrice() const {
    return amphibianPrice;
}

double Finances::getMammalPrice() const {
    return mammalPrice;
}

double Finances::getAvianPrice() const {
    return avianPrice;
}

void Finances::updateBalance(double amount) {
    balance += amount;
}

void Finances::deductExpense(double expense) {
    balance -= expense;
}

void Finances::addRevenue(double revenue) {
    balance += revenue;
}