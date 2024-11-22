#include "complex.h"

int main() {
    try {
        Complex z;
        cout << "Enter a complex number z (real and imaginary parts):" << endl;
        cin >> z;

        if (!z.isValidForArctan()) {
            throw invalid_argument("Error: The magnitude of z must be less than 1 for the series to converge.");
        }

        int maxTerms;
        cout << "Enter the maximum number of terms for the series: ";
        cin >> maxTerms;
        if (maxTerms <= 0) {
            throw invalid_argument("Error: The number of terms must be positive.");
        }

        Complex result = computeArctanSum(z, maxTerms);
        cout << "The computed sum of the arctan(z) series is: " << result << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
