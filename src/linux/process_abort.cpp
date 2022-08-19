#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid = 0;
	pid = fork();
	int status;
	if (pid == 0) {
		abort();
	}
	if (pid > 0) {
		wait(&status);
		printf("CODE= %d \n", WEXITSTATUS(status));
	}
	return 0;
}