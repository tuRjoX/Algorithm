#include <iostream>

using namespace std;

const int MAX_ITEMS = 5;
const int MAX_DAYS = 7;
const int MAX_SALES = 1000;

void inputSalesData(int salesUnit[], int salesQuantity[]) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        cout << "Enter sales unit price for item " << i + 1 << ": ";
        cin >> salesUnit[i];

        if (salesUnit[i] < 0 || salesUnit[i] > MAX_SALES) {
            cout << "Sales unit price must be between 0 and 1000. Please try again." << endl;
            exit(1);
        }

        cout << "Enter sales quantity for item " << i + 1 << ": ";
        cin >> salesQuantity[i];

        if (salesQuantity[i] < 0 || salesQuantity[i] > MAX_SALES) {
            cout << "Sales quantity must be between 0 and 1000. Please try again." << endl;
            exit(1);
        }
    }
}

// Function to calculate total sales
int calculateTotalSales(const int salesUnit[], const int salesQuantity[]) {
    int totalSales = 0;
    for (int i = 0; i < MAX_ITEMS; ++i) {
        totalSales += salesUnit[i] * salesQuantity[i];
    }
    return totalSales;
}

// Function to calculate average sales quantity
double calculateAverageSalesQuantity(const int salesQuantity[]) {
    int totalQuantity = 0;
    for (int i = 0; i < MAX_ITEMS; ++i) {
        totalQuantity += salesQuantity[i];
    }
    return static_cast<double>(totalQuantity) / MAX_DAYS;
}

int main() {
    int salesUnit[MAX_ITEMS];
    int salesQuantity[MAX_ITEMS];

    inputSalesData(salesUnit, salesQuantity);

    int totalSales = calculateTotalSales(salesUnit, salesQuantity);
    double averageSalesQuantity = calculateAverageSalesQuantity(salesQuantity);

    cout << "Total sales of seven days: " << totalSales << endl;
    cout << "Average sales quantity: " << averageSalesQuantity << endl;

    return 0;
}
