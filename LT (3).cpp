#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cout << "After swap: ";
                for (int k = 0; k < size; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main() {

    int arr[] = {5, 3, 8, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Un-Sorted Array Is :";
    for (int i = 0; i < size; i++)
    cout << arr[i] << "  ";

    bubbleSort(arr, size);

    cout << "Sorted Array Is :";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}
