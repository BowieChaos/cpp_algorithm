#include <fcntl.h>
#include <stdio.h>
#include <string.h> //mencpy()
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int fd;
	char* map_ptr;

	int retval;

	fd = open("a.txt", O_RDWR);
	if (fd == -1) {
		perror("open failed:");
		return -1;
	}

	map_ptr = (char*)mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (map_ptr == MAP_FAILED) {
		perror("map memory failed:");
		return -1;
	}

	printf("%s \n", map_ptr);

	memcpy(map_ptr, "haha", 5);

	retval = munmap(map_ptr, 100);
	if (retval == -1) {
		perror("munmap failed:");
		return -1;
	}

	close(fd);

	return 0;
}