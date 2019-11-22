#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1000

void replaceAll(char *str,const char *oldWord,const char *newWord);

int main()
{
	FILE *fPtr;
	FILE *fTemp;
	char path[100];
	char buffer[BUFFER_SIZE];
	char oldWord[100];
	char newWord[100];
	printf("Enter path of source file:");
	scanf("%s",path);
	printf("Enter word to replace:");
	scanf ("%s",oldWord);
	printf("Replace %s with:");
	scanf("%s",newWord);
	fPtr=fopen(path,"r");
	fTemp=fopen("replace.tmp","w");
	if(fPtr == NULL || fTemp == NULL)
	{
		printf("Unable to open file\n");
		printf("Please check whether file exists and you have read/write privilage\n");
		exit(EXIT_SUCCESS);
	}
	while((fgets(buffer,BUFFER_SIZE,fPtr)!= NULL))
	{
		replaceAll(buffer,oldWord,newWord);
		fputs(buffer,fTemp);
	}
	fclose(fPtr);
	fclose(fTemp);
	remove(path);
	rename("replace.tmp",path);
	printf("Successfully replaced all occurences of '%s' with '%s'.",oldWord,newWord);
	return 0;
}
void replaceAll(char *str,const char *oldWord,const char *newWord)
{
	char *pos;
	char temp[BUFFER_SIZE];
	int index=0,owlen;
	
	owlen = strlen(oldWord);
	
	while((pos=strstr(str,oldWord))!= NULL)
	{
		strcpy(temp,str);
		index= pos-str;
		str[index] = '\0';
		strcat(str,newWord);
		strcat(str,temp+index+owlen);
	}
}
