#pragma once

#include "Product.h"

class Book : public Product {
private:
    string author;
    int numPages;

public:
    Book(int id, string n, double p, int q, string auth, int pages);

    string getAuthor();
    int getNumPages();

    void displayInfo() override;
    void saveToFile(ofstream& file) override;
};

