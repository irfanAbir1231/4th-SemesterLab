#include <iostream>
#include <vector>

using namespace std;

struct Index {
    int row, col;
};

Index find_2d_peak_bruteforce(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            bool isPeak = true;

            if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
                isPeak = false;
            }
            if (i < rows - 1 && matrix[i][j] < matrix[i + 1][j]) {
                isPeak = false;
            }
            if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
                isPeak = false;
            }
            if (j < cols - 1 && matrix[i][j] < matrix[i][j + 1]) {
                isPeak = false;
            }

            if (isPeak) {
                Index peakIndex;
                peakIndex.row = i;
                peakIndex.col = j;
                return peakIndex;
            }
        }
    }

    return {-1, -1};
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows in the 2D array: ";
    cin >> rows;
    cout << "Enter the number of columns in the 2D array: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the 2D array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    Index peakIndex = find_2d_peak_bruteforce(matrix);

    if (peakIndex.row != -1 && peakIndex.col != -1) {
        cout << "2D Peak (Brute Force): Element at index (" << peakIndex.row << ", " << peakIndex.col << ") = " << matrix[peakIndex.row][peakIndex.col] << endl;
    } else {
        cout << "No peak found in the 2D array." << endl;
    }

    return 0;
}
