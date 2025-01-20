#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

void findUniqueInSecondHalf(const string& name, const vector<int>& V) {
    if (V.size() % 2 != 0) {
        cerr << "Error: Vector must have an even number of elements." << endl;
        return;
    }

    size_t halfSize = V.size() / 2;

    set<int> firstHalf(V.begin(), V.begin() + halfSize);
    set<int> secondHalf(V.begin() + halfSize, V.end());

    vector<int> result;

    set_difference(secondHalf.begin(), secondHalf.end(),
                   firstHalf.begin(), firstHalf.end(),
                   back_inserter(result));

    sort(result.begin(), result.end());

    ofstream outputFile(name);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }

    for (int num : result) {
        outputFile << num << endl;
    }

    outputFile.close();
}

int main() {

    string fileName = "output.txt";
    vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8, 3, 6, 9, 10};
    findUniqueInSecondHalf(fileName, V);

    cout << "Results written to " << fileName << endl;

    return 0;
}
