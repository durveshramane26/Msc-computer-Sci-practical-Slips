#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>int main(void)
{
	struct dirent *de;
	struct stat filestat;
	char dirnm[80];
	int sz;
	printf("Enter how many bytes :");
	scanf("%d",&sz);
	strcpy(dirnm,getcwd(dirnm,sizeof(dirnm)));
	printf("\n Current Dir = %s\n",dirnm);
	DIR *dr = opendir(dirnm);
	if(dr==NULL)
	{
		printf("Could not open current Directory \n");
		return 0;
	}
	printf("Files are : \n");
	while((de = readdir(dr)) != NULL)
	{
		if(stat(de->d_name,&filestat)<0)
			printf("Error");
		else
		{
			printf("%d",&filestat.st_size);
			if((filestat.st_size) > sz)
				printf("%s\n",de->d_name);
		}
	}
	closedir(dr);
	return 0;
}
