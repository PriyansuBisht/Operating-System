

// Child Processs whose corresponding Parent Process has alredy terminated either by the OS or due 
// to some other reason, these child process are called OTPHAN PROCESSS 

#include<stdio.h>
#include<process.h>
#include<unistd.h>

int main() {
    pid_t p;
    p = fork();

    if( p == 0 ) {
        printf("\nThis is a CHILD process");

        wait(NULL);     // CHILD process goes on wating state

        printf("\n I became an ORPHAN !!!");

    } else if( p > 0 ) {
        printf("\nThis is a PARENT process");

        exit(0);        // PARENT process terminates making CHILD an ORPHAN
                        // later this ORPHAN is adopted by INIT processs
    } else {
        printf("\nThe FORK system call failed !!! ");
        exit(1);
    }
    return 0;
}