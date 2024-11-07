// 10. Compare the performance of Rabin-Karp, Knuth-Morris-Pratt and naive string matching algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_SIZE 1000000  // Increased text size for better performance evaluation
#define MAX_PATTERN_SIZE 100    // Pattern size remains small for matching

// Naive String Matching Algorithm
int naiveStringMatch(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            count++;
        }
    }
    return count;
}

// Knuth-Morris-Pratt (KMP) Algorithm
void computeLPSArray(char* pattern, int m, int* lps) {
    int length = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPStringMatch(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[MAX_PATTERN_SIZE];

    computeLPSArray(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern
    int count = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++; // found a match
            j = lps[j - 1]; // Continue to search for next match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

// Rabin-Karp Algorithm
int rabinKarpStringMatch(char* text, char* pattern, int d, int q) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1; // The value of d^(m-1) % q

    // The value of h would be "d^(m-1)%q"
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // Check for characters one by one
            int found = 1;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; // Match found
            }
        }

        // Calculate hash value for next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0) {
                t = t + q;
            }
        }
    }
    return 0; // No match found
}

// Function to compare performances
void compareStringMatchingAlgorithms(char* text, char* pattern) {
    clock_t start, end;
    double time_taken;

    // Naive Algorithm
    start = clock();
    int naiveCount = naiveStringMatch(text, pattern);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Naive String Matching: %d matches found in %f seconds\n", naiveCount, time_taken);

    // KMP Algorithm
    start = clock();
    int kmpCount = KMPStringMatch(text, pattern);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("KMP String Matching: %d matches found in %f seconds\n", kmpCount, time_taken);

    // Rabin-Karp Algorithm
    start = clock();
    int rabinKarpCount = rabinKarpStringMatch(text, pattern, 256, 101);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Rabin-Karp String Matching: %d matches found in %f seconds\n", rabinKarpCount, time_taken);
}

int main() {
    // Generate a large sample text
    char text[MAX_TEXT_SIZE];
    char pattern[MAX_PATTERN_SIZE] = "ABAB"; // Pattern to search for

    // Fill the text with a repetitive pattern for testing
    for (int i = 0; i < MAX_TEXT_SIZE - 1; i++) {
        text[i] = "ABAB"[i % 4]; // Create a long string "ABABABAB..."
    }
    text[MAX_TEXT_SIZE - 1] = '\0'; // Null-terminate the string

    // Compare algorithms
    compareStringMatchingAlgorithms(text, pattern);

    return 0;
}
