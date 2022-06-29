#include "src/algorithm/list/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/binary_tree/all.h"
#include <iostream>
int main() {
	std::vector<int> vec{1,3,2,5};
	TreeNode* root1 = create_tree(vec);
	std::vector<int> vec1{2,1,3,-1,4,-1,7};
	TreeNode* root2 = create_tree(vec1);
	print_tree_pre_order(root1);
	std::cout <<std::endl;
	print_tree_in_order(root1);
	std::cout <<std::endl;
	print_tree_post_order(root1);
	std::cout <<std::endl;
	std::cout<<"================"<<std::endl;
	MergeTree solution;
	auto result = solution.mergeTrees(root1,root2);
	//print_vector(result);
	std::cout<<""<<std::endl;
	return 0;
}