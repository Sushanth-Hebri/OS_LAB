#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M = 3, ind = 0;
    printf("\nEnter the number of processess: ");
    scanf("%d", &N);

    int alloc[N][M], max[N][M], need[N][M], finished[N], ans[N], avail[M];

    printf("\nEnter allocated resources\n");
    for (int i = 0; i < N; i++)
    {
        printf("For Process %d: ", i);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Maximum resources\n");
    for (int i = 0; i < N; i++)
    {
        printf("For Process %d: ", i);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter available resources\n");
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &avail[i]);
    }

    for (int i = 0; i < N; i++)
    {
        finished[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            if (finished[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < M; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int p = 0; p < M; p++)
                    {
                        avail[p] += alloc[i][p];
                    }
                    finished[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < N; i++)
    {
        if (finished[i] == 0)
        {
            flag = 0;
            printf("System is in a deadlock state.\n");
            break;
        }
    }

    if (flag == 1)
    {
        printf("\nSystem is in a safe state.\n");
    }
}
