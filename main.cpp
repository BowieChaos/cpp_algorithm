#include "src/algorithm/list/all.h"
#include "src/algorithm/sort/all.h"
#include "src/algorithm/binary_tree/all.h"
#include <iostream>
int main() {
	std::vector<int> vec{1,2,3,-1,-1,6,7};
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
	Serial solution;
	auto result = solution.Serialize(root1);
	auto root = solution.Deserialize(result);
	//print_vector(result);
	std::cout<<""<<std::endl;
	return 0;
}