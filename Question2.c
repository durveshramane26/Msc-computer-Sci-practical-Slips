#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>
#include<sys/times.h>
#include<stdlib.h>
int main(void)
{
    int i,status;
    pid_t pid;
    time_t currentTime;
    struct tms cpuTime;
    if((pid = fork())== -1)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if(pid==0)
    {
        time(&currentTime);
        printf("Child proccess started at %s",ctime(&currentTime));
        for(i=0;i< 5; ++i)
        {
            printf("Counting: %d \n",i);
            sleep(i);
        }
        time(&currentTime);
        printf("Child Process ended at %s",ctime(&currentTime));
        exit(EXIT_SUCCESS);
    }
    else{
        time(&currentTime);
        printf("Parent process Started at %s",ctime(&currentTime));
        if(wait(&status)== -1)
            perror("wait error");
        if(WIFEXITED(status))
            printf("Child Process ended normally");
        else
            printf("Child Process did not ended normally\n");
        if(times(&cpuTime)<0)
            perror("Times error");
        else {
            printf("Parent process user time = %ld \n",((double)
            cpuTime.tms_utime)/_SC_CLK_TCK);
            printf("Parent process system time = %ld \n",((double)
            cpuTime.tms_stime)/_SC_CLK_TCK);
            printf("Child process user time = %ld \n",((double)
            cpuTime.tms_cutime)/_SC_CLK_TCK);
            printf("Child process system time = %ld \n",((double)
            cpuTime.tms_cstime)/_SC_CLK_TCK);
        }
        time(&currentTime);
        printf("Parent Process ended at %s",ctime(&currentTime));
        exit(EXIT_SUCCESS);
    }
}