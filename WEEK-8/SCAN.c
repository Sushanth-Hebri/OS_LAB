// Write a C program to simulate disk scheduling algorithms
// c)SCAN
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head;
    char direction;
    int sum = 0;

    printf("SCAN\n");
    printf("Enter the number of requests (n):");
    scanf("%d", &n);

    int rs[n];
    printf("Enter request sequence one by one (in ascending)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }

    printf("Enter initial head position (p):");
    scanf("%d", &head);

    printf("Enter the direction(l or r)");
    scanf(" %c", &direction);

    if (direction == 'l')
    {
        sum = head + rs[n - 2];
        printf("Total Seek Time: %d\n", sum);
    }

    else if (direction == 'r')
    {
        sum = abs(rs[n - 1] - head) + abs(rs[n - 1] - rs[1]);
        printf("Total Seek Time: %d\n", sum);
    }

    else
    {
        printf("invalid input try l or r");
    }
    return 0;
}