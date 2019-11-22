#include<stdio.h>

int i,j,nof,nop,flag=0,pgno[50],frm[50],pf=0,victim=-1;

void main()
{
	printf("FIFO Page Replacement Algorithm\n");
	printf("Enter no.of.frames: ");
	scanf("%d",&nof);
	printf("Enter no.of.pages in reference string: ");
	scanf("%d",&nop);
	
	printf("Enter the page no: ");
	for(i=0;i<nop;i++)
		scanf("%d",&pgno[i]);
	
	printf("The given pages are: ");
	for(i=0;i<nop;i++)
		printf("%4d",pgno[i]);
	
	for(i=1;i<nof;i++)
	frm[i] = -1;
	printf("\n");
	
	for(i=0;i<nop;i++)
	{
		flag=0;
		printf("\nPage no %d->\t",pgno[i]);
		for(j=0;j<nof;j++)
		{
			if(frm[j] == pgno[i])
			{
				flag=1;
				printf("--No--PF--");
				break;
			}
		}
		if(flag == 0)
		{
			pf++;
			victim++;
			victim %= nof;
			frm[victim] = pgno[i];
			printf("Frame->");
			for(j=0;j<nof;j++)
			printf("%d|",frm[j]);
		}
	}
	printf("\nNo.of.page faults: %d\n",pf);
}
