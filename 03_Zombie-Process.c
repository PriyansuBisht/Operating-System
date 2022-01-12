

/*  When a CHILD process terminates, it frees the resources, but mantain an entry in the process id table
    this entry is kept till the PARENT process ends, this child is called ZOMBIE process
    presented as DEFUNCT process & Z+ & have a value of 1
*/  


#include<stdio.h>
#include<process.h>
#include<unistd.h>

int main() {
    pid_t p = fork();

    if( p > 0) {       // PARENT process
        printf("\nThis is a PARENT Process");

        sleep(15);      // PARENT goes to sleep for 15 ms or s

        printf("\nMy CHILD became a ZOMBIE !!! ");

    } else if ( p == 0 ) {       // CHILD process
        printf("\nThis is a CHILD process");

        exit(0);        // CHILD terminates while PARENT is asleep hence becomes a ZOMBIE process

    } else {
        printf("\nFORK system call failed !!! ");
        exit(1);
    }
}
