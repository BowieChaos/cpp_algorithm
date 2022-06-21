#include "src/algorithm/list/all.h"
#include <iostream>
int main() {
	std::vector<int> vec{1, 3, 5};
	ListNode* head1 = create_list_node(vec);
	std::vector<int> vec2{2, 4, 6};
	ListNode* head2 = create_list_node(vec2);
	std::vector<ListNode*> vecList{head1, head2};
	MergeKLists solution;
	auto result = solution.mergeKLists(vecList);
	print_list_node(result);
	return 0;
}