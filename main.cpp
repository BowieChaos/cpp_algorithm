#include "src/algorithm/dynamic_programming/all.h"
#include "src/algorithm/hash/all.h"
#include "src/algorithm/list/all.h"
#include "src/algorithm/other/all.h"
#include "src/algorithm/recursion_backtracking/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/stack_heap_queue/all.h"
#include "src/algorithm/string/all.h"
#include <iostream>

void test() {
	// vector<vector<int>> vec{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> vec{2,2,3,4,3};
	MaxLength solution;
	int s[6] = {4, 6, 6, 0, 0, 0};
	int r[3] = {1, 2, 3};
	auto res = solution.maxLength(vec);
	// print_vector(res);
	std::cout << res << std::endl;
}
int main() {
	test();

	return 0;
}