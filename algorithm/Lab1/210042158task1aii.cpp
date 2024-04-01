#include <iostream>
#include <chrono>
using namespace std;

int find_1d_peak_divide_conquer(int arr[], int low, int high) {
    int n = high - low + 1;

    if (n == 0) {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return arr[mid]; 
    }

    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return find_1d_peak_divide_conquer(arr, low, mid - 1);
    }

    return find_1d_peak_divide_conquer(arr, mid + 1, high);
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

    int result = find_1d_peak_divide_conquer(arr, 0, n - 1);

    cout << "1D Peak (Divide and Conquer): " << result << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

    delete[] arr;

    return 0;
}
