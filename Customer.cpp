#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(int id, string n, string p) : customerId(id), name(n), phone(p) {}
string Customer::getName() const { return name; }
Customer::~Customer() {}

RegularCustomer::RegularCustomer(int id, string n, string p) : Customer(id, n, p) {}
void RegularCustomer::displayInfo() const {
    cout << "Regular Customer: " << name << " | Phone: " << phone << endl;
}
double RegularCustomer::calculateDiscount(double subtotal) const {
    return 0.0;
}

PremiumCustomer::PremiumCustomer(int id, string n, string p, double rate) 
    : Customer(id, n, p), discountRate(rate) {}
void PremiumCustomer::displayInfo() const {
    cout << "Premium Customer: " << name << " | Phone: " << phone 
         << " | Discount Rate: " << (discountRate * 100) << "%" << endl;
}
double PremiumCustomer::calculateDiscount(double subtotal) const {
    return subtotal * discountRate;
}