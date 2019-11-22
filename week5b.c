#include<stdio.h>
#include<string.h>

void main()
{
	char p[10][15],temp[5];
	int tot=0,wt[10],i,j,n,pt[10],temp1,turn[10],totturn=0;
	float avg=0,avgturn=0;
	
	printf("Enter the no.of.processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter process %d name: ",i+1);
		scanf("%s",p[i]);
		printf("Enter the process time: ");
		scanf("%d",&pt[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pt[i]>pt[j])
			{
				temp1 = pt[i];
				pt[i] = pt[j];
				pt[j] = temp1;
				strcpy(temp,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],temp);
			}
		}
	}
	wt[0] = 0;
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + pt[i-1];
		tot = tot + wt[i];
	}
	avg = (float)tot/n;
	for(i=0;i<n;i++)
	{
		turn[i] = pt[i] + wt[i];
		totturn = totturn + turn[i];
	}
	avgturn = (float)totturn/n;
	printf("p_name\tp_time\tw_time\tturn_time\t\n");
	printf("=====================================================\n");
	for(i=0;i<n;i++)
	printf("%s\t%d\t%d\t%d\n",p[i],pt[i],wt[i],turn[i]);
	printf("=====================================================\n");
	printf("\n Total waiting time = %d\n Avg waiting time = %f\n Turn time = %d\n Avg turn time = %f\n",tot,avg,totturn,avgturn);
}
