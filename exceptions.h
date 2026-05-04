#pragma once
#include <exception>
#include <string>
using namespace std;

class StoreException : public exception {
protected:
    string message;
public:
    StoreException(const string& msg) : message(msg) {}
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

class InvalidPriceException : public StoreException {
public:
    InvalidPriceException(double price)
        : StoreException("Invalid price: " + to_string(price) +
            ". Price cannot be negative.") {}
};

class InvalidQuantityException : public StoreException {
public:
    InvalidQuantityException(int qty)
        : StoreException("Invalid quantity: " + to_string(qty) +
            ". Quantity cannot be negative.") {}
};

class OutOfStockException : public StoreException {
public:
    OutOfStockException(int requested, int available)
        : StoreException("Cannot buy " + to_string(requested) +
            " only " + to_string(available) +
            " items available.") {}
};

class FileException : public StoreException {
public:
    FileException(const string& filename)
        : StoreException("Failed to open file: " + filename) {}
};
