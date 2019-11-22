#include<stdio.h>
#include<string.h>

int main()
{
	int s=0,i,ch,v;
	char f[20][12];

	do
	{
		w:printf("Enter filename: ");
		scanf("%s",f[s]);
		i=0;
		while(i < s)
		{
			v = strcmp(f[s],f[i]);
			if(v == 0)
			{
				printf("File already exist\n Please Enter other name");
				goto w;
			}
			i++;
		}
		s++;
		printf("Do you want to create another file(1/0): ");
		scanf("%d",&ch);
	}while(ch != 0);
	printf("The files in the file system are\n");
	for(i=0;i<s;i++)
	{
		printf("\n%d\t%s",i+1,f[i]);
	}
	return 0;
}
