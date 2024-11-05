//12_12
#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
#include <stdexcept>


double parse_number(const std::string& str) {

    std::regex pattern_A("^[+-]?\\d{1,3}\\.\\d{1,3}$");
    std::regex pattern_B("^[+-]?\\d{1,2}E[+-]?\\d{1,3}$");
    std::regex pattern_C("^[+-]?\\d{1,3}\\.\\d{1,4}$");

    if (std::regex_match(str, pattern_A) || std::regex_match(str, pattern_B) || std::regex_match(str, pattern_C)) {
        try {
            return std::stod(str);
        } catch (const std::invalid_argument&) {
            throw std::runtime_error("Invalid format.");
        }
    }
    throw std::runtime_error("Invalid format.");
}


double harmonic_mean(double a, double b, double c) {
    if (a == 0 || b == 0 || c == 0) {
        throw std::runtime_error("Harmonic mean undefined due to zero value.");
    }
    return 3.0 / ((1.0 / a) + (1.0 / b) + (1.0 / c));
}

int main() {
    std::string strA, strB, strC;
    std::cout << "Enter three numbers in the formats A=xxx.xxx, B=xxExxx, C=xxx.xxxx:\n";

    std::cout << "A = ";
    std::cin >> strA;
    std::cout << "B = ";
    std::cin >> strB;
    std::cout << "C = ";
    std::cin >> strC;

    try {
        double A = parse_number(strA);
        double B = parse_number(strB);
        double C = parse_number(strC);

        double harmonicMean = harmonic_mean(A, B, C);


        std::cout << "Harmonic mean:\n";
        std::cout << "Scientific notation: " << std::scientific << harmonicMean << "\n";
        std::cout << "Fixed notation: " << std::fixed << std::setprecision(6) << harmonicMean << "\n";

    } catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
