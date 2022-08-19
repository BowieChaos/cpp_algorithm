#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int fd = open("./mypipe", O_WRONLY); //打开管道
	if (fd < 0) {
		perror("open");
		return 1;
	}

	char buf[1024];
	while (1) {
		printf("客户端：");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf) - 1); //向管道文件中写数据
		if (s > 0) {
			buf[s] = 0; //以字符串的形式写
			write(fd, buf, strlen(buf));
		}
	}
	close(fd);
	return 0;
}
