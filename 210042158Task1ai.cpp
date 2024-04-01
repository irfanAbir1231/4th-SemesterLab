#include <iostream>
#include <chrono>
using namespace std;

int find_1d_peak_linear(int arr[], int n) {
    if (n == 0) {
        return -1;
    }

    if (arr[0] >= arr[1]) {
        return arr[0];
    }

    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            return arr[i];
        }
    }

    if (arr[n - 1] >= arr[n - 2]) {
        return arr[n - 1];
    }

    return -1;
}

int main() {
    long long int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    int N = 100;

    for (int i = 0; i < n; i++) {
        int a = rand() % N;
        arr[i] = a;
    }

    auto start = std::chrono::high_resolution_clock::now();


    int result = find_1d_peak_linear(arr, n);

    auto end = chrono::high_resolution_clock::now();

    if (result != -1) {
        cout << "1D Peak (Linear): " << result << endl;
    } else {
        cout << "No peak found in the array." << endl;
    }

     delete[] arr;

    chrono::duration<double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds." << endl;

    return 0;
}
