
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;

void insertionSort( int array[], int n) {

    n = sizeof(array) / sizeof(array[0]);
    for (int i = 1; i < n; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[i] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

int main() {

    int arr[5] = {5, 4, 3, 2, 1};

    insertionSort(arr, 5);

    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
