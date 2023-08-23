#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10;
int count = 0;

int wait(int s)
{
    while (s <= 0)
        ;
    s--;
    return s;
}

int signal(int s)
{
    s++;
    return s;
}

void producer()
{
    empty = wait(empty);
    mutex = wait(mutex);
    count++;
    printf("Producer produces an item %d\n", count);
    mutex = signal(mutex);
    full = signal(full);
}

void consumer()
{
    full = wait(full);
    mutex = wait(mutex);
    printf("Consumer consumes an item %d\n", count);
    count--;
    mutex = signal(mutex);
    empty = signal(empty);
}
void main()
{
    int choice;
    printf("\n>Enter 1 for Producer\n>Enter 2 for Consumer\n>Enter 3 for Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (empty == 0)
            {
                printf("\nBuffer is full!!\n");
            }
            else
            {
                producer();
            }
            break;
        case 2:
            if (full == 0)
            {
                printf("\nBuffer is empty!!\n");
            }
            else
            {
                consumer();
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}