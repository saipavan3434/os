#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
	char fname[12];
	int fstart,length;
}direntry[10];
struct
{
	int start,size;
}flist[10];
int m=0,n=0,start=500;
void create();
void del();
void compaction();
void display();
int main()
{
	int ch;
	flist[0].start=0;
	flist[0].size=start;
	while(1)
	{
		printf("\n1.Create\n2.Delete\n3.Compaction\n4.Display\n5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				del();
				break;
			case 3:
				compaction();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default:
				printf("You have entered a wrong number\n");
		}
	}
	return 0;
}
void create()
{
	int i,size,flag=0,j,a;
	char name[12];
	printf("Enter the name of file: ");
	scanf("%s",name);
	printf("Enter the size of the file: ");
	scanf("%d",&size);
	for(i=0;i<=m;i++)
	{
		if(flist[i].size >= size)
		{
			a=i,flag=1;
		}
	}
	if(flag)
	{
		strcpy(direntry[n].fname,name);
		direntry[n].length=size;
		direntry[n].fstart=flist[a].start;
		flist[a].start +=size;
		flist[a].size -=size;
		n++;
	}
	else
	{
		printf("No enough space\n");
		flag=0;
		compaction();
		for(i=0;i<=m;i++)
		{
			if(flist[i].size >= size)
			{
				a=i,flag=1;
			}
		}
		if(flag)
		{
			strcpy(direntry[n].fname,name);
			direntry[n].length=size;
			direntry[n].fstart=flist[a].start;
			flist[a].start +=size;
			flist[a].size -=size;
			n++;
		}
		else
		{
			printf("No enough space\n");
		}
	}
}
void del()
{
	int i,j,k;
	char name[12];
	printf("Enter the file name: ");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(!strcmp(direntry[i].fname,name))
		{
			break;
		}
	}
	if(i==n)
	{
		printf("No such file exists.....\n");
	}
	else
	{
		m++;
		flist[m].start=direntry[i].fstart;
		flist[m].size=direntry[i].length;
		for(k=i;k<n;k++)
		{
			direntry[k]=direntry[k+1];
		}
		n--;
	}
}
void compaction()
{
	int i,j,size1=0;
	for(i=0;i<n;i++)
	{
		direntry[i].fstart=size1;
		size1+=direntry[i].length;
	}
	flist[0].start=size1;
	flist[0].size=start-size1;
	m=0;
}
void display()
{
	int i;
	
	printf("\n   ***   Directory Contents  ***  \n");
	printf("\n\nName    Starting address   Length  \n\n");
	for(i=0;i<n;i++)
	{
		printf("%s%10d%10d\n",direntry[i].fname,direntry[i].fstart,direntry[i].length);
	}
		printf("\n\n");
		printf("\n\n*** Free Space Table ***\n\n");
		printf("Freestartaddress     Free size  \n\n");
		for(i=0;i<=m;i++)
		{
			printf(" %d            %d\n",flist[i].start,flist[i].size);
		}
}
