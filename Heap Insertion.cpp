#include <iostream>

using namespace std;

void createHeap(int A[], int n) {
    int temp, k;

    for (int i = 2; i <= n; ++i) {
        temp = A[i];
        k = i;

        while (k > 0 && A[k / 2] < temp) {
            A[k] = A[k / 2];
            k = k / 2;
        }

        A[k] = temp;
    }
}

int main() {
    // Example usage:
    int n = 6; // Adjust the size of the array as needed
    int A[] = {0, 10, 3, 5, 1, 7}; // A[0] is not used in this implementation

    createHeap(A, n);

    // Output the heap
    cout << "Heap: ";
    for (int i = 1; i <= n; ++i) {
        cout << A[i] << " ";
    }

    return 0;
}
