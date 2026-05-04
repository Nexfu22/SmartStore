#pragma once

#include "Product.h"

class ElectronicDevice : public Product {
private:
    string brand;
    int warranty; // in months

public:
    ElectronicDevice(int id, string n, double p, int q, string br, int war);

    string getBrand();
    int getWarranty();

    void displayInfo() override;
    void saveToFile(ofstream& file) override;
};

