
// produce consumer
#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\n");
    printf("\nProducer produced a item %d \n", x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer <- item %d \n", x);
    x--;
    ++mutex;
}

int main()
{
    int n, i;
    printf("\n1. Producer\t2.Consumer\t3.Exit\n");
#pragma omp critical

    for (i = 1; i > 0; i++)
    {
        printf("Total item available:%d \n",full);
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("Buffer is full cannot add\n");
            }
            break;

        case 2:
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty cant get");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
}
