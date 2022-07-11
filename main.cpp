#include "src/algorithm/hash/all.h"
#include "src/algorithm/list/all.h"
#include "src/algorithm/recursion_backtracking/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/stack_heap_queue/all.h"
#include "src/algorithm/dynamic_programming/all.h"
#include <iostream>

void test() {
	//vector<vector<int>> vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> vec{1,100,1,1,1,90,1,1,80,1};
	EditDistance solution;
	auto res = solution.editDistance("aaa", "a");
	//print_vector(res);
	std::cout << res << std::endl;
}
int main() {
	test();

	return 0;
}