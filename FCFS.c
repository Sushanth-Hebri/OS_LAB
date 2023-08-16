// Write a C program to simulate disk scheduling algorithms
// a)  FCFS

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,head;
printf("First come first serve\n");
printf("Enter the number of request(n):");
scanf("%d",&n);
int i,rs[n];
printf("Enter request sequence one by one\n");
for( i=0;i<n;i++){
scanf("%d",&rs[i]);
}
printf("Enter initial head position(p):");
scanf("%d",&head);
int sum=0;
sum=abs(head-rs[0]);

for(int j=1;j<n;j++){
    sum=sum+abs(rs[j]-rs[j-1]);
}

printf("Total seek operation:%d",sum);
return 0;
}