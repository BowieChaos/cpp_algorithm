
#pragma once

#include <iostream>
#include <vector>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

void print_list_node (ListNode* head) {
	if (head == nullptr) {
		std::cout<<"empty list"<<std::endl;
	}

	while (head != nullptr) {
		std::cout<<head->val<<" "<<std::endl;
		head = head->next;
	}
}

ListNode* create_list_node (const std::vector<int>& vec) {
	if (vec.empty()) 
	{
		return nullptr;
	}

	ListNode* pre = new ListNode(-1);
	ListNode* ret_pre = pre;

	for (auto val : vec) {
		ListNode* tmp_node = new ListNode(val);
		pre->next = tmp_node;
		pre = pre->next;
	}
	return ret_pre->next;
}