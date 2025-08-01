#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double runtime_second;
    start = clock();

    int array[10], search, i, n;

    printf("Enter number of elements in array:\n");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter a number to search:\n");
    scanf("%d", &search);  // ✅ Fix: move this up, you were re-scanning array

    // 🔍 Linear search
    for (i = 0; i < n; i++) {
        if (array[i] == search) {
            printf("%d is present at location %d.\n", search, i + 1); // i++ was incorrect
            break;
        }
    }

    if (i == n) {
        printf("%d isn't present in the array.\n", search);
    }

    end = clock();
    runtime_second = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Runtime: %lf seconds\n", runtime_second);  //Fix: use %lf instead of %If

    return 0;
}
