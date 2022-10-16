#pragma once

#include "../../model/list_node.h"

// NC69 链表中倒数最后k个结点
// https://www.nowcoder.com/practice/886370fe658f41b498d40fb34ae76ff9?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class KthToTail {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param pHead ListNode类
	 * @param k int整型
	 * @return ListNode类
	 */
	ListNode* FindKthToTail(ListNode* pHead, int k) {
		if (pHead == nullptr || k <= 0) {
			return nullptr;
		}

		ListNode* slow = pHead;
		ListNode* fast = pHead;
		int count = 1;
		while (count < k && fast != nullptr) {
			count++;
			fast = fast->next;
		}
		if (fast == nullptr) {
			return nullptr;
		}

		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};