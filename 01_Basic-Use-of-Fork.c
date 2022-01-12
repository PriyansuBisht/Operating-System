#include <stdio.h>
#include <process.h>
#include <unistd.h>

int main()
{
    int i = 0;
    pid_t pid ;     // create a process id element to store process id, t = getpid(); 
    i++;
    printf("\n PROCESS ID %d IS : %d", i, getpid());

    fork();
    i++;
    printf("\n PROCESS ID %d IS : %d", i, getpid());

    fork();
    i++;
    printf("\n PROCESS ID %d IS : %d", i, getpid());
}