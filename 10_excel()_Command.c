#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>

int main() {
	pid_tpid;
	pid = fork();

	if (pid< 0) {
		printf("Fork Failed\n");
		exit(1);
	} else if (pid == 0) {
		execl("/bin/date", "date", NULL);
	} else {
		execl("/bin/ls", "ls", "-l", NULL);
	}
	return 0;
}
