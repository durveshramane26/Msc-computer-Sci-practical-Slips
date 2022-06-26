#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (int argc, char *argv[])
{
	struct stat fileStat;
	int fd=0;
	FILE *filename;
	filename = (FILE *)argv[1];
	//printf("\n%s\n",argv[1]);
	if ( ( fd = open (filename , O_RDONLY) ) == -1)
	{
		perror ("open ");
		system("pause");
		exit (1) ;
	}
	if(fstat(fd, &fileStat)<0) return 1;
	printf("File Size: \t\t%d bytes\n",fileStat.st_size);
	printf("Mode: \t\t%d\n",fileStat.st_mode);
	return 0;
}
