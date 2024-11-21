#include "product.h"

int main() {
    vector<Product *> products;

    time_t now = time(0);
    products.push_back(new Toy("Teddy Bear", "T001", "pcs", 50.0, now, 3));
    products.push_back(new Food("Milk", "F001", "liters", 10.0, now, 10));
    products.push_back(new Electronics("Laptop", "E001", "pcs", 1500.0, now, true, 365));

    string filename = "products.bin";
    saveToBinaryFile(filename, products);
    vector<Product *> loadedProducts;
    readFromBinaryFile(filename, loadedProducts);

    cout << "\nSearching for 'Milk' of type 'Food':\n";
    searchProducts(loadedProducts, "Milk", "Food");

    cout << "\nProcessing order for 'Teddy Bear':\n";
    vector<string> order = {"Teddy Bear"};
    processOrder(loadedProducts, order);
    cout << "\nApplying discount to eligible products:\n";
    applyDiscount(loadedProducts);
    cout << "\nRemaining products:\n";
    for (const auto &product : loadedProducts) {
        product->display();
    }


    for (auto &product : products) {
        delete product;
    }

    return 0;
}
