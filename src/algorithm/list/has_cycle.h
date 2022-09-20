#pragma once

#include "../../model/list_node.h"

// NC4 判断链表中是否有环
// https://www.nowcoder.com/practice/650474f313294468a4ded3ce0f7898b9?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == nullptr) {
			return false;
		}

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast!=nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
	}
};