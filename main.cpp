#include "src/algorithm/other/all.h"
#include <iostream>
#include <map>
#include <set>
void test() {
	vector<int> vec{2, 1, 5, 3, 6, 4, 8, 9, 7};

	vector<string> vec1{"http://tiny.urleNm26h"};
	// vector<vector<int>> vec{{1, 3}, {2, 4}};
	BNMultiply solution;
	auto res = solution.solve("111", "0");
	// print_vector(res);
	std::cout << res << std::endl;
}
struct People {
	int age;
	bool dead;
};

int main() {
	int i = 0x12345678;

	if (*((char*)&i) == 0x12)
		cout << "big" << endl;
	else
		cout << "fuck" << endl;

	return 0;
}