#include <iostream>

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
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr_1d[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr_1d[i];
    }

    int result = find_1d_peak_divide_conquer(arr_1d, 0, n - 1);

    cout << "1D Peak (Divide and Conquer): " << result << endl;

    return 0;
}
