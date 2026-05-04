#pragma once

#include "Product.h"

class OfficeSupply : public Product {
private:
    string category;
    string material;

public:
    OfficeSupply(int id, string n, double p, int q, string cat, string mat);

    string getCategory();
    string getMaterial();

    void displayInfo() override;
    void saveToFile(ofstream& file) override;
};

