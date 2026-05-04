#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Payment.h"
#include "Delivery.h"

class OrderItem {
private:
    Product* product;
    int quantity;
    double unitPriceAtPurchase;
public:
    OrderItem(Product* p, int q);
    double calculateItemTotal() const;
    std::string getProductName() const;
    int getQuantity() const;
    double getUnitPrice() const;
};

class Order {
private:
    int orderId;
    std::string orderDate;
    std::string status;
    Customer* customer;
    Payment* payment;
    Delivery* delivery;
    std::vector<OrderItem*> items;
public:
    Order(int id, std::string date, Customer* cust);
    void addItem(Product* product, int quantity);
    void setPayment(Payment* p);
    void setDelivery(Delivery* d);
    double calculateSubtotal() const;
    double calculateFinalTotal() const;
    void printInvoice() const;
    ~Order();
};

#endif