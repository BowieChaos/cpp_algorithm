#include "src/algorithm/list/all.h"
#include <iostream>
int main() {
	std::vector<int> vec{1, 2 ,2};
	ListNode* head1 = create_list_node(vec);
	std::vector<int> vec2{6, 3};
	ListNode* head2 = create_list_node(vec2);
	std::vector<ListNode*> vecList{head1, head2};
	Delete2 solution;
	auto result = solution.deleteDuplicates(head1);
	print_list_node(result);
	return 0;
}