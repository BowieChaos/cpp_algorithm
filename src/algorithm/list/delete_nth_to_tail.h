#pragma once

#include "../../model/list_node.h"

// NC53 删除链表的倒数第n个节点
// https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class DeleteNth {
public:
	/**
	 *
	 * @param head ListNode类
	 * @param n int整型
	 * @return ListNode类
	 */
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// write code here
		if (head == nullptr || n <= 0) {
			return nullptr;
		}

		ListNode* pre = new ListNode(-1);
		pre->next = head;
		ListNode* ret = pre;

		ListNode* fast = head;
		ListNode* slow = head;
		int count = 1;
		while (count < n) {
			count++;
			fast = fast->next;
		}
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
			pre = pre->next;
		}
		pre->next = pre->next->next;
		return ret->next;
	}
};