#include "product.h"
#include <fstream>
#include <iomanip>
#include <cmath>

// Product Implementation
Product::Product(const string &name, const string &article, const string &unit, double price, time_t supply_date)
    : name(name), article(article), unit(unit), price(price), supply_date(supply_date) {}

void Product::display() const {
    cout << "Name: " << name << ", Article: " << article
         << ", Unit: " << unit << ", Price: " << price
         << ", Supply Date: " << ctime(&supply_date);
}

string Product::getName() const { return name; }

double Product::getPrice() const { return price; }

void Product::setPrice(double newPrice) { price = newPrice; }

bool Product::needsDiscount() const { return false; }

// Toy Implementation
Toy::Toy(const string &name, const string &article, const string &unit, double price, time_t supply_date, int age_limit)
    : Product(name, article, unit, price, supply_date), age_limit(age_limit) {}

void Toy::display() const {
    Product::display();
    cout << ", Age Limit: " << age_limit << endl;
}

string Toy::getType() const { return "Toy"; }

// Food Implementation
Food::Food(const string &name, const string &article, const string &unit, double price, time_t supply_date, int shelf_life)
    : Product(name, article, unit, price, supply_date), shelf_life(shelf_life) {}

void Food::display() const {
    Product::display();
    cout << ", Shelf Life: " << shelf_life << " days" << endl;
}

string Food::getType() const { return "Food"; }

bool Food::needsDiscount() const {
    time_t now = time(0);
    double remaining_days = difftime(supply_date + shelf_life * 24 * 3600, now) / (24 * 3600);
    return remaining_days < 5;
}

// Electronics Implementation
Electronics::Electronics(const string &name, const string &article, const string &unit, double price, time_t supply_date, bool warranty_available, int warranty_period)
    : Product(name, article, unit, price, supply_date), warranty_available(warranty_available), warranty_period(warranty_period) {}

void Electronics::display() const {
    Product::display();
    cout << ", Warranty Available: " << (warranty_available ? "Yes" : "No")
         << ", Warranty Period: " << warranty_period << " days" << endl;
}

string Electronics::getType() const { return "Electronics"; }

bool Electronics::needsDiscount() const {
    time_t now = time(0);
    double remaining_days = difftime(supply_date + warranty_period * 24 * 3600, now) / (24 * 3600);
    return remaining_days < 5;
}

// Utility Functions
void saveToBinaryFile(const string &filename, const vector<Product *> &products) {
    ofstream outFile(filename, ios::binary);
    for (const auto &product : products) {
        outFile.write(reinterpret_cast<const char *>(product), sizeof(*product));
    }
    outFile.close();
}

void readFromBinaryFile(const string &filename, vector<Product *> &products) {
    ifstream inFile(filename, ios::binary);
    while (inFile) {
        Product *product;
        inFile.read(reinterpret_cast<char *>(product), sizeof(*product));
        if (inFile) {
            products.push_back(product);
        }
    }
    inFile.close();
}

void searchProducts(const vector<Product *> &products, const string &name, const string &type) {
    bool found = false;
    for (const auto &product : products) {
        if (product->getName() == name && product->getType() == type) {
            product->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No matching products found.\n";
    }
}

void processOrder(vector<Product *> &products, const vector<string> &ordered_names) {
    double total_cost = 0;
    for (const auto &name : ordered_names) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if ((*it)->getName() == name) {
                total_cost += (*it)->getPrice();
                products.erase(it);
                break;
            }
        }
    }
    cout << "Total cost of order: " << total_cost << endl;
}

void applyDiscount(vector<Product *> &products) {
    for (auto &product : products) {
        if (product->needsDiscount()) {
            product->setPrice(product->getPrice() * 0.8);
        }
    }
}
