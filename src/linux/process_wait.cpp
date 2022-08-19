#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/wait.h>
#include <stdlib.h>
 
int main(void)
{
	pid_t pid = -1;
	pid_t ret = -1;
	int status = -1;
	
	pid = fork();
	if (pid > 0)
	{
	//因为wait函数是阻塞的，当父进程先执行，子进程没有结束的情况下，父进程会在wait函数这个地方阻塞住
		printf("parent.\n");
		ret = wait(&status);
		
		printf("子进程已经被回收，子进程pid = %d.\n", ret);
		printf("子进程已经被回收，子进程status = %d.\n", status);
	}
	else if (pid == 0)
	{
		// 子进程
		printf("child pid = %d.\n", getpid());
		//while(1);//子进程不可能结束，所以wait函数被阻塞住，子进程不可能被回收
	}
	else
	{
		perror("fork");
		return -1;
	}
	
	return 0;
}