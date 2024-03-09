#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j]]++; // Count the swaps for the current element
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Swap
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps[arr[i]]++; // Count the swaps for the current element
        }
    }
}

void printSwaps(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }
    printf("Total swaps: %d\n", swaps[0]); // Total swaps
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    // Initialize swap counters to 0
    int swaps1[100] = {0};
    int swaps2[100] = {0};

    printf("array1:\n");
    bubbleSort(array1, n1, swaps1);
    printSwaps(array1, n1, swaps1);

    printf("\narray2:\n");
    selectionSort(array2, n2, swaps2);
    printSwaps(array2, n2, swaps2);

    return 0;
}