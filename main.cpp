#include "src/algorithm/binary_tree/all.h"
#include "src/algorithm/hash/all.h"
#include "src/algorithm/list/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/stack_heap_queue/all.h"
#include "src/algorithm/recursion_backtracking/all.h"
#include <iostream>

void test() {
	vector<int> vec{1,1,2};
	PermuteUnique solution;
	auto res = solution.permuteUnique(vec);
	// print_vector(res);
	std::cout << "fuck" << std::endl;
}
int main() {
	test();

	return 0;
}