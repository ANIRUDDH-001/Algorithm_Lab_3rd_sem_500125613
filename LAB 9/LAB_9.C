// 9. Compare the Backtracking and Branch & Bound Approach by the implementation of 0/1 Knapsack problem. Also compare the performance with dynamic programming approach.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

// Utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

//Backtracking

// Backtracking function to solve the 0/1 Knapsack problem
void knapsackBacktracking(int i, int currentWeight, int currentValue, int *maxValue, int W, int n, struct Item items[]) {
    if (currentWeight > W) return; // If weight exceeds capacity, stop
    if (i == n) {
        *maxValue = max(*maxValue, currentValue); // Update max value if current value is better
        return;
    }
    
    // Include the current item
    knapsackBacktracking(i + 1, currentWeight + items[i].weight, currentValue + items[i].value, maxValue, W, n, items);
    
    // Exclude the current item
    knapsackBacktracking(i + 1, currentWeight, currentValue, maxValue, W, n, items);
}

//Branch & Bound

struct Node {
    int level;    // Level of the node in the decision tree
    int value;    // Total value up to this node
    int weight;   // Total weight up to this node
    int bound;    // Upper bound of the maximum value possible from this node
};

// Comparator function for sorting items by value/weight ratio (used in Branch & Bound)
int cmp(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    return (ratio1 > ratio2) ? -1 : 1;
}

// Function to calculate upper bound for Branch & Bound
int bound(struct Node u, int n, int W, struct Item items[]) {
    if (u.weight >= W) return 0; // If weight exceeds capacity, no bound
    
    int bound = u.value;
    int totalWeight = u.weight;
    
    for (int i = u.level; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            bound += items[i].value;
        } else {
            bound += (W - totalWeight) * items[i].value / items[i].weight;
            break;
        }
    }
    return bound;
}

// Branch & Bound function to solve the 0/1 Knapsack problem
int knapsackBranchAndBound(int W, int n, struct Item items[]) {
    qsort(items, n, sizeof(struct Item), cmp); // Sort items by value/weight ratio
    
    struct Node Q[n * 2]; // Queue of nodes
    int front = 0, rear = 0; // Queue front and rear pointers
    int maxValue = 0;
    
    struct Node u, v;
    u.level = 0;
    u.value = 0;
    u.weight = 0;
    u.bound = bound(u, n, W, items);
    
    Q[rear++] = u;
    
    while (front != rear) {
        u = Q[front++]; // Dequeue
        
        if (u.level == n) continue;
        
        v.level = u.level + 1;
        
        // Include the current item in the knapsack
        v.weight = u.weight + items[u.level].weight;
        v.value = u.value + items[u.level].value;
        if (v.weight <= W && v.value > maxValue)
            maxValue = v.value;
        v.bound = bound(v, n, W, items);
        
        if (v.bound > maxValue) Q[rear++] = v; // Enqueue if promising
        
        // Exclude the current item from the knapsack
        v.weight = u.weight;
        v.value = u.value;
        v.bound = bound(v, n, W, items);
        
        if (v.bound > maxValue) Q[rear++] = v; // Enqueue if promising
    }
    
    return maxValue;
}

//Dynamic Programming

// Dynamic Programming function to solve the 0/1 Knapsack problem
int knapsackDynamic(int W, int n, struct Item items[]) {
    int dp[n+1][W+1]; // DP table
    
    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i-1].weight <= w) {
                dp[i][w] = max(items[i-1].value + dp[i-1][w - items[i-1].weight], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][W];
}

//Main Function

int main() {
    struct Item items[] = {{2, 40}, {3, 50}, {5, 100}, {7, 130}, {4, 60}, {6, 110}};
    int n = sizeof(items) / sizeof(items[0]); // Number of items
    int W = 10; // Capacity of the knapsack
    
    // Backtracking Approach
    int maxValueBacktracking = 0;
    knapsackBacktracking(0, 0, 0, &maxValueBacktracking, W, n, items);
    printf("Maximum value (Backtracking): %d\n", maxValueBacktracking);
    
    // Branch & Bound Approach
    int maxValueBranchBound = knapsackBranchAndBound(W, n, items);
    printf("Maximum value (Branch & Bound): %d\n", maxValueBranchBound);
    
    // Dynamic Programming Approach
    int maxValueDynamic = knapsackDynamic(W, n, items);
    printf("Maximum value (Dynamic Programming): %d\n", maxValueDynamic);

    return 0;
}