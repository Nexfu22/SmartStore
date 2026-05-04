#include "FileIO.h"

void saveAllProducts(Product* products[], int size) {
    ofstream file("products.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open file for saving!" << endl;
        return;
    }
    file << size << "\n";
    for (int i = 0; i < size; i++) {
        products[i]->saveToFile(file);
    }
    file.close();
    cout << "Products saved to file successfully!" << endl;
}

void readProductsFromFile() {
    ifstream file("products.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open file for reading!" << endl;
        return;
    }

    cout << "\n===== Reading from File =====" << endl;

    int size;
    file >> size;
    file.ignore();

    for (int i = 0; i < size; i++) {
        string type, name;
        int id, quantity;
        double price;

        getline(file, type);
        file >> id;
        file.ignore();
        getline(file, name);
        file >> price >> quantity;
        file.ignore();

        cout << "Type: " << type
            << " | ID: " << id
            << " | Name: " << name
            << " | Price: " << price
            << " | Qty: " << quantity;

        if (type == "Book") {
            string author;
            int pages;
            getline(file, author);
            file >> pages;
            file.ignore();
            cout << " | Author: " << author << " | Pages: " << pages;
        }
        else if (type == "ElectronicDevice") {
            string brand;
            int warranty;
            getline(file, brand);
            file >> warranty;
            file.ignore();
            cout << " | Brand: " << brand << " | Warranty: " << warranty << " months";
        }
        else if (type == "OfficeSupply") {
            string category, material;
            getline(file, category);
            getline(file, material);
            cout << " | Category: " << category << " | Material: " << material;
        }

        cout << endl;
    }

    file.close();
}