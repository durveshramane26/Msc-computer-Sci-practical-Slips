#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	char fnm[20];
	int fp;
	struct stat st;
	printf("\n Enter the filename :");
	scanf("%s",fnm);
	fp=open(fnm,O_RDONLY);
	if(fp < 0)
		printf("\n File openinng error");
	else
	{
		sleep(15);
	}
	close(fp);
}
