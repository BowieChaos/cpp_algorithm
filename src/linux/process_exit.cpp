#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid = 0;
	pid = fork();
	int status;
	if (pid == 0) {
		//  return 100;//return返回，见图一
		exit(200); // exit()返回，见图二
	}
	if (pid > 0) {
		wait(&status);
		// printf("CODE= %d \n",WEXITSTATUS(status) );
		printf("CODE2= %d \n", WEXITSTATUS(status));
	}
	return 2; // run  echo $?
}