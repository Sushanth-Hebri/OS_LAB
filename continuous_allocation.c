// Write a C program to simulate the following contiguous memory
// allocation techniques
// a) Worst-fit
// b) Best-fit
// c) First-fit

int n;
int request;

#include <stdio.h>
#include <conio.h>

int main()
{
    printf("_________Contiguous memory allocation__________\n\n\n");
    printf("Enter total number of memory blocks(n):");
    scanf("%d", &n);
    int memory[n][n];
    int inserted[n][n];
    int visited[n][n];




      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j]=0;
            inserted[i][j]=0;
        }
    }



    printf("Enter each memory block sizes one by one\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &memory[i][j]);
        }
    }


while(1){
printf("Enter the required memory request!:");
scanf("%d",&request);

printf("\n-----First FIt-----");

      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(memory[i][j]>=request && visited[i][j]==0){
            inserted[i][j]=request;
           }
        }
    }

    printf("\n");
    
      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
          printf("%d---->%d",memory[i][j],inserted[i][j]);
        }
    }










}

}