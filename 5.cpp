#include <iostream>
using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(int capacity, const Item items[], int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    Item items[] = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};
    int capacity = 5;
    int n = sizeof(items) / sizeof(items[0]);

    int max_value = knapsack(capacity, items, n);
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
