#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
protected:
    int customerId;
    std::string name;
    std::string phone;
public:
    Customer(int id, std::string n, std::string p);
    virtual void displayInfo() const = 0;
    virtual double calculateDiscount(double subtotal) const = 0;
    std::string getName() const;
    virtual ~Customer();
};

class RegularCustomer : public Customer {
public:
    RegularCustomer(int id, std::string n, std::string p);
    void displayInfo() const override;
    double calculateDiscount(double subtotal) const override;
};

class PremiumCustomer : public Customer {
private:
    double discountRate;
public:
    PremiumCustomer(int id, std::string n, std::string p, double rate);
    void displayInfo() const override;
    double calculateDiscount(double subtotal) const override;
};

#endif