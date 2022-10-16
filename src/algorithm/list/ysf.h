#pragma once
#include "../../model/list_node.h"
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/41c399fdb6004b31a6cbb047c641ed8a?tpId=117&tqId=37812&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=
// NC132 环形链表的约瑟夫问题

class YSF {
public:
	/**
	 *
	 * @param n int整型
	 * @param m int整型
	 * @return int整型
	 */
	int ysf(int n, int m) {
		// write code here
		ListNode* head = new ListNode(1);
		ListNode* cur = head;
		for (int i = 2; i <= n; i++) {
			ListNode* tmp = new ListNode(i);
			cur->next = tmp;
			cur = tmp;
		}
		cur->next = head;
		ListNode* pre = cur;
		cur = head;
		while (cur->next != cur) {
			for (int i = 1; i < m; i++) {
				pre = cur;
				cur = cur->next;
			}
			auto tmp = cur;
			cur = cur->next;
			pre->next = cur;
			delete tmp;
		}

		return cur->val;
	}
};