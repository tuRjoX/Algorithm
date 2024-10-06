#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;

        cout << "After pass " << i << ": ";
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[5] = {5, 2, 4, 1, 3};

    cout << "Unsorted Array: ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << endl;
    cout << endl;
    insertionSort(arr, 5);
    cout << endl;

    cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}
