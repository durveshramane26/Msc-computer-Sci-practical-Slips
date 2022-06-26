#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (int argc, char *argv[])
{
	struct stat fileStat;
	int fd=0,i;
	FILE *filename;
	for(i=0;i<argc;i++)
	{
		filename = argv[i];
		if ( ( fd = open (filename , O_RDONLY) ) == -1)
		{
			perror ( "open " );
			system("pause");
			exit (1) ;
		}
		if(fstat(fd, &fileStat)<0) return 1;
		printf("Inode for %s\n",filename);
		printf("---------------------------\n");
		//printf("File Size: \t\t%d bytes\n",fileStat.st_size);
		//printf("Number of Links: \t%d\n",fileStat.st_nlink);
		printf("File inode: \t\t%d\n\n",fileStat.st_ino);
	}
	//printf("\n%d\n",argc);
	//printf("\n%s\n",argv[0]);
	return 0;
}
