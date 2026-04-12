#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, n;
    scanf("%d", &m);     // size of hash table
    scanf("%d", &n);     // number of operations

    int hash[m];
    for (int i = 0; i < m; i++)
        hash[i] = EMPTY;

    char op[10];
    int key;

    for (int j = 0; j < n; j++) {
        scanf("%s %d", op, &key);

        int index = key % m;

        if (strcmp(op, "INSERT") == 0) {
            int i = 0;
            while (i < m) {
                int newIndex = (index + i * i) % m;
                if (hash[newIndex] == EMPTY) {
                    hash[newIndex] = key;
                    break;
                }
                i++;
            }
        }

        else if (strcmp(op, "SEARCH") == 0) {
            int i = 0, found = 0;
            while (i < m) {
                int newIndex = (index + i * i) % m;
                if (hash[newIndex] == key) {
                    found = 1;
                    break;
                }
                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}