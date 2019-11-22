#include<stdio.h>
int main()
{
	int sb[20],size[20],n,j,i,x;
	int c[10][10];
	printf("enter no. of files");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter starting blocks and size");
		scanf("%d%d",&sb[i],&size[i]);
		
	}
	for(i=0;i<n;i++){
		printf("enter block occupied by each file %d",i);
		for(j=0;j<size[i];j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	printf("file name\t index \t size \t\t blockoccupied\n");
	for(i=0;i<n;i++)
	{
		printf("\n p[%d] \t %d \t %d\t",i,sb[i],size[i]);
		for(j=0;j<size[i];j++)
		printf(" \t %3d",c[i][j]);
	}
	
}
