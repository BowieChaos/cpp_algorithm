#include <stdio.h>
 
int main(int argc,char* argv[])
{
	int wr_ret;
	int rd_ret;
	FILE *fp;
	unsigned long file_size;
	char wr_buf[100] = "hello world";
	char rd_buf[100];
 
	fp = fopen( "a.txt", "a+" );//文件追加，可读可写，文件不存在则创建
	if(fp == NULL)
	{
		perror("open file error:");//只有上面的函数设置了error全局错误号，才可使用，会根据error输出对应的错误信息
		return -1;
	}
 
	wr_ret = fwrite( wr_buf, sizeof(wr_buf), 1, fp);
	printf("wr_ret = %d\n", wr_ret);
 
	rewind(fp);//上面的写操作，文件位置偏移量也会相应的移动，此处将文件偏移到文件开始位置，然后才能读取刚刚输入的内容
	rd_ret = fread(rd_buf, sizeof(rd_buf), 1, fp);
	printf("rd_ret = %d\n",rd_ret);
	printf("content=%s\n", rd_buf);
 
	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	printf("file_size = %lu\n", file_size);
 
	fclose(fp);//关闭文件
 
	return 0;
}