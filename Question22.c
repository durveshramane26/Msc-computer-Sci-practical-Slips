#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int fd[2];
    pid_t pid1, pid2;

    if (pipe(fd) < 0)
        perror("pipe error"), exit(1);
    else if ((pid1 = fork()) < 0)
        perror("fork error"), exit(1);
    else if (pid1 == 0)
    {
        /* ls */
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", (char *)0);
        perror("exec ls");
        exit(1);
    }
    else if ((pid2 = fork()) < 0)
        perror("fork error"), exit(1);
    else if (pid2 == 0)
    {
        /* wc */
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", (char *)0);
        perror("exec wc");
        exit(1);
    }
    else
    {
        close(fd[0]);
        close(fd[1]);
        int status1;
        int status2;
        int corpse1 = waitpid(pid1, &status1, 0);
        int corpse2 = waitpid(pid2, &status2, 0);
        printf("ls: pid = %d, corpse = %d, exit status = 0x%.4X\n", pid1, corpse1, status1);
        printf("ls: pid = %d, corpse = %d, exit status = 0x%.4X\n", pid2, corpse2, status2);
    }
    return 0;
}
