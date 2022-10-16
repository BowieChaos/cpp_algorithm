#pragma once

#include "../../model/list_node.h"

// NC21 链表内指定区间反转
// https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class ReverseBetween {
public:
	/**
	 *
	 * @param head ListNode类
	 * @param m int整型
	 * @param n int整型
	 * @return ListNode类
	 */
	ListNode* reverse_between(ListNode* head, int m, int n) {
		if (head == nullptr) {
			return head;
		}

		ListNode* pre = new ListNode(-1);
		ListNode* ret = new ListNode(-1);
		ret->next = head;
		pre->next = head;
		ListNode* cur = head;

		int count = m;
		while (cur != nullptr && count > 1) {
			count--;
			pre = cur;
			cur = cur->next;
		}

		ListNode* p_next = head;
		count = n;
		while (count >= 1) {
			count--;
			p_next = p_next->next;
		}

		ListNode* tmp_pre = p_next;
		int i = 0;
		while (cur->next != nullptr && m + i < n) {
			auto tmp_next = cur->next;
			cur->next = tmp_pre;
			tmp_pre = cur;
			cur = tmp_next;
			i++;
		}
		cur->next = tmp_pre;
		pre->next = cur;

		if (m == 1) {
			return cur;
		}
		return ret->next;
	}
};