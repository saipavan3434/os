#include<stdio.h> 

struct process 
{ 
	int pid,bt,tt,wt; 
}; 
int main() 
{ 
	struct process x[10],p[30]; 
	int i,j,k,tot=0,m,n; 
	float wttime=0.0,tottime,a1,a2;
	
	printf("Enter No.of processes: "); 
	scanf("%d",&n); 
	for(i=1;i<=n;i++) 
	{ 
		x[i].pid=i; 
		printf("Enter The Burst Time: "); 
		scanf("%d",&x[i].bt); 
		x[i].tt=0; 
		tot=tot+x[i].bt; 
	} 
	//printf("\n%d",tot); 
	printf("Total Burst Time: %d\n",tot); 
	p[0].tt=0; 
	k=1; 
	printf("Enter The Time Slice: "); 
	scanf("%d",&m); 
	while(tot>0) 
	{ 
		for(i=1;i<=n;i++) 
		{ 
			if(x[i].bt!=0) 
			{ 
				p[k].pid=i; 
				if(x[i].bt-m<0) 
				{ 
					p[k].wt=p[k-1].tt-x[i].tt; 
					p[k].bt=x[i].bt; 
					p[k].tt=p[k-1].tt+x[i].bt; 
					x[i].tt+=p[k].wt+x[i].bt; 
					tot-=x[i].bt; 
					x[i].bt=0; 
					k++; 
				} 
				else
				{ 
					p[k].wt=p[k-1].tt-x[i].tt; 
					p[k].tt=p[k-1].tt+m; 
					x[i].bt=x[i].bt-m; 
					x[i].tt+=p[k].wt+m; 
					tot-=m; 
					k++; 
				} 
			} 
		} 
		printf("Remaining burst time:%d\n",tot);
	} 
	printf("\npid\t wt\ttat\n");
	printf("=====================================\n");
	for(i=1;i<k;i++) 
	{ 
		printf("\n%d\t%d\t%d",p[i].pid,p[i].wt,p[i].tt); 
		wttime=wttime+p[i].wt; 
	} 
	printf("\n=====================================\n");
	for(i=1;i<=n;i++) 
	tottime=tottime+x[i].tt; 
	a1=wttime/n; 
	a2=tottime/n; 
	printf("\nAverage Waiting Time: %.2f",a1); 
	printf("Average TurnAround Time: %.2f\n",a2); 
	return 0; 
}
