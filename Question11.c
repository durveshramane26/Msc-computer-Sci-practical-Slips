#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char** argv)
{
	int des_p[2];
	if(pipe(des_p) == -1)
	{
		perror("Pipe Failed");
		exit(1);
	}
	if(fork()==0)
	{
		close(STDOUT_FILENO);
		dup(des_p[1]);
		close(des_p[0]);
		close(des_p[1]);
		const char* progl[] = {"ls","-l",0};
		execvp(progl[0],progl);
		perror("execvp of ls failed");
		exit(1);
	}
	if(fork()==0)
	{
		close(STDIN_FILENO);
		dup(des_p[0]);
		close(des_p[1]);
		close(des_p[0]);
		const char* prog2[] = {"wc","-l",0};
		execvp(prog2[0],prog2);
		perror("execvp of wc failed");
		exit(1);
	}
}
