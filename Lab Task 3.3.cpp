#include <iostream>
#include <cstdlib>
using namespace std;

int binarySearch(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 10;
    int arr[size] = {10, 3, 7, 5, 2, 8, 4, 1, 9, 6};

    cout << "Choose a searching procedure:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;

    int choice;
    cout<<"Enter Your Choice : ";
    cin >> choice;

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int result = -1;

    switch (choice) {
        case 1:
            result = linearSearch(arr, size, target);
            break;
        case 2:
            int sortChoice;
            cout << "Choose a sorting algorithm:" << endl;
            cout << "1. Insertion Sort" << endl;
            cout << "2. Merge Sort" << endl;
            cout << "3. Quick Sort" << endl;
            cout<<"Enter Your Choice : ";
            cin >> sortChoice;

            switch (sortChoice) {
                case 1:
                    insertionSort(arr, size);
                    break;
                case 2:
                    mergeSort(arr, 0, size - 1);
                    break;
                case 3:
                    quickSort(arr, 0, size - 1);
                    break;
                default:
                    cerr << "Invalid sorting algorithm choice" << endl;
                    return EXIT_FAILURE;
            }
            result = binarySearch(arr, size, target);
            break;
        default:
            cerr << "Invalid choice" << endl;
            return EXIT_FAILURE;
    }

    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found in the array" << endl;
    }

    return 0;
}
