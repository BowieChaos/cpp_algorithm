#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
	int fds[2];
	if (pipe(fds) < 0) { //创建一个管道，用于父子间进行通信
		perror("pipe");
		return 1;
	}
	char buf[1024]; //临时数组，用于存放通信的消息

	printf("Please enter：");
	fflush(stdout);
	ssize_t s = read(0, buf, sizeof(buf) - 1);
	if (s > 0) {
		buf[s] = 0;
	}

	pid_t pid = fork();
	if (pid == 0) { //子进程只写,关闭读端
		close(fds[0]);
		while (1) {
			sleep(1);
			write(fds[1], buf, strlen(buf)); //将buf的内容写入管道
		}
	} else { //父进程只读，关闭写端
		close(fds[1]);
		char buf1[1024];
		while (1) {
			ssize_t s =
			    read(fds[0], buf1, sizeof(buf1) - 1); //从管道里读数据，放入buf
			if (s > 0) {
				buf1[s - 1] = 0;
				printf("client->farther：%s\n", buf1);
			}
		}
	}
}
