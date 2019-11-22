#include<stdio.h>
struct st {
	char dname[10];
	char sdname[10][10];
	char fname[10][10][10];
	int ds,sds;
}dir[10];
main(){
	int i,j,k,n;
	printf("enter number of directories");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter directory %d name \t",1);
		scanf("%s",dir[i].dname);
		printf("enter size of directory \t");
		scanf("%d",&dir[i].ds);
		for(j=0;j<dir[i].ds;j++)
		{
			printf("enter subdirectory name \t");
			scanf("%s",dir[i].sdname[j]);
			printf("enter subdirectory size \t");
			scanf("%d",&dir[i].sds);
			for(k=0;k<dir[i].sds;k++)
			{
				printf("enter file name \t ");
				scanf("%s",dir[i].fname[j][k]);
			}
		}
	}
	printf("\n dirname \t size \t subdirname \t size \t files \n");
	for(i=0;i<n;i++)
	{
		printf("%s\t %d",dir[i].dname,dir[i].ds);
		for(j=0;j<dir[i].ds;j++)
		{
			printf("\t \t \t %s \t %d \t",dir[i].sdname[j],dir[i].sds);
			for(k=0;k<dir[i].sds;k++)
			{
				printf(" %s \n",dir[i].fname[j][k]);
			}
			
		}
	}
}

