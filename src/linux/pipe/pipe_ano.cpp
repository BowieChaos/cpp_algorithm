#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
	int fd[2];      //文件描述符数组
	char buf[1024]; //临时缓冲区
	int len;
	ssize_t s;
	ssize_t w;
	if (pipe(fd) == -1) { //创建管道
		perror("pipe");
		return -1;
	}

	while (1) {
		printf("Please enter:");
		fflush(stdout);
		s = read(0, buf, sizeof(buf)); //从屏幕上读取内容
		if (s < 0) {
			perror("read");
			return -2;
		}
		len = strlen(buf);

		w = write(fd[1], buf, len); //将读取的数据写入管道
		if (w != len) {
			perror("write");
			return -3;
		}

		memset(buf, 0, sizeof(buf)); //将buf清0

		s = read(fd[0], buf, sizeof(buf)); //从管道当中读取数据
		if (s < 0) {
			perror("read");
			return -4;
		}

		w = write(1, buf, len); //将读的数据写入屏幕
		if (w != len) {
			perror("write");
			return -5;
		}
	}

	return 0;
}