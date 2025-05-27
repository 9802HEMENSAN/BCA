#include <stdio.h>

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform insertion sort
void insertionSort(int arr[], int n, int *exchanges, int *loop_count) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*exchanges)++;
            (*loop_count)++;
        }
        arr[j + 1] = key;
        (*loop_count)++;

        // Display the array after each step
        printf("Step %d: ", i);
        displayArray(arr, n);
    }
}

// Main function
int main() {
    int arr[] = {27, 15, 42, 3, 9, 29, 81, 54, 0, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int exchanges = 0, loop_count = 0;

    printf("Original Array:\n");
    displayArray(arr, n);
    printf("\n");

    // Sort the array
    insertionSort(arr, n, &exchanges, &loop_count);

    // Display sorted array
    printf("\nSorted Array:\n");
    displayArray(arr, n);

    // Output analysis
    printf("\nTotal Exchanges: %d", exchanges);
    printf("\nTotal Loop Executions: %d\n", loop_count);

    return 0;
}
