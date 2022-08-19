#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//
int main() {
	umask(0);                                     //将权限清0
	if (mkfifo("./mypipe", 0666 | S_IFIFO) < 0) { //创建管道
		perror("mkfifo");
		return 1;
	}

	int fd = open("./mypipe", O_RDONLY); //打开管道
	if (fd < 0) {
		perror("open");
		return 2;
	}

	char buf[1024];
	while (1) {
		buf[0] = 0;
		printf("请等待。。。\n");
		ssize_t s = read(fd, buf, sizeof(buf) - 1);

		if (s > 0) {
			buf[s - 1] = 0; //过滤\n
			printf("服务器：%s\n", buf);
		} else if (s == 0) { //当客户端退出时，read返回0
			printf("客户端退出，自己退出\n");
			break;
		}
	}
	close(fd);
	return 0;
}
