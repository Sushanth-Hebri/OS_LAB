#include <stdio.h>
#include <stdlib.h>

void FCFS()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial;
    printf("\n>>> FCFS Algorithm <<<");
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    for (i = 0; i < n; i++)
    {
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
        initial = RQ[i];
    }

    printf("Total head moment is: %d", TotalHeadMoment);
}

void SCAN()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    printf("\n>>> SCAN Algorithm <<<");
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf(">>Choose the head movement direction\n>0.Towards the smaller value\n>1.Towards the larger value\n>>: ");
    scanf("%d", &move);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
        initial = size - 1;
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0);
        initial = 0;
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total head movement is: %d", TotalHeadMoment);
}

void C_SCAN()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;

    printf("\n>>> C-SCAN Algorithm <<<");
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf(">>Choose the head movement direction\n>0.Towards the smaller value\n>1.Towards the larger value\n>>: ");
    scanf("%d", &move);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }

    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
        TotalHeadMoment = TotalHeadMoment + abs(size - 1 - 0);
        initial = 0;
        for (i = 0; i < index; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0);
        TotalHeadMoment = TotalHeadMoment + abs(size - 1 - 0);
        initial = size - 1;
        for (i = n - 1; i >= index; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("Total head movement is: %d", TotalHeadMoment);
}

void main()
{
    int ch;
    printf("\nDisk Scheduling Algorithms");
    while (1)
    {
        printf("\n\nChoose an Algorithm\n");
        printf("1.FCFS\n2.SCAN\n3.C-SCAN\n4.EXIT");
        printf("\n>>Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            FCFS();
            break;
        case 2:
            SCAN();
            break;
        case 3:
            C_SCAN();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
