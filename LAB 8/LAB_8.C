// 8.Implement the sum of subset.

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Recursive approach to the Subset Sum Problem
bool subsetSumRecursive(int set[], int n, int sum) {
    // Base Cases
    if (sum == 0) return true; // A sum of 0 can always be achieved with an empty subset
    if (n == 0) return false;  // No items left to choose from

    // If the last item is greater than the sum, ignore it
    if (set[n - 1] > sum)
        return subsetSumRecursive(set, n - 1, sum);

    // Check if the sum can be obtained by either including or excluding the last item
    return subsetSumRecursive(set, n - 1, sum) || subsetSumRecursive(set, n - 1, sum - set[n - 1]);
}

// Dynamic Programming approach to the Subset Sum Problem
bool subsetSumDP(int set[], int n, int sum) {
    bool dp[MAX][MAX] = {false};

    // A sum of 0 can always be achieved with an empty subset
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] > j) {
                dp[i][j] = dp[i - 1][j]; // Ignore the current item
            } else {
                // Include or exclude the current item
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    return dp[n][sum]; // The last cell will be true if a subset with the given sum exists
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    // Using the recursive approach
    if (subsetSumRecursive(set, n, sum))
        printf("Recursive: Found a subset with the given sum %d\n", sum);
    else
        printf("Recursive: No subset with the given sum %d\n", sum);

    // Using the dynamic programming approach
    if (subsetSumDP(set, n, sum))
        printf("DP: Found a subset with the given sum %d\n", sum);
    else
        printf("DP: No subset with the given sum %d\n", sum);

    return 0;
}
