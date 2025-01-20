#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

int charToValue(unsigned char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return toupper(c) - 'A' + 10;
    return -1;
}

bool isValidNumber(const vector<unsigned char>& number, int base) {
    for (auto c : number) {
        if (charToValue(c) < 0 || charToValue(c) >= base) {
            return false;
        }
    }
    return true;
}


long long toDecimal(const vector<unsigned char>& number, int base) {
    long long decimalValue = 0;
    for (unsigned char c : number) {
        decimalValue = decimalValue * base + charToValue(c);
    }
    return decimalValue;
}


vector<unsigned char> fromDecimal(long long decimalValue, int base) {
    if (decimalValue == 0) return {'0'};
    vector<unsigned char> result;
    while (decimalValue > 0) {
        int digit = decimalValue % base;
        result.push_back(digit < 10 ? '0' + digit : 'A' + (digit - 10));
        decimalValue /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}


vector<int> addition(const vector<unsigned char>& A, int baseA,
                     const vector<unsigned char>& B, int baseB,
                     int baseResult) {

    if (baseA < 2 || baseB < 2 || baseResult < 2) return {};

    if (!isValidNumber(A, baseA) || !isValidNumber(B, baseB)) return {};

    long long decimalA = toDecimal(A, baseA);
    long long decimalB = toDecimal(B, baseB);

    long long decimalSum = decimalA + decimalB;

    vector<unsigned char> result = fromDecimal(decimalSum, baseResult);

    vector<int> resultInt;
    for (unsigned char c : result) {
        resultInt.push_back(c);
    }
    return resultInt;
}


pair<int, vector<unsigned char>> readNumber(ifstream& file) {
    string line;
    getline(file, line);
    size_t colonPos = line.find(':');
    if (colonPos == string::npos) return {-1, {}};

    int base = stoi(line.substr(0, colonPos));
    vector<unsigned char> number(line.begin() + colonPos + 1, line.end());
    return {base, number};
}
void runTests() {
    // Test 1: Valid input with base 10 and result in base 2
    {
        vector<unsigned char> A = {'2', '5', '3'}; // 253 in base 10
        vector<unsigned char> B = {'1', '5'};     // 15 in base 10
        int baseA = 10, baseB = 10, baseResult = 2;
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        vector<int> expected = {'1', '0', '0', '0', '1', '0', '0', '0'};
        assert(result == expected);
    }

    // Test 2: Valid input with hexadecimal numbers
    {
        vector<unsigned char> A = {'F', 'D'}; // FD in base 16 (253 in decimal)
        vector<unsigned char> B = {'A'};     // A in base 16 (10 in decimal)
        int baseA = 16, baseB = 16, baseResult = 16;
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        vector<int> expected = {'1', '0', '7'};
        assert(result == expected);
    }

    // Test 3: Invalid input with character out of range
    {
        vector<unsigned char> A = {'Z'};  // Invalid in any base
        vector<unsigned char> B = {'1'};  // Valid
        int baseA = 16, baseB = 10, baseResult = 10;
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        assert(result.empty()); // Expected empty result due to invalid input
    }

    // Test 4: Invalid base (base < 2)
    {
        vector<unsigned char> A = {'1', '0'}; // 10 in base 10
        vector<unsigned char> B = {'1', '1'}; // 11 in base 10
        int baseA = 1, baseB = 10, baseResult = 10; // Invalid baseA
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        assert(result.empty()); // Expected empty result due to invalid base
    }

    // Test 5: Zero values
    {
        vector<unsigned char> A = {'0'}; // 0 in base 10
        vector<unsigned char> B = {'0'}; // 0 in base 10
        int baseA = 10, baseB = 10, baseResult = 2;
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        vector<int> expected = {'0'};
        assert(result == expected);
    }

    // Test 6: Different bases
    {
        vector<unsigned char> A = {'1', '0'}; // 10 in base 2
        vector<unsigned char> B = {'1', '1'}; // 11 in base 10
        int baseA = 2, baseB = 10, baseResult = 10;
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        vector<int> expected = {'2', '1'};
        assert(result == expected);
    }

    // Test 7: Invalid characters in high bases
    {
        vector<unsigned char> A = {'G', '1'}; // Invalid in base 16
        vector<unsigned char> B = {'F', 'A'}; // Valid in base 16
        int baseA = 16, baseB = 16, baseResult = 10;
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        assert(result.empty()); // Expected empty result due to invalid input
    }

    // Test 8: Valid input with large bases
    {
        vector<unsigned char> A = {'1', '0', '0'}; // 100 in base 8
        vector<unsigned char> B = {'7', '7'};      // 77 in base 8
        int baseA = 8, baseB = 8, baseResult = 10;
        vector<int> result = addition(A, baseA, B, baseB, baseResult);
        vector<int> expected = {'1', '3', '5'}; // 135 in decimal
        assert(result == expected);
    }

    cout << "All tests passed!" << endl;
}


int main() {
    runTests();
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    auto [baseA, numberA] = readNumber(inputFile);

    auto [baseB, numberB] = readNumber(inputFile);

    int baseResult;
    cout << "Enter the result base: ";
    cin >> baseResult;

    vector<int> result = addition(numberA, baseA, numberB, baseB, baseResult);

    if (result.empty()) {
        outputFile << "Error: Invalid input or bases!" << endl;
    } else {
        outputFile << "Result in base " << baseResult << ": ";
        for (int c : result) {
            outputFile << static_cast<char>(c);
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
