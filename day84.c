// Problem: Implement Selection Sort - Implement the algorithm.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the sorted array or search result

// Example:
// Input:
// 5
// 64 34 25 12 22

// Output:
// 12 22 25 34 64

#include <stdio.h>

int main() {
    int n;

    // Step 1: Take input size
    scanf("%d", &n);

    int arr[n];  // Array of size n

    // Step 2: Take array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Selection Sort Logic
    for (int i = 0; i < n - 1; i++) {

        int min_index = i;  // Assume current index has minimum

        // Find the smallest element in remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum with current element
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    // Step 4: Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}