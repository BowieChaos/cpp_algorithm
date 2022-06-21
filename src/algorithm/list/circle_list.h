#pragma once

#include "../../model/list_node.h"

// https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class CircleList {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == pHead) {
			return pHead;
		}

        if (pHead->next == nullptr) {
            return nullptr;
        }

		ListNode* slow = pHead;
		ListNode* fast = pHead;
		ListNode* begin = nullptr;
		while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast && slow != nullptr) {
				begin = slow;
				break;
			}
		}
		if (slow == nullptr || fast == nullptr) {
			return nullptr;
		}

		slow = pHead;
		fast = begin;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};