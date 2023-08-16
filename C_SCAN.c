// Write a C program to simulate disk scheduling algorithms
//C scan
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head;
    char direction;
    int sum = 0;
    int i,back,forward;

    printf("C-SCAN\n");
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
    { for(i=n;i>=0;i--){
        if(rs[i]>head){
        forward=i;
    }
      }
      sum=head+abs(rs[n-1]-rs[forward]);
      printf("Total Seek Time: %d\n", sum);
    }

    else if (direction == 'r')
    {
        for(i=1;i<=n;i++){
        if(rs[i]<head){
         back=i;
                    }
       }
         sum=abs(rs[n-1]-head)+rs[back];
         printf("Total Seek Time: %d\n", sum);
    }

    else
    {

        printf("invalid input try l or r");
    }
    return 0;
}