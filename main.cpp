/* #include "src/algorithm/other/all.h"
#include <iostream>
#include <map>
#include <set>

class Solution {
public:
	int NumberOf1(int n) {
		unsigned int base = 0x80000000;
		int ret = 0;
		while (base != 0) {
			if ((n & base) != 0) {
				ret++;
			}
			base = base >> 1;
		}
		return ret;
	}
};

void test() {
	vector<int> vec{1, 2, 3};

	vector<string> vec1{"http://tiny.urleNm26h"};
	// vector<vector<int>> vec{{1, 3}, {2, 4}};
	Solution solution;
	auto res = solution.NumberOf1(2);
	//  print_vector(res);
	std::cout << res << std::endl;
}
 */
/*linux下：*/
 
/*linux下：*/
 
#include <stdio.h>
#include <unistd.h>
 
int main() {
    pid_t pid;
    pid = fork();
    if(pid  == 0) //返回子进程
    {
        printf("child pid: %d\n", getpid());
    } else {
        printf("pid: %d\n", pid);//父进程中返回子进程的pid
        printf("father pid: %d\n", getpid());
    }
}