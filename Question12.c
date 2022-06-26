#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
int main(void)
{
	struct dirent *de;
	struct stat filestat;
	char dirnm[80];
	strcpy(dirnm,getcwd(dirnm,sizeof(dirnm)));
	char mn[20];
	printf("\n Enter the month: ");
	scanf("%s",&mn);
	printf("\n Current Dir = %s\n",dirnm);
	DIR *dr = opendir(dirnm);
	if(dr==NULL)
	{
		printf("Could not open current Directory");
		return 0;
	}
	printf("Files created in the month if %s are : \n",mn);
	while((de = readdir(dr)) != NULL)
	{
		if(stat(de->d_name,&filestat)<0)
			printf("Error");
		else
		{
			//printf("%s",ctime(&filestat.st_mtime));
			if(strstr(ctime(&filestat.st_mtime),mn))
				printf("%s\n",de->d_name);
		}
	}
	closedir(dr);
	return 0;
}
