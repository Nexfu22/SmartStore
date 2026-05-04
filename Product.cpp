#include "Product.h"
#include "exceptions.h"

// Initialize static variable
int Product::totalProducts = 0;

Product::Product(int id, string n, double p, int q) {

    if (p < 0) throw InvalidPriceException(p);
    if (q < 0) throw InvalidQuantityException(q);
    productID = id;
    name = n;
    price = p;
    quantity = q;
    totalProducts++;
}

Product::~Product() {
    totalProducts--;
}

int Product::getID() { return productID; }
string Product::getName() { return name; }
double Product::getPrice() { return price; }
int Product::getQuantity() { return quantity; }
void Product::setQuantity(int q) { quantity = q; }

void Product::displayInfo() {
    cout << "ID: " << productID << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << " EGP" << endl;
    cout << "Quantity: " << quantity << endl;
}

void Product::buyOne() {
    if (quantity <= 0) {
        throw OutOfStockException(1, quantity);
    }

    quantity--;
    cout << "You bought 1 of [" << name << "]. Remaining: " << quantity << endl;
}

void Product::buyMultiple(int amount) {
    if (amount > quantity) {
        throw OutOfStockException(amount, quantity);
    }

    quantity -= amount;
    cout << "You bought " << amount << " of [" << name << "]. Remaining: " << quantity << endl;
}

void Product::saveToFile(ofstream& file) {
    if (!file.is_open()) {
        throw FileException("products.txt");
    }
    file << productID << "\n" << name << "\n" << price << "\n" << quantity << "\n";
}

void Product::printTotalProducts() {
    cout << "Total products in store: " << totalProducts << endl;
}
