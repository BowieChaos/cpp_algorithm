#pragma once

#include "../../model/list_node.h"

// https://www.nowcoder.com/practice/f23604257af94d939848729b1a5cda08?tpId=295&tqId=1008772&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class SortList {
public:
	/**
	 *
	 * @param head ListNode类 the head node
	 * @return ListNode类
	 */
	ListNode* sortInList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}

		ListNode* ret = new ListNode(-1);
		ret->next = head;

		ListNode* sorted = ret;
		while (sorted->next != nullptr) {
            ListNode* pre_cur = sorted;
            ListNode* cur = sorted->next;
            ListNode* pre_min = nullptr;
            ListNode* min_node = nullptr;
            while (cur!=nullptr) {
                if (min_node == nullptr || cur->val<min_node->val) {
                    min_node = cur;
                    pre_min = pre_cur;
                }
                pre_cur = pre_cur->next;
                cur = cur->next;
            }
            pre_min->next = pre_min->next->next;
            min_node->next = sorted->next;
            sorted->next = min_node;
            sorted = sorted->next;
		}
        return ret->next;
	}
};