#include "Book.h"
#include "ElectronicDevice.h"
#include "OfficeSupply.h"
#include "exceptions.h"
#include "FileIO.h"


int main() {
    // Create 4 products
    Product* products[4];
    try {
    products[0] = new Book(101, "Clean Code", 250.0, 10, "Robert Martin", 431);
    products[1] = new ElectronicDevice(102, "Samsung Galaxy", 15000.0, 5, "Samsung", 24);
    products[2] = new OfficeSupply(103, "Stapler", 75.0, 30, "Fasteners", "Metal");
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
        products[i]->displayInfo();
    }

    // Static function
    Product::printTotalProducts();

    // Purchase operations
    cout << "\n===== Purchase Operations =====" << endl;
    try {
        products[0]->buyOne();
        products[1]->buyMultiple(3);
        products[2]->buyMultiple(100); 
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
    
    // Free memory
    for (int i = 0; i < 4; i++) {
        delete products[i];
    }

    return 0;
}
