#pragma once

#include "../../model/list_node.h"
#include <stack>
// https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class CommonNode {
public:
	/* 	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	        if (pHead1 == nullptr || pHead2 == nullptr) {
	            return nullptr;
	        }

	        size_t len_1 = 0;
	        size_t len_2 = 0;
	        ListNode* cur_1 = pHead1;
	        ListNode* cur_2 = pHead2;
	        while (cur_1 != nullptr || cur_2 != nullptr) {
	            if (cur_1 != nullptr) {
	                len_1++;
	                cur_1 = cur_1->next;
	            }
	            if (cur_2 != nullptr) {
	                len_2++;
	                cur_2 = cur_2->next;
	            }
	        }

	        cur_1 = pHead1;
	        cur_2 = pHead2;
	        if (len_1 != len_2) {
	            if (len_1 < len_2) {
	                for (size_t i = 0; i < len_2 - len_1; i++) {
	                    cur_2 = cur_2->next;
	                }
	            } else {
	                for (size_t i = 0; i < len_1 - len_2; i++) {
	                    cur_1 = cur_1->next;
	                }
	            }
	        }

	        while (cur_1 != nullptr && cur_2 != nullptr) {
	            if (cur_1 == cur_2) {
	                return cur_1;
	            }
	            cur_1 = cur_1->next;
	            cur_2 = cur_2->next;
	        }
	        return nullptr;
	    } */

	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		std::stack<ListNode*> stk_1;
		std::stack<ListNode*> stk_2;

		ListNode* cur_1 = pHead1;
		ListNode* cur_2 = pHead2;
		while (cur_1 != nullptr || cur_2 != nullptr) {
			if (cur_1 != nullptr) {
				stk_1.emplace(cur_1);
				cur_1 = cur_1->next;
			}
			if (cur_2 != nullptr) {
				stk_2.emplace(cur_2);
				cur_2 = cur_2->next;
			}
		}

		ListNode* ret = nullptr;
		while (!stk_1.empty() && !stk_2.empty()) {
			auto top_1 = stk_1.top();
			auto top_2 = stk_2.top();
			if (top_1 == top_2) {
				ret = top_1;
                stk_1.pop();
                stk_2.pop();
			} else {
				break;
			}
		}
        return ret;
	}
};