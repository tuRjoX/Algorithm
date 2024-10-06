#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void displayLeapYears(int startYear, int endYear) {
    bool leapYearFound = false;

    cout << "Leap years between " << startYear << " and " << endYear << " are:" << endl;
    for (int year = startYear; year <= endYear; ++year) {
        if (isLeapYear(year)) {
            cout << year << " ";
            leapYearFound = true;
        }
    }

    if (!leapYearFound) {
        cout << "No leap years found in the given range." << endl;
    }
}

int main() {
    int startYear, endYear;

    cout << "Enter the start year: ";
    cin >> startYear;

    cout << "Enter the end year: ";
    cin >> endYear;

    displayLeapYears(startYear, endYear);

    return 0;
}
