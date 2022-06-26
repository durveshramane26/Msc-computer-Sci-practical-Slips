#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int spawn ( char * program ,char **arg_list )
{
	pid_t child_pid;
	child_pid =fork();
	if ( child_pid !=0 )
	{
		return child_pid;
	}
	else
	{
		execvp ( program ,arg_list );
		fprintf(stderr,"An error occured in execvp");
		abort();
	}
}
int main ( int argc , char *argv[] )
{
	char * fd =argv[1];
	char *arg_list[]={
		"ls", "-l", fd,
		NULL};
	spawn ("ls" , arg_list);
	printf("%s", fd);
	return 0;
}
