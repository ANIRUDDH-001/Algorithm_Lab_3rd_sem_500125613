// 5. Get a detailed insight of dynamic programming approach by the implementation of  Matrix Chain Multiplication problem and see the impact of parenthesis positioning on time requirements for matrix multiplication.

#include <stdio.h>
#include <limits.h>
#include <time.h>

// Function to find the minimum number of scalar multiplications using DP
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    
    // Initializing the diagonal to 0 (no cost for a single matrix)
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // Filling the table in a bottom-up manner
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];  // Return the minimum number of multiplications
}

// Function to measure time and execute the matrix chain multiplication for different cases
void runMatrixChainOrder(int p[], int n, int case_num) {
    clock_t start, end;
    double cpu_time_used;
    
    // Start measuring time
    start = clock();
    
    // Perform matrix chain order calculation
    int result = matrixChainOrder(p, n);
    
    // Stop measuring time
    end = clock();
    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Print the result and time taken
    printf("Case %d: Minimum number of multiplications is: %d\n", case_num, result);
    printf("Time taken for case %d: %f seconds\n\n", case_num, cpu_time_used);
}

int main() {
    // Define different sets of matrices for 5 different cases

    // Case 1: A1: 30x35, A2: 35x15, A3: 15x5, A4: 5x10, A5: 10x20, A6: 20x25
    int p1[] = {30, 35, 15, 5, 10, 20, 25};
    int n1 = sizeof(p1) / sizeof(p1[0]);
    
    // Case 2: A1: 10x30, A2: 30x5, A3: 5x60, A4: 60x40, A5: 40x30
    int p2[] = {10, 30, 5, 60, 40, 30};
    int n2 = sizeof(p2) / sizeof(p2[0]);
    
    // Case 3: A1: 40x20, A2: 20x30, A3: 30x10, A4: 10x30
    int p3[] = {40, 20, 30, 10, 30};
    int n3 = sizeof(p3) / sizeof(p3[0]);
    
    // Case 4: A1: 5x10, A2: 10x15, A3: 15x20, A4: 20x25, A5: 25x30
    int p4[] = {5, 10, 15, 20, 25, 30};
    int n4 = sizeof(p4) / sizeof(p4[0]);
    
    // Case 5: A1: 10x20, A2: 20x30, A3: 30x40, A4: 40x50, A5: 50x60
    int p5[] = {10, 20, 30, 40, 50, 60};
    int n5 = sizeof(p5) / sizeof(p5[0]);

    // Execute and measure time for each case
    runMatrixChainOrder(p1, n1, 1);  // Case 1
    runMatrixChainOrder(p2, n2, 2);  // Case 2
    runMatrixChainOrder(p3, n3, 3);  // Case 3
    runMatrixChainOrder(p4, n4, 4);  // Case 4
    runMatrixChainOrder(p5, n5, 5);  // Case 5

    return 0;
}
