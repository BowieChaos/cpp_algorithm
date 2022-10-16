#pragma once

#include "../../model/list_node.h"

// BM16 删除有序链表中重复的元素-II
// https://www.nowcoder.com/practice/71cef9f8b5564579bf7ed93fbe0b2024?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Delete2 {
public:
	/**
	 *
	 * @param head ListNode类
	 * @return ListNode类
	 */
	//  ListNode* deleteDuplicates(ListNode* head) {
	// 	if (head == nullptr) {
	// 		return head;
	// 	}
	// 	ListNode* ret = new ListNode(-1000000);
	// 	ret->next = head;
	// 	ListNode* pre = ret;
	// 	ListNode* cur = head;
	// 	bool duplicate = false;
	// 	while (cur != nullptr && cur->next != nullptr) {
	// 		if (cur->val == cur->next->val) {
	// 			cur->next = cur->next->next;
	// 			duplicate = true;
	// 		} else {
	// 			if (duplicate) {
	// 				duplicate = false;
	// 				ret->next = cur->next;
	// 			} else {
	// 				ret = cur;
	// 			}
	// 			cur = cur->next;
	// 		}
	// 	}
	// 	if (duplicate) {
	// 		ret->next = cur->next;
	// 	}
	// 	return pre->next;
	// }
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return head;
		}

		ListNode* ret = new ListNode(-10000);
		ret->next = head;
		ListNode* pre = ret;
		ListNode* cur = head;
		ListNode* next_node = head->next;
		while (next_node != nullptr) {
			if (cur->val != next_node->val) {
				pre = cur;
				cur = next_node;
				next_node = next_node->next;
			} else {
				while (next_node != nullptr && cur->val == next_node->val) {
					next_node = next_node->next;
				}
				if (next_node!=nullptr) {
					pre->next = next_node;
					cur = next_node;
					next_node = next_node->next;
				} else {
					pre->next = nullptr;
				}
			}
		}
		return ret;
	}
};