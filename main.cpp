#include "src/algorithm/dynamic_programming/all.h"
#include <iostream>
#include <set>
#include <map>
void test() {
	vector<int> vec{2, 1, 5, 3, 6, 4, 8, 9, 7};

	vector<string> vec1{"http://tiny.urleNm26h"};
	// vector<vector<int>> vec{{1, 3}, {2, 4}};
	ChessFlip solution;
	auto res = solution.solve(4, 10);
	//print_vector(res);
	std::cout << res << std::endl;
}
struct People
{
	int age;
	bool dead;
};


int main() {
	test();

	return 0;
}