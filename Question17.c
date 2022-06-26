#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
int main()
{
	char command[30],cmd[10],dnm[50],op[50],func[50];
	DIR *dp;
	struct dirent *dirf;
	int file,pid,cnt=0;
	while(1)
	{
		printf("\n ---");
		gets(func);
		sscanf(func,"%s %s %s",cmd,op,dnm);
		pid=fork();
		if(pid==0)
		{
			if(strcmp(cmd,"list")==0)
			{
				if(op[0]=='f')
				{dp=opendir(dnm);
					while((dirf=readdir(dp))!=NULL)
					{
						printf("\n Name %s",dirf->d_name);
					}
					closedir(dp);
				}
				if(op[0]=='n')
				{
					cnt=0;
					dp=opendir(dnm);
					while((dirf=readdir(dp))!=NULL)
					{
						cnt++;
					}
					printf("\n Number of files %d",cnt);
					closedir(dp);
				}
				if(op[0]=='i')
				{
					dp=opendir(dnm);
					while((dirf=readdir(dp))!=NULL)
					{
						printf("\n File name=%s and nodes=%d \n",dirf->d_name,dirf->d_ino);
					}
					closedir(dp);
				}
			}
			else if(strcmp(cmd,"exit")==0)
			{
				exit(0);
			}
		}
	}
}
