#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    string name;
    double price;
    int quantity;
    static int totalProducts;

public:
    Product(int id, string n, double p, int q);
    virtual ~Product();

    int getID();
    string getName();
    double getPrice();
    int getQuantity();
    void setQuantity(int q);

    virtual void displayInfo();
    void buyOne();
    void buyMultiple(int amount);
    virtual void saveToFile(ofstream& file);

    static void printTotalProducts();
};

