#include <iostream>
#include <vector>

using namespace std;

struct Index {
    int row, col;
};

Index find_2d_peak_greedy(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int start_col = 0;
    int end_col = cols - 1;

    while (start_col <= end_col) {
        int mid_col = start_col + (end_col - start_col) / 2;

        int max_row = 0;
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][mid_col] > matrix[max_row][mid_col]) {
                max_row = i;
            }
        }

        bool isPeak = true;
        if (max_row > 0 && matrix[max_row][mid_col] < matrix[max_row - 1][mid_col]) {
            isPeak = false;
            end_col = mid_col - 1; 
        } else if (max_row < rows - 1 && matrix[max_row][mid_col] < matrix[max_row + 1][mid_col]) {
            isPeak = false;
            start_col = mid_col + 1; 
        }

        if (isPeak) {
            Index peakIndex;
            peakIndex.row = max_row;
            peakIndex.col = mid_col;
            return peakIndex;
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

    Index peakIndex = find_2d_peak_greedy(matrix);

    if (peakIndex.row != -1 && peakIndex.col != -1) {
        cout << "2D Peak (Greedy): Element at index (" << peakIndex.row << ", " << peakIndex.col << ") = " << matrix[peakIndex.row][peakIndex.col] << endl;
    } else {
        cout << "No peak found in the 2D array." << endl;
    }

    return 0;
}
