#pragma once

#include "../../model/list_node.h"
#include <queue>
#include <vector>
using namespace std;

// NC51 合并k个已排序的链表
// https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6?tpId=295&tqId=654&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj
class ListCompare {
public:
	bool operator()(ListNode* left, ListNode* right) {
		return left->val > right->val;
	}
};

class MergeKLists {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return nullptr;
		}

		ListNode* ret = new ListNode(-1);
		ListNode* cur = ret;

		for (auto iter = lists.begin(); iter != lists.end(); ) {
			if (*iter != nullptr) {
				iter++;
			} else {
				iter = lists.erase(iter);
			}
		}

		std::priority_queue<ListNode*, std::vector<ListNode*>, ListCompare>
		    pri_que(lists.begin(), lists.end());
		while (!pri_que.empty()) {
			ListNode* top = pri_que.top();
			cur->next = top;
			cur = cur->next;
			pri_que.pop();
			if (top->next != nullptr) {
				pri_que.emplace(top->next);
			}
		}
		return ret->next;
	}
};