#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the 'element' type
typedef int element;

// Define the SWAP macro
#define SWAP(a, b, temp) {temp = a; a = b; b = temp;}

void quicksort(element list[], int left, int right)
{
  int pivot, i, j;
  element temp;
  if (left < right) {
    i = left;    j = right+1;
    pivot = list[left];
    do {
      do i++; while (i <= right && list[i] < pivot);
      do j--; while (j >= left && list[j] > pivot);
      if (i < j) SWAP(list[i], list[j], temp);
    } while (i < j);
    SWAP(list[left], list[j], temp);
    quicksort(list, left, j-1);
    quicksort(list, j+1, right);
  }
}

// Function to print an array
void printArray(element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the quicksort implementation
int main() {
    printf("=== QuickSort Implementation ===\n\n");
    
    // Test with a sample array
    element arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Test 1 - Fixed array:\n");
    printf("Original array: ");
    printArray(arr, n);
    
    quicksort(arr, 0, n-1);
    
    printf("Sorted array:   ");
    printArray(arr, n);
    
    // Test with random array
    printf("\nTest 2 - Random array:\n");
    srand(time(NULL));
    const int SIZE = 15;
    element randomArr[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        randomArr[i] = rand() % 100;
    }
    
    printf("Original random array: ");
    printArray(randomArr, SIZE);
    
    quicksort(randomArr, 0, SIZE-1);
    
    printf("Sorted random array:   ");
    printArray(randomArr, SIZE);
    
    printf("\nQuickSort completed successfully!\n");
    return 0;
}