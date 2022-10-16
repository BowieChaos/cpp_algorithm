#pragma once

#include "../../model/list_node.h"

// NC25 删除有序链表中重复的元素-I
// https://www.nowcoder.com/practice/c087914fae584da886a0091e877f2c79?tpId=295&tqId=1008769&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class DeleteDuplicate {
public:
	/**
	 *
	 * @param head ListNode类
	 * @return ListNode类
	 */
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		ListNode* cur = head;
		while (cur != nullptr && cur->next != nullptr) {
			if (cur->val == cur->next->val) {
				cur->next = cur->next->next;
			} else {
                cur = cur->next;
            }
		}
		return head;
	}
};