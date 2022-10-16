#pragma once

#include "../../model/list_node.h"

// NC96 判断一个链表是否为回文结构
// https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f?tpId=295&tqId=1008769&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class IsPail {
public:
	/**
	 *
	 * @param head ListNode类 the head
	 * @return bool布尔型
	 */
	bool isPail(ListNode* head) {
		if (head == nullptr) {
			return true;
		}
		int vals[100004];
		ListNode* cur = head;
		int index = 0;
		while (cur != nullptr) {
			vals[index++] = cur->val;
			cur = cur->next;
		}

		for (int i = 0, j = index-1; i <= j; i++, j--) {
            if (vals[i] != vals[j]) {
                return false;
            }
		}
        return true;
	}
};