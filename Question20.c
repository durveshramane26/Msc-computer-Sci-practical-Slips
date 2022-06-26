#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
struct list
{
	char fname[20];
	int size;
}l[10];
void main(int argc,char *argv[])
{
	int i=0,j;
	struct stat sbuff;
	struct list temp;
	for(i=1;i<argc;i++)
	{
		stat(argv[i],&sbuff);
		strcpy(l[i-1].fname,argv[i]);
		l[i-1].size=sbuff.st_size;
	}
	//bubble sort
	for(i=0;i<argc-1;i++)
	{
		for(j=i+1;j<argc-1;j++)
		{
			if(l[i].size > l[j].size)
			{
				strcpy(temp.fname,l[j].fname);
				temp.size=l[j].size;
				strcpy(l[j].fname,l[i].fname);
				l[j].size=l[i].size;
				strcpy(l[i].fname,temp.fname);
				l[i].size=temp.size;
			}
		}
	}
	//printing
	printf("File Name\t File Size\n");
	for(i=0;i<argc-1;i++)
	{
		printf("\n%s\t%d",l[i].fname,l[i].size);
	}
}
