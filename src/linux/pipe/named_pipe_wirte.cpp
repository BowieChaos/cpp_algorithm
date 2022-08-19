#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
//读取文件，将文件内容写入管道
int main() {
	mkfifo("tp", 0644);               //创建一个管道文件
	int infd = open("123", O_RDONLY); //打开一个文件
	if (infd == -1) {
		perror("open");
		return 1;
	}

	int outfd = open("tp", O_WRONLY); //打开管道文件，将123文件的内容写入管道文件
	if (outfd == -1) {
		perror("open");
		return 2;
	}

	char buf[1024]; //用于存放文件内容
	ssize_t s;

	while ((s = read(infd, buf, sizeof(buf))) > 0) {
		write(outfd, buf, s);
	}
	close(infd);
	close(outfd);
}
