#include "src/algorithm/dynamic_programming/all.h"
#include "src/algorithm/hash/all.h"
#include "src/algorithm/list/all.h"
#include "src/algorithm/other/all.h"
#include "src/algorithm/recursion_backtracking/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/string/all.h"
#include <iostream>

void test() {
	vector<vector<int>> vec{{1, 1, 1}, {1, 2, 2}, {1, 3, 3}, {1, 4, 4}, {2, 4},
	                        {2, 3},    {2, 2},    {2, 1},    {1, 5, 5}, {2, 4}};
	// vector<vector<int>> vec{{1, 3}, {2, 4}};
	vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 0};
	Inverse solution;
	auto res = solution.InversePairs(vec1);
	print_vector(vec1);
	std::cout << res << std::endl;
}
int main() {
	test();

	return 0;
}