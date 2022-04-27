#include <stdio.h>
#include <unistd.h>
void main()
{
    int fd[2], n;
    char msg[] = "Hai, This is my message\n";
    char buffer[100];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if (pid != 0)
    {
        printf("Parent process with pid: %d\n", getpid());
        write(fd[1], msg, sizeof(msg));
    }
    else
    {
        printf("Child process with pid: %d\n", getpid());
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
    }
}
