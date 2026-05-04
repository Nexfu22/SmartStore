#include "Book.h"

Book::Book(int id, string n, double p, int q, string auth, int pages)
    : Product(id, n, p, q) {
    author = auth;
    numPages = pages;
}

string Book::getAuthor() { return author; }
int Book::getNumPages() { return numPages; }

void Book::displayInfo() {
    cout << "------- Book -------" << endl;
    Product::displayInfo();
    cout << "Author: " << author << endl;
    cout << "Pages: " << numPages << endl;
    cout << "--------------------" << endl;
}

void Book::saveToFile(ofstream& file) {
    file << "Book\n";
    Product::saveToFile(file);
    file << author << "\n" << numPages << "\n";
}