#include <iostream>
#include <string>

namespace Custom {
    
// Шаблонна функція для знаходження максимуму двох значень
template <typename T>
T findMax(const T& x, const T& y) {
    return (x > y) ? x : y;
}

int computeGCD(int x, int y) {
    while (y != 0) {
        int remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

class Fraction {
private:
    int numerator;   
    int denominator; 

    void reduce() {
        int gcdValue = computeGCD(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
        // Нормалізація
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Конструктор з перевіркою на нульовий знаменник
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw std::invalid_argument("The denominator cannot be zero");
        }
        reduce();
    }

    // >
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // ==
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    // рядок
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

}

int main() {
    using namespace Custom;

    int num1 = 7, num2 = 15;
    std::cout << "The maximum between " << num1 << " і " << num2 << ": " << findMax(num1, num2) << std::endl;

    std::string word1 = "cat", word2 = "dog";
    std::cout << "The maximum between \"" << word1 << "\" і \"" << word2 << "\": \"" << findMax(word1, word2) << "\"" << std::endl;

    Fraction frac1(2, 5), frac2(3, 7);
    std::cout << "The maximum between " << frac1 << " і " << frac2 << ": " << findMax(frac1, frac2) << std::endl;
}