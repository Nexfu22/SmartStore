#include "Book.h"
#include "ElectronicDevice.h"
#include "OfficeSupply.h"
#include "exceptions.h"
#include "templates.h"
#include "FileIO.h"


int main() {
    // Create 4 products
    Product* products[4] = { nullptr, nullptr, nullptr, nullptr };
    try {
    products[0] = new Book(101, "Clean Code", -250.0, 10, "Robert Martin", 431);
    }

    catch (InvalidPriceException& e) {
        cout << e.what() << endl;
    }
    catch (InvalidQuantityException& e) {
        cout << e.what() << endl;
    }
    try {
        products[1] = new ElectronicDevice(102, "Samsung Galaxy", 15000.0, 5, "Samsung", 24);
    }

    catch (InvalidPriceException& e) {
        cout << e.what() << endl;
    }
    catch (InvalidQuantityException& e) {
        cout << e.what() << endl;
    }
    try {
        products[2] = new OfficeSupply(103, "Stapler", 75.0, 30, "Fasteners", "Metal");
    }

    catch (InvalidPriceException& e) {
        cout << e.what() << endl;
    }
    catch (InvalidQuantityException& e) {
        cout << e.what() << endl;
    }
    try {
        products[3] = new Book(104, "Harry Potter", 180.0, 8, "J.K. Rowling", 500);
    }

    catch (InvalidPriceException& e) {
        cout << e.what() << endl;
    }
    catch (InvalidQuantityException& e) {
        cout << e.what() << endl;
    }
    
    // Display all products
    cout << "\n===== All Products =====" << endl;
    for (int i = 0; i < 4; i++) {
        if (products[i] != nullptr) {
            products[i]->displayInfo();
        }
        else {
            cout << "Product " << i + 1 << " was skipped due to invalid data." << endl;
        }
    }

    // Static function
    Product::printTotalProducts();

    // Purchase operations
    cout << "\n===== Purchase Operations =====" << endl;

    try {
        if (products[0] != nullptr)
            products[0]->buyOne();
        else
            cout << "Product 1 is not available." << endl;

        if (products[1] != nullptr)
            products[1]->buyMultiple(3);
        else
            cout << "Product 2 is not available." << endl;

        if (products[2] != nullptr)
            products[2]->buyMultiple(100);
        else
            cout << "Product 3 is not available." << endl;

    }
    catch (OutOfStockException& e) {
        cout << e.what() << endl;
    }

    // File I/O
    cout << "\n===== File Operations =====" << endl;
    try {
    saveAllProducts(products, 4);
    readProductsFromFile();
    }

    catch (FileException& e) {
        cout << e.what() << endl;
    }
    
    Product* highest = findHighestPrice(products, 4);
    cout << "\nHighest price product: " << highest->getName() << endl;

    swapProducts(products[0], products[1]);
    cout << "After swap: " << products[0]->getName() << endl;

    // Free memory
    for (int i = 0; i < 4; i++) {
        delete products[i];
    }

    return 0;
}
