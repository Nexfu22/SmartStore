#include "Payment.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Payment::Payment(int id, double amt) : paymentId(id), amount(amt) {}
Payment::~Payment() {}

CashPayment::CashPayment(int id, double amt) : Payment(id, amt) {}
void CashPayment::pay() const {
    cout << "Processing cash payment of $" << amount << "..." << endl;
}
string CashPayment::getMethod() const { return "Cash"; }

CardPayment::CardPayment(int id, double amt, string cardNum) 
    : Payment(id, amt), cardNumber(cardNum) {}
bool CardPayment::validateCard() const {
    if (cardNumber.length() != 16) return false;
    for (char c : cardNumber) {
        if (!isdigit(c)) return false;
    }
    return true;
}
void CardPayment::pay() const {
    if (!validateCard()) {
        throw invalid_argument("Exception: Invalid card number! Must be exactly 16 digits.");
    }
    cout << "Processing card payment of $" << amount << "..." << endl;
}
string CardPayment::getMethod() const { 
    return "Credit Card ending in " + cardNumber.substr(12, 4); 
}