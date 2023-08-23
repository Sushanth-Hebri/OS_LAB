#include <stdio.h>
#include <stdlib.h>

void SSTF()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;

    printf("\n>>> SSTF Algorithm <<<");
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    while (count != n)
    {
        int min = 1000, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        RQ[index] = 1000;
        count++;
    }

    printf("Total head movement is: %d", TotalHeadMoment);
}

void LOOK()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;

    printf("\n>>> LOOK Algorithm <<<");
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
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

        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total head movement is: %d", TotalHeadMoment);
}

void C_LOOK()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;

    printf("\n>>> C-LOOK Algorithm <<<");
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);

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
        printf("1.SSTF\n2.LOOK\n3.C-LOOK\n4.EXIT");
        printf("\n>>Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            SSTF();
            break;
        case 2:
            LOOK();
            break;
        case 3:
            C_LOOK();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
