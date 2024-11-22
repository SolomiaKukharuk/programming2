#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double real = 0.0, double imag = 0.0);
    double getReal() const;
    double getImag() const;
    void setReal(double real);
    void setImag(double imag);
    friend istream &operator>>(istream &in, Complex &c);
    friend ostream &operator<<(ostream &out, const Complex &c);
    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    Complex operator*(const Complex &c) const;
    Complex operator/(const Complex &c) const;
    double magnitude() const;
    bool isValidForArctan() const;
};

Complex computeArctanSum(const Complex &z, int maxTerms);

#endif // COMPLEX_H
