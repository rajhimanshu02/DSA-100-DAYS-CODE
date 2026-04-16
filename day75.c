// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Structure for hash map
typedef struct {
    int key;
    int value;
} Hash;

int maxLen(int arr[], int n) {
    Hash hash[MAX];
    int size = 0;

    int sum = 0;
    int max_length = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0 from start
        if (sum == 0) {
            max_length = i + 1;
        }

        // Check if sum already exists
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (hash[j].key == sum) {
                int length = i - hash[j].value;
                if (length > max_length) {
                    max_length = length;
                }
                found = 1;
                break;
            }
        }

        // Store sum if not found
        if (!found) {
            hash[size].key = sum;
            hash[size].value = i;
            size++;
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}