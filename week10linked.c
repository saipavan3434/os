#include<stdio.h>
#define size 32
struct
{
	char fname[12];
	int start,end;
}direntry[10];
struct
{
	int b_no,next;
}list_blocks[size];
int n=0,fsl_first=0,fsl_size=32;

void create();
void del();
void display();

int main()
{
	int ch,i;
	for(i=0;i<size;i++)
	{
		list_blocks[i].b_no=i;
		list_blocks[i].next=i+1;
	}
	list_blocks[i-1].next=-1;
	do
	{
		printf("1.create\n2.delete\n3.display\n4.exit\nenter your choice: \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
					break;
			case 2:del();
					break;
			case 3:display();
					break;
			case 4:exit(1);
		}
	}while(ch!=4);
	return 0;
}

void create()
{
	int i,fsize,last;
	char name[12];
	printf("\nenter the name of file: ");
	scanf("%s",name);
	printf("\nenter the size of the file: ");
	scanf("%d",&fsize);
	if(fsl_size>=fsize)
	{
		strcpy(direntry[n].fname,name);
		direntry[n].start=fsl_first;
		for(i=0;i<fsize-1;i++)
		fsl_first=list_blocks[fsl_first].next;
		last=direntry[n].end=fsl_first;
		fsl_first=list_blocks[fsl_first].b_no;
		list_blocks[last].next=-1;
		fsl_size-=fsize;
		n++;
	}
	else
	printf("\n no enough space \n");
}

void del()
{
	int i,k,fsize;
	char name[12];
	printf("\nenter the file name which u want to delete: ");
	scanf("%s",name);
	printf("\nenter the size of file");
	scanf("%d",&fsize);
	for(i=0;i<n;i++)
	if(!strcmp(direntry[i].fname,name))
	break;
	if(i==n)
	printf("\nno such file exists");
	else
	{
		list_blocks[direntry[i].end].next=fsl_first;
		fsl_first=list_blocks[direntry[i].start].b_no;
		fsl_size+=fsize;
		for(k=i;k<n;k++)
		direntry[k]=direntry[k+1];
		n--;
	}
}

void display()
{
	int i;
	printf("\n *** directory contents *** \n");
	printf("\n\n name\tstarting address\tend address\n\n");
	for(i=0;i<n;i++)
	printf("%s%10d%10d\n",direntry[i].fname,direntry[i].start,direntry[i].end);
	printf("\n\n\n\n*** free space list ***\n\n");
	printf("free space list start\tfre size\n\n");
	printf("%d\t%d\n",fsl_first,fsl_size);
}
