#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            cin >> matrix[r][c];
}

void printMatrix(int matrix[][MAX_SIZE], int rows, int cols, string name) {
    cout << name << " Matrix:" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << matrix[r][c] << "  ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int transposed[][MAX_SIZE], int rows, int cols) {
    for (int r = 0; r < cols; r++)
        for (int c = 0; c < rows; c++)
            transposed[r][c] = matrix[c][r];
}

void addMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            result[r][c] = matrix1[r][c] + matrix2[r][c];
}

void subtractMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            result[r][c] = matrix1[r][c] - matrix2[r][c];
}

void multiplyMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[j][k];
            }
        }
    }
}

int main() {
    int rows = 3; 
    int cols = 3; 

    int matrix1[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[MAX_SIZE][MAX_SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    printMatrix(matrix1, rows, cols, "First");
    printMatrix(matrix2, rows, cols, "Second");

    int transposed1[MAX_SIZE][MAX_SIZE];
    int transposed2[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrix1, transposed1, rows, cols);
    transposeMatrix(matrix2, transposed2, rows, cols);
    printMatrix(transposed1, cols, rows, "Transposed First");
    printMatrix(transposed2, cols, rows, "Transposed Second");

    int addition[MAX_SIZE][MAX_SIZE];
    addMatrices(transposed1, transposed2, addition, cols, rows);
    printMatrix(addition, cols, rows, "Addition of Transposed Matrices");

    int subtraction[MAX_SIZE][MAX_SIZE];
    subtractMatrices(transposed1, transposed2, subtraction, cols, rows);
    printMatrix(subtraction, cols, rows, "Subtraction of Transposed Matrices");

    int multiplication[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(transposed1, transposed2, multiplication, cols, rows, cols);
    printMatrix(multiplication, cols, cols, "Multiplication of Transposed Matrices");

    return 0;
}
