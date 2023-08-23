#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

void fifo(int pages[], int n, int frames)
{
    int frame[frames];
    int front = 0, rear = 0;
    int page_faults = 0;

    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            frame[rear] = pages[i];
            rear = (rear + 1) % frames;
            page_faults++;
        }

        printf("Page %d: ", pages[i]);
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults (FIFO): %d\n", page_faults);
}

void lru(int pages[], int n, int frames)
{
    int frame[frames];
    int page_faults = 0;
    int used[MAX_PAGES] = {0};

    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                used[j] = i;
                break;
            }
        }

        if (!found)
        {
            int min = 0;
            for (int j = 1; j < frames; j++)
            {
                if (used[j] < used[min])
                {
                    min = j;
                }
            }
            frame[min] = pages[i];
            used[min] = i;
            page_faults++;
        }

        printf("Page %d: ", pages[i]);
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults (LRU): %d\n", page_faults);
}

void optimal(int pages[], int n, int frames)
{
    int frame[frames];
    int page_faults = 0;

    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            if (i < frames)
            {
                frame[i] = pages[i];
            }
            else
            {
                int max_dist = -1;
                int replace_page = -1;
                for (int j = 0; j < frames; j++)
                {
                    int dist = MAX_PAGES;
                    for (int k = i + 1; k < n; k++)
                    {
                        if (pages[k] == frame[j])
                        {
                            dist = k - i;
                            break;
                        }
                    }
                    if (dist > max_dist)
                    {
                        max_dist = dist;
                        replace_page = j;
                    }
                }
                frame[replace_page] = pages[i];
            }
            page_faults++;
        }

        printf("Page %d: ", pages[i]);
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults (Optimal): %d\n", page_faults);
}

int main()
{
    int pages[MAX_PAGES];
    int n, frames;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("\nFIFO Page Replacement:\n");
    fifo(pages, n, frames);

    printf("\nLRU Page Replacement:\n");
    lru(pages, n, frames);

    printf("\nOptimal Page Replacement:\n");
    optimal(pages, n, frames);

    return 0;
}
