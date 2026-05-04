#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Order.h"

class Store {
private:
    std::string name;
    std::vector<Product*> products;
    std::vector<Customer*> customers;
    std::vector<Order*> orders;
public:
    Store(std::string n);
    void addProduct(Product* p);
    void addCustomer(Customer* c);
    void addOrder(Order* o);
    void displayStoreSummary() const;
};

#endif