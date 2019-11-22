#include<stdio.h>
#include<string.h>

void main()
{
	char p[10][5],temp[5],turn[10],totturn=0;
	int i,j,pt[10],totwt=0,pr[10],temp1,n,wt[10];
	float avgwt=0,avgturn=0;
	
	printf("Enter no.of.processes: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter process %d name: ",i+1);
		scanf("%s",p[i]);
		printf("Enter the process time: ");
		scanf("%d",&pt[i]);
		printf("Enter the priority: ");
		scanf("%d",&pr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j] && pr[i]>pr[j])
			{
				temp1 = at[i];
				at[i] = at[j];
				at[j] = temp1;
				temp1=pr[i];
				pr[i]=pr[j];
				pr[j]=temp1;
				temp1=pt[i];
				pt[i]=pt[j];
				pt[j]=temp1;
				strcpy(temp,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],temp);
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + pt[i-1];
		totwt = totwt + wt[i];
	}
	avgwt = (float)totwt/n;
	for(i=0;i<n;i++)
	{
		turn[i] = pt[i] + wt[i];
		totturn = totturn + turn[i];
	}
	avgturn = (float)totturn/n;
	printf("p_name\tp_time\tpriority\tw_time\tturn_time\t\n");
	printf("=====================================================\n");
	for(i=0;i<n;i++)
	printf("%s\t%2d\t%4d\t\t%d\t%d\n",p[i],pt[i],pr[i],wt[i],turn[i]);
	printf("=====================================================\n");
	printf("\n Total waiting time = %d\n Avg waiting time = %f\n Turn time = %d\n Avg turn time = %f\n",totwt,avgwt,totturn,avgturn);
}
