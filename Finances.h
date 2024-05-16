
#ifndef FINANCES_H
#define FINANCES_H

class Finances {
private:
    double balance; // Current balance
    double amphibianPrice; // Price of amphibians
    double mammalPrice; // Price of mammals
    double avianPrice; // Price of avians


public:
    Finances(); // Constructor
    ~Finances(); // Destructor

    double getBalance() const; // Getter for balance
    double getAmphibianPrice() const; // Getter for amphibian price
    double getMammalPrice() const; // Getter for mammal price
    double getAvianPrice() const; // Getter for avian price


    void updateBalance(double amount); // Function to update the balance
    void deductExpense(double expense); // Function to deduct an expense from the balance
    void addRevenue(double revenue); // Function to add revenue to the balance
    void handleVisitorPurchase(double purchaseAmount); // Function to handle visitor purchases
};

#endif 