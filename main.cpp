#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Payment.h"
#include "Delivery.h"
#include "Order.h"
#include "Store.h"

using namespace std;

int main() {
    Store myStore("Smart Tech Store");

    // 1. Create at least 4 products 
    Product p1(1, "Laptop", 1200.0, 10);
    Product p2(2, "Mouse", 25.0, 50);
    Product p3(3, "Keyboard", 45.0, 30);
    Product p4(4, "Monitor", 300.0, 5);
    
    myStore.addProduct(&p1);
    myStore.addProduct(&p2);
    myStore.addProduct(&p3);
    myStore.addProduct(&p4);

    // 2. Create at least one RegularCustomer and one PremiumCustomer
    RegularCustomer c1(101, "Alice Smith", "555-1234");
    PremiumCustomer c2(102, "Bob Johnson", "555-5678", 0.10); // 10% discount
    
    myStore.addCustomer(&c1);
    myStore.addCustomer(&c2);

    try {
        // --- Order 1: Delivered Order, Card Payment ---
        Order order1(1001, "2026-05-04", &c2);
        
        // Add multiple products
        order1.addItem(&p1, 1); 
        order1.addItem(&p2, 2); 
        
        // Setup Delivery (Delivered Order)
        Delivery delivery1(1, "123 Main St", 15.0, "Driver Dan");
        order1.setDelivery(&delivery1);
        
        // Setup Payment (Card Payment) - Final total gets passed to payment
        CardPayment cardPay(1, order1.calculateFinalTotal(), "1234567812345678");
        cardPay.pay();
        order1.setPayment(&cardPay);
        
        myStore.addOrder(&order1);
        order1.printInvoice(); // Print invoice correctly

        // --- Order 2: Pickup Order, Cash Payment ---
        Order order2(1002, "2026-05-04", &c1);
        
        // Add multiple products
        order2.addItem(&p3, 1);
        order2.addItem(&p4, 2);
        
        // Pickup order (No delivery fee, leave delivery as nullptr)
        
        // Setup Payment (Cash Payment)
        CashPayment cashPay(2, order2.calculateFinalTotal());
        cashPay.pay();
        order2.setPayment(&cashPay);
        
        myStore.addOrder(&order2);
        order2.printInvoice(); // Print invoice correctly

        myStore.displayStoreSummary();

        cout << "\n--- Exception Handling Demonstration ---\n";
        
        // Exception Case 1: Invalid Card Number
        try {
            cout << "Attempting to process invalid card...\n";
            CardPayment badCard(3, 100.0, "1234"); // Only 4 digits
            badCard.pay(); 
        } catch (const exception& e) {
            cout << "Caught Exception: " << e.what() << endl;
        }

        // Exception Case 2: Insufficient Stock
        try {
            cout << "\nAttempting to buy more monitors than available...\n";
            Order order3(1003, "2026-05-04", &c1);
            order3.addItem(&p4, 10); // Only 3 left after order2 took 2
        } catch (const exception& e) {
            cout << "Caught Exception: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cout << "Critical Error: " << e.what() << endl;
    }

    return 0;
}