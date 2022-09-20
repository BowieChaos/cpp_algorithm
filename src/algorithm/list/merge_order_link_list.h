#pragma once

#include "../../model/list_node.h"

// NC33 合并两个排序的链表
// https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj
class MergeOrderList {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr) {
			return pHead2;
		}
		if (pHead2 == nullptr) {
			return pHead1;
		}

		ListNode* ret = new ListNode(-1);
		ListNode* cur = ret;
		ListNode* cur_1 = pHead1;
		ListNode* cur_2 = pHead2;
		while (cur_1 != nullptr && cur_2 != nullptr) {
			if (cur_1->val < cur_2->val) {
				cur->next = cur_1;
				cur = cur->next;
				cur_1 = cur_1->next;
			} else {
				cur->next = cur_2;
				cur = cur->next;
				cur_2 = cur_2->next;
			}
		}
		if (cur_1 != nullptr) {
			cur->next = cur_1;
		}

		if (cur_2 != nullptr) {
			cur->next = cur_2;
		}
		return ret->next;
	}
};