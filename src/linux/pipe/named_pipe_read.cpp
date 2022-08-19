#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//从管道文件里面读取内容，并将内容写入另一个文件中
int main() {
	int infd = open("abc.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644); //创建一个新的文件
	if (infd == -1) {
		perror("open");
		return 1;
	}

	//将从管道读取的内容写入到新的文件中

	int outfd = open("tp", O_RDONLY); //打开管道文件
	if (outfd == -1) {
		perror("open");
		return 2;
	}

	char buf[1024]; //临时数组
	ssize_t s;

	while ((s = read(outfd, buf, sizeof(buf))) > 0) {
		write(infd, buf, s);
	}
	close(infd);
	close(outfd);

	return 0;
}
