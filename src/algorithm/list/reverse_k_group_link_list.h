#pragma once

#include "../../model/list_node.h"
// https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj
class ReverseKGroup {
public:
	/**
	 *
	 * @param head ListNode类
	 * @param k int整型
	 * @return ListNode类
	 */
	ListNode* reverseKGroup(ListNode* head, int k) {
		// write code here
		if (head == nullptr || k <= 0) {
			return head;
		}

		ListNode* ret = new ListNode(-1);
		ret->next = head;
		ListNode* needle = ret;
		ListNode* cur = head;

		while (true) {

			if (cur == nullptr)
				break;
			ListNode* tmp_head = cur;
			ListNode* tail = cur;

			int count = 1;
			while (count < k && tail != nullptr) {
				++count;
				tail = tail->next;
			}

			if (count != k || tail == nullptr) {
				break;
			}
			cur = tail->next;
			tail->next = nullptr;
			ListNode* new_head = this->reverse(tmp_head);
			tmp_head->next = cur;
			needle->next = new_head;
			needle = tmp_head;
		}
		return ret->next;
	}

	ListNode* reverse(ListNode* head) {
		if (head == nullptr) {
			return head;
		}

		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur->next != nullptr) {
			auto tmp_next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp_next;
		}
		cur->next = pre;
		return cur;
	}
};