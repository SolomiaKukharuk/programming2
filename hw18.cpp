//18_5(є)
#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
    vector<int> data;


    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;


        vector<int> leftArray(n1), rightArray(n2);

        for (int i = 0; i < n1; i++) leftArray[i] = arr[left + i];
        for (int i = 0; i < n2; i++) rightArray[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;


        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k] = leftArray[i];
                i++;
            } else {
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }


        while (i < n1) {
            arr[k] = leftArray[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

public:
    Array(const vector<int>& inputData) : data(inputData) {}
y
    void sort() {
        mergeSort(data, 0, data.size() - 1);
    }

    static void sort(vector<int>& externalData) {
        Array instance(externalData);
        instance.mergeSort(externalData, 0, externalData.size() - 1);
    }

    void display() const {
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> myData = {5, 2, 9, 1, 5, 6};
    Array arr(myData);

    cout << "Original array: ";
    arr.display();

    arr.sort();
    cout << "Sorted array (member method): ";
    arr.display();

    vector<int> anotherData = {10, 3, 7, 4, 8};
    cout << "Original array for static sort: ";
    for (int num : anotherData) {
        cout << num << " ";
    }
    cout << endl;

    Array::sort(anotherData);
    cout << "Sorted array (static method): ";
    for (int num : anotherData) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
