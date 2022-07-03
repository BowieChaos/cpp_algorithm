#include "src/algorithm/binary_tree/all.h"
#include "src/algorithm/list/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/stack_heap_queue/all.h"
#include "src/algorithm/hash/all.h"

#include <iostream>

void test() {
	vector<int> vec {1,4,1,6};
	AppearOnce solution;
	auto res = solution.FindNumsAppearOnce(vec);
	print_vector(res);
}
int main() {
	test();

	return 0;
}