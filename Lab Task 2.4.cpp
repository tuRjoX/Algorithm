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
    }
}

int main() {
    int arr[5];

    cout << "Enter 5 Integer Numbers: ";
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    insertionSort(arr, 5);

    cout << "Sorted Array Is :";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << "  ";

    return 0;
}
