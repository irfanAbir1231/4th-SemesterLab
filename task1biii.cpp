#include <iostream>
#include <vector>

using namespace std;

struct Index {
    int row, col;
};

// Function to find a peak element in a 2D array using Divide and Conquer
Index find_2d_peak_divide_conquer(const vector<vector<int>>& matrix, int start_col, int end_col) {
    int rows = matrix.size();
    int mid_col = (start_col + end_col) / 2;

    // Find the global maximum in the current column
    int max_row = 0;
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][mid_col] > matrix[max_row][mid_col]) {
            max_row = i;
        }
    }

    // Check if the maximum element in the current column is a peak
    if ((mid_col == 0 || matrix[max_row][mid_col] >= matrix[max_row][mid_col - 1]) &&
        (mid_col == rows - 1 || matrix[max_row][mid_col] >= matrix[max_row][mid_col + 1])) {
        // If it's a peak, return its index
        Index peakIndex;
        peakIndex.row = max_row;
        peakIndex.col = mid_col;
        return peakIndex;
    }

    // If the maximum element is less than its left neighbor, search in the left half
    if (mid_col > 0 && matrix[max_row][mid_col] < matrix[max_row][mid_col - 1]) {
        return find_2d_peak_divide_conquer(matrix, start_col, mid_col - 1);
    }

    // If the maximum element is less than its right neighbor, search in the right half
    return find_2d_peak_divide_conquer(matrix, mid_col + 1, end_col);
}

// Wrapper function for find_2d_peak_divide_conquer
Index find_2d_peak_divide_conquer_wrapper(const vector<vector<int>>& matrix) {
    int cols = matrix[0].size();
    return find_2d_peak_divide_conquer(matrix, 0, cols - 1);
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

    // Find the peak using the Divide and Conquer approach
    Index peakIndex = find_2d_peak_divide_conquer_wrapper(matrix);

    if (peakIndex.row != -1 && peakIndex.col != -1) {
        cout << "2D Peak (Divide and Conquer): Element at index (" << peakIndex.row << ", " << peakIndex.col << ") = " << matrix[peakIndex.row][peakIndex.col] << endl;
    } else {
        cout << "No peak found in the 2D array." << endl;
    }

    return 0;
}
