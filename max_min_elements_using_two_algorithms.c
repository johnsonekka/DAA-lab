#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Algorithm 1: Simple method (2n-2 comparisons)
void findMaxMinSimple(const int arr[], int n, int *max, int *min, int *comparisons) {
    *max = arr[0];
    *min = arr[0];
    *comparisons = 0;

    // Do both max and min in one pass instead of two
    for (int i = 1; i < n; i++) {
        (*comparisons)++;
        if (arr[i] > *max) {
            *max = arr[i];
        } else {
            (*comparisons)++;
            if (arr[i] < *min) {
                *min = arr[i];
            }
        }
    }
}

// Algorithm 2: Efficient pair method (~3n/2 comparisons)
void findMaxMinEfficient(const int arr[], int n, int *max, int *min, int *comparisons) {
    *comparisons = 0;
    int i;

    if (n % 2 == 0) {
        // Initialize with first pair
        (*comparisons)++;
        if (arr[0] > arr[1]) {
            *max = arr[0];
            *min = arr[1];
        } else {
            *max = arr[1];
            *min = arr[0];
        }
        i = 2;
    } else {
        // Initialize with first element
        *max = arr[0];
        *min = arr[0];
        i = 1;
    }

    // Process elements in pairs
    while (i < n - 1) {
        (*comparisons)++;
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > *max) (*max = arr[i]);
            if (arr[i + 1] < *min) (*min = arr[i + 1]);
        } else {
            if (arr[i + 1] > *max) (*max = arr[i + 1]);
            if (arr[i] < *min) (*min = arr[i]);
        }
        i += 2;
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int n, int min_val, int max_val) {
    for (int i = 0; i < n; i++) {
        arr[i] = min_val + rand() % (max_val - min_val + 1);
    }
}

// Function to print array
void printArray(const int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be positive!\n");
        return 1;
    }

    int arr[n];
    srand(time(NULL)); // seed random generator once
    generateRandomArray(arr, n, 1, 1000);

    int max1, min1, comp1;
    int max2, min2, comp2;

    printf("\nGenerated Array (%d elements):\n", n);
    printArray(arr, n);
    printf("\n");

    // Algorithm 1: Simple method
    findMaxMinSimple(arr, n, &max1, &min1, &comp1);
    printf("Algorithm 1 (Simple):\n");
    printf("  Max: %d, Min: %d\n", max1, min1);
    printf("  Comparisons: %d (theoretical %d)\n\n", comp1, 2 * n - 2);

    // Algorithm 2: Efficient method
    findMaxMinEfficient(arr, n, &max2, &min2, &comp2);
    printf("Algorithm 2 (Efficient):\n");
    printf("  Max: %d, Min: %d\n", max2, min2);
    printf("  Comparisons: %d (theoretical ~%d)\n\n", comp2, 3 * n / 2);

    // Verification
    if (max1 == max2 && min1 == min2) {
        printf("✓ Both algorithms produced the same results!\n");
    } else {
        printf("✗ Results don't match! Check the algorithms.\n");
    }

    printf("\nEfficiency Gain:\n");
    printf("  Algorithm 1: %d comparisons\n", comp1);
    printf("  Algorithm 2: %d comparisons\n", comp2);
    printf("  Saved: %d comparisons (%.1f%% reduction)\n",
           comp1 - comp2, ((comp1 - comp2) * 100.0) / comp1);

    return 0;
}
