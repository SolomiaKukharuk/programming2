#include "complex.h"


Complex::Complex(double real, double imag) : real(real), imag(imag) {}


double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}


void Complex::setReal(double real) {
    this->real = real;
}

void Complex::setImag(double imag) {
    this->imag = imag;
}


istream &operator>>(istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}


ostream &operator<<(ostream &out, const Complex &c) {
    out << c.real;
    if (c.imag >= 0) {
        out << " + " << c.imag << "i";
    } else {
        out << " - " << -c.imag << "i";
    }
    return out;
}


Complex Complex::operator+(const Complex &c) const {
    return Complex(real + c.real, imag + c.imag);
}


Complex Complex::operator-(const Complex &c) const {
    return Complex(real - c.real, imag - c.imag);
}


Complex Complex::operator*(const Complex &c) const {
    return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}


Complex Complex::operator/(const Complex &c) const {
    if (c.real == 0 && c.imag == 0) {
        throw runtime_error("Division by zero in complex division.");
    }
    double denom = c.real * c.real + c.imag * c.imag;
    return Complex((real * c.real + imag * c.imag) / denom, (imag * c.real - real * c.imag) / denom);
}


double Complex::magnitude() const {
    return sqrt(real * real + imag * imag);
}


bool Complex::isValidForArctan() const {
    return magnitude() < 1.0;
}


Complex computeArctanSum(const Complex &z, int maxTerms) {
    if (!z.isValidForArctan()) {
        throw invalid_argument("The magnitude of z must be less than 1 for the series to converge.");
    }

    Complex result(0, 0);
    Complex term = z;
    int sign = 1;
    for (int n = 1; n <= maxTerms; n++) {
        result = result + (term * sign / static_cast<double>(2 * n - 1));
        term = term * z * z;
        sign *= -1;

    return result;
}
