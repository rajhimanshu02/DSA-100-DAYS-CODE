#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefixSum = 0;
    long long count = 0;

    // Arrays to store prefix sums and their frequencies
    long long sum[n + 1];
    int freq[n + 1];
    int size = 0;

    // Initialize with prefix sum = 0
    sum[size] = 0;
    freq[size] = 1;
    size++;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int found = 0;

        // Check if prefixSum already exists
        for(int j = 0; j < size; j++) {
            if(sum[j] == prefixSum) {
                count += freq[j];
                freq[j]++;
                found = 1;
                break;
            }
        }

        // If not found, add new prefix sum
        if(!found) {
            sum[size] = prefixSum;
            freq[size] = 1;
            size++;
        }
    }

    printf("%lld\n", count);

    return 0;
}