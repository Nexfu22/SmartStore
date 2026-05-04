#include "Delivery.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Delivery::Delivery(int id, string addr, double fee, string driver) 
    : deliveryId(id), address(addr), driverName(driver) {
    if (fee < 0) {
        throw invalid_argument("Exception: Delivery fee cannot be negative.");
    }
    deliveryFee = fee;
}

double Delivery::getDeliveryFee() const { return deliveryFee; }

void Delivery::displayDeliveryInfo() const {
    cout << "Delivery ID: " << deliveryId << " | Address: " << address 
         << " | Fee: $" << deliveryFee << " | Driver: " << driverName << endl;
}