#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
	struct stat fileStat;
	int inode;
	int fd;
	int i;
	if(argc < 2)
	{
		fprintf(stderr,"usage: %s <file>\n",argv[0]);
		return 1;
	}
	else
	{
		printf("cc=%d\t%s",argc,argv[2]);
		for(i=0;i<argc;i++)
		{
			fd=open(argv[i],O_RDONLY);
			if(fd == -1)
			{
				perror("open");
				return 1;
			}if(fstat(fd,&fileStat)<0)return 1;
			else
			{
				printf("Information for %s\n",argv[i]);
				printf("---------------\n");
				printf("Type of file:\t%d\n",fileStat.st_mode);
			}
		}
	}
}
