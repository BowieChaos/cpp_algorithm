#include "src/algorithm/list/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/binary_tree/all.h"
#include <iostream>
int main() {
	std::vector<int> vec{1,2,3};
	TreeNode* root1 = create_tree(vec);
	print_tree_pre_order(root1);
	std::cout <<std::endl;
	print_tree_in_order(root1);
	std::cout <<std::endl;
	print_tree_post_order(root1);
	std::cout <<std::endl;
	std::cout<<"================"<<std::endl;
	Zorder solution;
	auto result = solution.Print(root1);
	//print_vector(result);
	std::cout<<""<<std::endl;
	return 0;
}