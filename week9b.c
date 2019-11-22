#include<stdio.h>
#include<string.h>

void display();
typedef struct 
{
	char uname[15];
	char fname[20][12];
	int size;
}subdir;

subdir user[20];
int n=0;

void main()
{
	int i,j,k,ch;
	char id[12];

	printf("Enter your choice: ");
	printf("\n1.Logging in for the first time\n2.Already have login\n3.Display\n4.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	do
	{
		switch(ch)
		{
			case 1:
				printf("Enter Username: ");
				scanf("%s",user[n].uname);
				user[n].size=0;
				createfiles(n);
				n++;
				break;
			case 2:
				printf("Enter your login id: ");
				scanf("%s",id);

				for(i=0;i<n;i++)
				{
					k=strcmp(user[i].uname,id);
					if(k==0)
					{
						createfiles(i);
						break;
					}
				}
				if(i==n)
				{
					printf("No such login id in the file system\n");
				}
				break;
			case 3:
				display();
				break;
		}
		printf("Enter your choice: ");
		scanf("%d",&ch);
	}while(ch != 4);
}
createfiles(int id)
{
	int i,v,ch,size;
	size=user[id].size;

	do
	{
		w:printf("Enter filename: ");
		scanf("%s",user[id].fname[size]);
		i=0;
		while(i<size)
		{
			v = strcmp(user[id].fname[i],user[id].fname[size]);
			if(v == 0)
			{
				printf("File already exist\n Please Enter other name");
				goto w;
			}
			i++;
		}
		size=++user[id].size;
		printf("Do you want to create another file(1/0): ");
		scanf("%d",&ch);
	}while(ch != 0);
	return 0;
}
//Displaying the contents of the file system
void display()
{
	int i,j;
	printf("The contents of the file system are\n");
	printf("Username\t Files\n");
	printf("***********************************\n");
	for(i=0;i<n;i++)
	{
		printf("\n%s",user[i].uname);
		for(j=0;j<user[i].size;j++)
		{
			printf("\t%s\n",user[i].fname[j]);
		}
		printf("-----------------------------------\n");
	}
}
