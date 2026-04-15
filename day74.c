// Problem Statement
// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Correct comparator
int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[n][101];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names
    qsort(names, n, sizeof(names[0]), cmp);

    char winner[101];
    int maxVotes = 0;

    for (int i = 0; i < n;) {
        int count = 1;

        while (i + 1 < n && strcmp(names[i], names[i + 1]) == 0) {
            count++;
            i++;
        }

        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }

        i++;
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}