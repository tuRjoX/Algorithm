#include <iostream>
using namespace std;

int calculateDiagonalSum(int arr[][100], int rows, int cols) {
    int dia1 = 0;
    int dia2 = 0;

    for (int r = 0; r < rows; r++) {
        dia1 += arr[r][r];
        dia2 += arr[r][cols - 1 - r];
    }
    if (rows % 2 != 0 && cols % 2 != 0) {
        int middleIndex = rows / 2;
        dia2 -= arr[middleIndex][middleIndex];
    }

    return dia1 + dia2;
}

int main() {
    int rows, cols;
    rows = cols = 3; 

    int arr[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "2D array is:" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << arr[r][c] << "  ";
        }
        cout << endl;
    }

    int diagonalSum = calculateDiagonalSum(arr, rows, cols);

    cout << "Diagonal Sum: " << diagonalSum;

    return 0;
}
