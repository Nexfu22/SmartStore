#ifndef DELIVERY_H
#define DELIVERY_H

#include <string>

class Delivery {
private:
    int deliveryId;
    std::string address;
    double deliveryFee;
    std::string driverName;
public:
    Delivery(int id, std::string addr, double fee, std::string driver);
    double getDeliveryFee() const;
    void displayDeliveryInfo() const;
};

#endif