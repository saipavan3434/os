#include<stdio.h>
#include<stdlib.h>
int main()
{
  int par_size,n,count=0,flag,size,wastage;
  char ch;
  printf("Enter the no.of partitions:");
  scanf("%d",&n);
  printf("enter the partition size:");
  scanf("%d",&par_size);
  ch='y';
  while(ch=='y')
  {
    flag=0;
    if(count<n)
    {
     printf("Enter the size of the job you want to execute:");
     scanf("%d",&size);
     if(par_size>=size)
     {
      flag=1;
      count++;
      wastage=par_size-size;
      printf("wastage is %2d\n",wastage);
      }
     }
    else
    {
      printf("no partition is free\n");
      exit(0);
     }
    if(flag==0)
    printf("this job cannot be executed\n");
    printf("Enter your choice (y or n)");
    scanf("\n %c",&ch);
    }
    return 0;
  }
