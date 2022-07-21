#include "src/algorithm/system_design/all.h"
#include <iostream>

void test() {
	vector<string> vec{"http:www.baidu.com", "http://www.nowcoder.com"};

	vector<string> vec1{"http://tiny.urleNm26h"};
	// vector<vector<int>> vec{{1, 3}, {2, 4}};
	ConHash solution;
	auto res = solution.consistentHashing(555, 8765421);
	// print_vector(res);
	std::cout << res << std::endl;
}
int main() {
	test();

	return 0;
}