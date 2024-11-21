#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Base class for Product
class Product {
protected:
    string name;
    string article;
    string unit;
    double price;
    time_t supply_date;

public:
    Product(const string &name, const string &article, const string &unit, double price, time_t supply_date);
    virtual ~Product() = default;

    virtual void display() const;
    string getName() const;
    virtual string getType() const = 0;

    double getPrice() const;
    void setPrice(double newPrice);

    virtual bool needsDiscount() const;
};

// Derived class for Toys
class Toy : public Product {
    int age_limit;

public:
    Toy(const string &name, const string &article, const string &unit, double price, time_t supply_date, int age_limit);
    void display() const override;
    string getType() const override;
};

// Derived class for Food
class Food : public Product {
    int shelf_life;

public:
    Food(const string &name, const string &article, const string &unit, double price, time_t supply_date, int shelf_life);
    void display() const override;
    string getType() const override;

    bool needsDiscount() const override;
};

// Derived class for Electronics
class Electronics : public Product {
    bool warranty_available;
    int warranty_period;

public:
    Electronics(const string &name, const string &article, const string &unit, double price, time_t supply_date, bool warranty_available, int warranty_period);
    void display() const override;
    string getType() const override;

    bool needsDiscount() const override;
};

// Utility functions
void saveToBinaryFile(const string &filename, const vector<Product *> &products);
void readFromBinaryFile(const string &filename, vector<Product *> &products);
void searchProducts(const vector<Product *> &products, const string &name, const string &type);
void processOrder(vector<Product *> &products, const vector<string> &ordered_names);
void applyDiscount(vector<Product *> &products);

#endif // PRODUCT_H
