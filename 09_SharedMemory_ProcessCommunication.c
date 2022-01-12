// Writer Process Code

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <sys/shm.h>
#include <sys/ipc.h>

int main() {		// Writer Process
	key_t key = ftok("MSG", 5);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *ptr = (char*)shmat(shmid, NULL, 0);

	printf("Enter data to put in shared memory: ");
	fgets(ptr, 512, stdin);
	shmdt(ptr);
	return 0;
}

// Reader Process Code

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
//#include <sys/shm.h>
#include <sys/ipc.h>

int main() {        // Reader Process
	key_t key = ftok("MSG", 5);
	int shmid = shmget(key, 1024, 0666);
	char *ptr = (char*)shmat(shmid, NULL, 0);
	
	printf("Data passed by writer process in shared memory is: %s", ptr);
	shmdt(ptr);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
