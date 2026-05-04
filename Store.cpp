#include "Store.h"
#include <iostream>

using namespace std;

Store::Store(string n) : name(n) {}

void Store::addProduct(Product* p) { products.push_back(p); }
void Store::addCustomer(Customer* c) { customers.push_back(c); }
void Store::addOrder(Order* o) { orders.push_back(o); }

void Store::displayStoreSummary() const {
    cout << "\n=== Store Summary: " << name << " ===" << endl;
    cout << "Total Products: " << products.size() << endl;
    cout << "Total Customers: " << customers.size() << endl;
    cout << "Total Orders: " << orders.size() << endl;
    cout << "===============================\n";
}