#include "Book.h"
#include "ElectronicDevice.h"
#include "OfficeSupply.h"
#include "FileIO.h"


int main() {
    // Create 4 products
    Product* products[4];
    products[0] = new Book(101, "Clean Code", 250.0, 10, "Robert Martin", 431);
    products[1] = new ElectronicDevice(102, "Samsung Galaxy", 15000.0, 5, "Samsung", 24);
    products[2] = new OfficeSupply(103, "Stapler", 75.0, 30, "Fasteners", "Metal");
    products[3] = new Book(104, "Harry Potter", 180.0, 8, "J.K. Rowling", 500);

    // Display all products
    cout << "\n===== All Products =====" << endl;
    for (int i = 0; i < 4; i++) {
        products[i]->displayInfo();
    }

    // Static function
    Product::printTotalProducts();

    // Purchase operations
    cout << "\n===== Purchase Operations =====" << endl;
    products[0]->buyOne();
    products[1]->buyMultiple(3);
    products[2]->buyMultiple(100); 

    // File I/O
    cout << "\n===== File Operations =====" << endl;
    saveAllProducts(products, 4);
    readProductsFromFile();

    // Free memory
    for (int i = 0; i < 4; i++) {
        delete products[i];
    }

    return 0;
}