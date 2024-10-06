#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


void countSort(int arr[], int n) {
    int k = arr[0];
    for (int i = 1; i < n; i++) {
        k = max(k, arr[i]);
    }

    int count[k + 1] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice;

    cout << "Enter the sorting algorithm to use:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Counting Sort" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            cout << "Array after Bubble Sort: ";
            break;
        case 2:
            countSort(arr, size);
            cout << "Array after Counting Sort: ";
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    int target;
    cout << "Enter the value to search for: ";
    cin >> target;
    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
