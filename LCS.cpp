#include <iostream>
#include <string>
using namespace std;

void print_lcs(int arr[][100], string a, string b, int i, int j, string &result) {
    if (i == 0 || j == 0)
        return;

    if (a[i - 1] == b[j - 1]) {
        print_lcs(arr, a, b, i - 1, j - 1, result);
        result += a[i - 1];
    } else {
        if (arr[i][j - 1] > arr[i - 1][j])
            print_lcs(arr, a, b, i, j - 1, result);
        else
            print_lcs(arr, a, b, i - 1, j, result);
    }
}

void lcs(string a, string b) {
    int s1 = a.size();
    int s2 = b.size();
    int arr[100][100];

    int alt;

    if (s1 > s2)
        alt = s2;
    else
        alt = s1;

    char save[alt];

    int m = 0, n = 0;
    while (m < s2) {
        arr[m++][0] = 0;
    }
    while (n < s1) {
        arr[0][n++] = 0;
    }

    int s = 0;
    for (int i = 1; i <= s2; i++) {
        for (int j = 1; j <= s1; j++) {
            if (a[i - 1] == b[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                save[s++] = a[i - 1];
            } else {
                if (arr[i][j - 1] > arr[i - 1][j]) {
                    arr[i][j] = arr[i][j - 1];
                } else {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
    }

    cout << "The 2D array \n";
    for (int i = 0; i <= s2; i++) {
        for (int j = 0; j <= s1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    string result;
    print_lcs(arr, a, b, s2, s1, result);

    cout << "LCS is: " << result << endl;
}

int main() {
    string a = "combination", b = "competition";
    lcs(a, b);
    return 0;
}