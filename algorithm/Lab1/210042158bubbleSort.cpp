#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;

void bubbleSort(vector<int>& array) {
    int n = array.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main() {
    long long int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    int N = 100;

    srand(time(0)); 

    for (int i = 0; i < n; i++) {
        int a = rand() % N;
        arr[i] = a;
    }

    auto start = chrono::high_resolution_clock::now();

    bubbleSort(arr);

    auto end = chrono::high_resolution_clock::now();

    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    // Calculate the duration
    chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    cout << "\nSorting time: " << duration.count() << " seconds." << endl;

    return 0;
}
