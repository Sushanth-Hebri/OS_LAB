#include <stdio.h>
#define max 25

int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0, lowest = 10000, ch;
static int bf[max], ff[max];

void firstfit();
void bestfit();
void worstfit();

void main()
{
    printf("\n\t   Memory Management Scheme\n");
    printf("\t------------------------------");

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    printf("\n|| 1.First Fit || 2.Best Fit || 3.Worst Fit ||\nEnter the Allocation Technique: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        firstfit();
        break;
    case 2:
        bestfit();
        break;
    case 3:
        worstfit();
        break;
    default:
        printf("Invalid choice");
    }
}

void firstfit()
{
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\nF%d\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}

void bestfit()
{
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nf && ff[i] != 0; i++)
        printf("\nF%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}

void worstfit()
{
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (highest < temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\nF%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}
