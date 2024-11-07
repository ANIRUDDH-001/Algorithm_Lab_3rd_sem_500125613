// 7. Through 0/1 Knapsack problem, analyze the greedy and dynamic programming approach for the same dataset.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for items
struct Item {
    int value;
    int weight;
};

// Comparison function for sorting items based on value/weight ratio
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 > r2) ? -1 : 1; // Sort in descending order
}

// Greedy approach (Fractional Knapsack)
void greedyKnapsack(struct Item items[], int n, int W) {
    qsort(items, n, sizeof(struct Item), compare); // Sort items by value/weight ratio

    double totalValue = 0.0;
    int currentWeight = 0;

    printf("Greedy Approach:\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Taking entire item %d: Value = %d, Weight = %d\n", i + 1, items[i].value, items[i].weight);
        } else {
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            printf("Taking fractional part of item %d: Value = %d, Weight = %d\n", i + 1, items[i].value, items[i].weight);
            break;
        }
    }
    printf("Total value in Greedy approach: %.2f\n\n", totalValue);
}

// Dynamic Programming approach (0/1 Knapsack)
int knapsackDP(struct Item items[], int n, int W) {
    int dp[MAX][MAX] = {0}; // Initialize DP table

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = dp[i - 1][w] > (dp[i - 1][w - items[i - 1].weight] + items[i - 1].value) ?
                           dp[i - 1][w] : (dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    struct Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int W = 50; // Capacity of the knapsack
    int n = sizeof(items) / sizeof(items[0]);

    // Greedy approach
    greedyKnapsack(items, n, W);

    // Dynamic Programming approach
    int maxValue = knapsackDP(items, n, W);
    printf("Total value in Dynamic Programming approach: %d\n", maxValue);

    return 0;
}
