#include "Order.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

// OrderItem Implementation
OrderItem::OrderItem(Product* p, int q) {
    if (q <= 0) {
        throw invalid_argument("Exception: Invalid order quantity.");
    }
    if (p->getAvailableQuantity() < q) {
        throw runtime_error("Exception: Insufficient stock for product: " + p->getName());
    }
    product = p;
    quantity = q;
    unitPriceAtPurchase = p->getPrice();
    product->reduceQuantity(q);
}
double OrderItem::calculateItemTotal() const { return quantity * unitPriceAtPurchase; }
string OrderItem::getProductName() const { return product->getName(); }
int OrderItem::getQuantity() const { return quantity; }
double OrderItem::getUnitPrice() const { return unitPriceAtPurchase; }

// Order Implementation
Order::Order(int id, string date, Customer* cust) 
    : orderId(id), orderDate(date), status("Pending"), customer(cust), payment(nullptr), delivery(nullptr) {}

void Order::addItem(Product* product, int quantity) {
    items.push_back(new OrderItem(product, quantity));
}
void Order::setPayment(Payment* p) { payment = p; }
void Order::setDelivery(Delivery* d) { delivery = d; }

double Order::calculateSubtotal() const {
    double subtotal = 0;
    for (auto item : items) subtotal += item->calculateItemTotal();
    return subtotal;
}

double Order::calculateFinalTotal() const {
    double subtotal = calculateSubtotal();
    double discount = customer->calculateDiscount(subtotal);
    double fee = (delivery != nullptr) ? delivery->getDeliveryFee() : 0.0;
    return subtotal - discount + fee;
}

void Order::printInvoice() const {
    cout << "\n=======================================\n";
    cout << "               INVOICE                 \n";
    cout << "=======================================\n";
    cout << "Order ID:   " << orderId << "\n";
    cout << "Date:       " << orderDate << "\n";
    cout << "Customer:   " << customer->getName() << "\n";
    cout << "---------------------------------------\n";
    cout << left << setw(20) << "Item" << setw(10) << "Qty" << "Total" << endl;
    
    for (auto item : items) {
        cout << left << setw(20) << item->getProductName() 
             << setw(10) << item->getQuantity() 
             << "$" << item->calculateItemTotal() << endl;
    }
    cout << "---------------------------------------\n";
    
    double subtotal = calculateSubtotal();
    double discount = customer->calculateDiscount(subtotal);
    double deliveryFee = (delivery != nullptr) ? delivery->getDeliveryFee() : 0.0;
    double finalTotal = calculateFinalTotal();

    cout << right << setw(25) << "Subtotal: $" << subtotal << endl;
    cout << setw(25) << "Discount: -$" << discount << endl;
    cout << setw(25) << "Delivery Fee: +$" << deliveryFee << endl;
    cout << "---------------------------------------\n";
    cout << setw(25) << "FINAL TOTAL: $" << finalTotal << endl;
    
    if (payment != nullptr) {
        cout << "Payment Method: " << payment->getMethod() << "\n";
    }
    cout << "=======================================\n";
}

Order::~Order() {
    for (auto item : items) delete item;
}