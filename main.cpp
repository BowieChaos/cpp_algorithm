#include "src/algorithm/list/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/binary_tree/all.h"
#include <iostream>
int main() {
	//test();

	return 0;
}

void test () {
	std::vector<int> vec{1,2,4,7,3,5,6,8};
	TreeNode* root1 = create_tree(vec);
	std::vector<int> vec1{4,7,2,1,5,3,8,6};
	TreeNode* root2 = create_tree(vec1);
	print_tree_pre_order(root1);
	std::cout <<std::endl;
	print_tree_in_order(root1);
	std::cout <<std::endl;
	print_tree_post_order(root1);
	std::cout <<std::endl;
	std::cout<<"================"<<std::endl;
	Construct solution;
	auto result = solution.reConstructBinaryTree(vec, vec1);
	//print_vector(result);
	std::cout<<""<<std::endl;
}