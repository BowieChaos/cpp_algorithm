/* 本来对于fork来说，子进程只继承了父进程的代码副本，mutex理应在父子进程中是相互独立的两个变量，但由于在初始化mutex的时候，由pshared
   = 1指定了mutex处于共享内存区域，所以此时mutex变成了父子进程共享的一个变量。此时，mutex就可以用来同步相关进程了。
 */

#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
	int fd, i;
	int nloop = 10, zero = 0;
	int* ptr;
	sem_t mutex;

	//  open a file and map it into memory
	fd = open("log.txt", O_RDWR | O_CREAT, S_IRWXU);

	write(fd, &zero, sizeof(int));

	ptr = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	close(fd);

	/* create, initialize semaphore */
	if (sem_init(&mutex, 1, 1) < 0) //
	{
		perror("semaphore initilization");
		exit(0);
	}

	if (fork() == 0) { /* child process*/
		for (i = 0; i < nloop; i++) {
			sem_wait(&mutex);

			printf("child: %d\n", (*ptr)++);
			// sleep(1);
			sem_post(&mutex);
		}
		exit(0);
	}

	/* back to parent process */
	for (i = 0; i < nloop; i++) {
		sem_wait(&mutex);

		printf("parent: %d\n", (*ptr)++);
		// sleep(1);
		sem_post(&mutex);
	}
	exit(0);
}