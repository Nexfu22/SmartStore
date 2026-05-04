#include "OfficeSupply.h"

OfficeSupply::OfficeSupply(int id, string n, double p, int q, string cat, string mat)
    : Product(id, n, p, q) {
    category = cat;
    material = mat;
}

string OfficeSupply::getCategory() { return category; }
string OfficeSupply::getMaterial() { return material; }

void OfficeSupply::displayInfo() {
    cout << "--- Office Supply ---" << endl;
    Product::displayInfo();
    cout << "Category: " << category << endl;
    cout << "Material: " << material << endl;
    cout << "---------------------" << endl;
}

void OfficeSupply::saveToFile(ofstream& file) {
    file << "OfficeSupply\n";
    Product::saveToFile(file);
    file << category << "\n" << material << "\n";
}