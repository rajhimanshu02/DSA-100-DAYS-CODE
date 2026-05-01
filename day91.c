#include <stdio.h>

// Function to check if we can paint within maxTime using k painters
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        // If single board exceeds maxTime → impossible
        if (boards[i] > maxTime) {
            return 0;
        }

        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];

            if (painters > k) {
                return 0;
            }
        }
    }
    return 1;
}

// Main function
int minTime(int boards[], int n, int k) {
    int low = 0, high = 0;

    // Calculate range
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];   // max element
        high += boards[i];    // sum
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1; // increase time
        }
    }

    return ans;
}

// Driver code
int main() {
    int n = 4, k = 2;
    int boards[] = {10, 20, 30, 40};

    printf("%d\n", minTime(boards, n, k));

    return 0;
}