#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

void renamefun();
void removefun();

void renamefun()
{
          int ret;
          char oldname[20],newname[20];
          
          printf("Enter old file name: ");
          scanf("%s",oldname);
          printf("Enter newfile name: ");
          scanf("%s",newname);
          
          ret = rename(oldname,newname);
          
          if(ret ==0)
          {
                    printf("File renamed successfully\n");
          }
          else
          {
                    printf("Error:Unable to rename the file\n");
          }
          //return 0;
}
void removefun()
{
          int status;
          char filename[15];
          
          printf("Enter name of the file you want to delete: ");
          scanf("%s",filename);
          status = remove(filename);
          
          if(status == 0)
          {
                    printf("%s file deleted successfully\n",filename);
          }
          else
          {
                    printf("Unable to delete the file\n");
          }
          //return 0;
}
int main()
{
	int ch;
	while(1)
	{
		printf("\tMenu\n\t1.Rename a file\n\t2.Delete a file or a directory\n\t3.Output Process Information\n\t4.Execute\"mode 644 ls -l\"\n\t5.Exit\n");
		printf("\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				renamefun();
				break;
			case 2:
				removefun();
				break;
			case 3:
				printf("Output Process-Information\n");
				system("ps");
				break;
			case 4:
				printf("Execute mode 644 ls -l\n");
				system("ls -l");
				break;
			case 5:
				exit(0);
			default:
				printf("Enter a number between 1-5\n");
		}
	}
}
