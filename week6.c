#include<stdio.h>

int main()
{
	int psize=0,size=0,flag;
	char ch;
	
	printf("Enter the size of memory: ");
	scanf("%d",&size);
	ch = 'y';
	
	while(ch == 'y')
	{
		printf("Enter the size of the job that is to be executed: ");
		scanf("%d",&psize);
		flag=0;
		
		if(size>=psize)
		{
			flag = 1;
			size = size-psize;
			printf("Job is executed\n");
			printf("Free space available is :%d\n",size);
		}
		else
		{
			printf("No free space available\n");
		}
		if(flag == 0)
		{
			printf("The job cannot be executed\n");
		}
		printf("Enter your choice(y or n): ");
		scanf("%s",&ch);
	}
}
