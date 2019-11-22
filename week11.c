#include<stdio.h>  
void input();  
void display();  
int safe();  
void request();  
int m,n,i,j,k,Avail[10],Alloc[10][10],Max[10][10],Need[10][10];  
void main()  
{
  int ch;  
  do
  {
     printf("-------MENU--------");
     printf("\n1.Input\n2.Display\n3.Safe\n4.Request\n5.Exit\n");
     printf("Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
          case 1:
               input();
               break;
          case 2:
               display();
               break;
          case 3:
               if(safe())
                    printf("\nThe System is in Safe state");
               else
                    printf("\n The System is in Unsafe state");
               break;
          case 4:
               request();
               break;
          }
     }while(ch!=5);
}
void input()  
{  
     printf("Enter the number of resource types: ");
     scanf("%d",&m);
     printf("Enter the number of active processes in the system: ");  
     scanf("%d",&n);  
     printf("Enter the available vector of length %d:",m);  
     for(i=0;i<m;i++)
          scanf("%d",&Avail[i]);  
     printf("Enter the content of matrix: Max of%dX%d:",n,m);  
     for(i=0;i<n;i++)
          for(j=0;j<m;j++)
               scanf("%d",&Max[i][j]);  
     printf("Enter the content of matrix: Alloc of%dX%d:",n,m);  
     for(i=0;i<n;i++)
          for(j=0;j<m;j++)
               scanf("%d",&Alloc[i][j]);  
     for(i=0;i<n;i++)
          for(j=0;j<m;j++)
               Need[i][j]=Max[i][j]-Alloc[i][j];  
}  
void display()  
{  
     printf("The Current Resource Allocation State is\n");  
     printf("The content of matrix Max is\n");  
     for(i=0;i<n;i++)  
     {  
          printf("\n");  
          for(j=0;j<m;j++)  
               printf("%d\t",Max[i][j]);  
     }  
     printf("The content of matrix Alloc is\n");  
     for(i=0;i<n;i++)  
     {  
          printf("\n");  
          for(j=0;j<m;j++)  
               printf("%d\t",Alloc[i][j]);  
     }  
     printf("The content of matrix Need is\n");  
     for(i=0;i<n;i++)  
     {  
          printf("\n");  
          for(j=0;j<m;j++)  
               printf("%d\t",Need[i][j]);  
     }  
     printf("The content of vector Avail is\n");  
     for(i=0;i<m;i++)  
          printf("%d\t",Avail[i]);  
}
int safe()  
{
     int Work[10],Finish[10],flag=0,count=0;
     for(i=0;i<m;i++)
          Work[i]=Avail[i];  
     for(i=0;i<n;i++)  
          Finish[i]=0;  
     do  
     {  
          for(i=0;i<n;i++)  
          {  
               if(Finish[i]==0)  
               {  
                    flag=0;  
                    for(j=0;j<m;j++)
                         if(Need[i][j]>Work[j])
                              break;
                         if(j==m)
                         {
                              count++;
                              flag=1;
                              printf("P%d->",i);
                              break;
                         }
               }
          }
          if(flag)
          {
               for(j=0;j<m;j++)
                    Work[j]+=Alloc[i][j];
               Finish[i]=1;
          }
     }while(flag && count<n);  
     for(i=0;i<n;i++)  
     if(Finish[i]==0)  
     return 0;  
     return 1;  
}  
void request()  
{  
     int request[10];
     printf("Enter the proces requesting resources: ");
     scanf("%d",&i);
     printf("Enter the Process P%d request: ",i);
     for(j=0;j<m;j++)
          scanf("%d",&request[j]);
     for(j=0;j<m;j++)
          if(request[j]>Need[i][j])
          {
               printf("Not a valid request: exceeding maximum claim\n");
               return;
          }
     for(j=0;j<m;j++)
          if(request[j]>Avail[j])
          {
               printf("The resources are not not available, so the process P%d should wait\n",i);
               return;
          }  
     //Pretending allocation of resources  
     for(j=0;j<m;j++)
     {
          Alloc[i][j]+=request[j];
          Need[i][j]-=request[j];
          Avail[j]-=request[j];
     }
     if(safe())
          printf("The request can be granted immediately\n");
     else
     {  //Restoring to old state of the system
          for(j=0;j<m;j++)
          {
               Alloc[i][j]-=request[j];
               Need[i][j]+=request[j];
               Avail[j]+=request[j];
          }
          printf("The request can not be granted immediately, the process P%d must be delayed\n",i);
     }
}
