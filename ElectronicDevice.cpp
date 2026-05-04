#include "ElectronicDevice.h"

ElectronicDevice::ElectronicDevice(int id, string n, double p, int q, string br, int war)
    : Product(id, n, p, q) {
    brand = br;
    warranty = war;
}

string ElectronicDevice::getBrand() { return brand; }
int ElectronicDevice::getWarranty() { return warranty; }

void ElectronicDevice::displayInfo() {
    cout << "--- Electronic Device ---" << endl;
    Product::displayInfo();
    cout << "Brand: " << brand << endl;
    cout << "Warranty: " << warranty << " months" << endl;
    cout << "-------------------------" << endl;
}

void ElectronicDevice::saveToFile(ofstream& file) {
    file << "ElectronicDevice\n";
    Product::saveToFile(file);
    file << brand << "\n" << warranty << "\n";
}