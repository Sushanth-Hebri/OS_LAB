// Write a C program to simulate disk scheduling algorithms
// b)SSTF
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;
    
    printf("Shortest Seek Time First\n");
    printf("Enter the number of requests (n):");
    scanf("%d", &n);
    
    int rs[n];
    printf("Enter request sequence one by one (in ascending)\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    
    printf("Enter initial head position (p):");
    scanf("%d", &head);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int sum = 0;
    int current = head;

    for (int i = 0; i < n; i++) {
        int minDiff = 1e9;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int diff = abs(current - rs[j]);
                if (diff < minDiff) {
                    minDiff = diff;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        sum += minDiff;
        current = rs[index];
    }

    printf("Total Seek Time: %d\n", sum);

    return 0;
}