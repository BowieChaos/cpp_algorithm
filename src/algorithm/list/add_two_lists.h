#pragma once

#include "../../model/list_node.h"
#include <stack>
// https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b?tpId=295&tqId=1008772&ru=%2Fpractice%2F650474f313294468a4ded3ce0f7898b9&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class AddTwoLists {
public:
	/**
	 *
	 * @param head1 ListNode类
	 * @param head2 ListNode类
	 * @return ListNode类
	 */
	ListNode* addInList(ListNode* head1, ListNode* head2) { /*  */
		if (head1 == nullptr) {
			return head2;
		}
		if (head2 == nullptr) {
			return head1;
		}

		std::stack<int> stk_1;
		std::stack<int> stk_2;
		ListNode* cur_1 = head1;
		ListNode* cur_2 = head2;
		while (cur_1 != nullptr) {
			stk_1.emplace(cur_1->val);
			cur_1 = cur_1->next;
		}
		while (cur_2 != nullptr) {
			stk_2.emplace(cur_2->val);
			cur_2 = cur_2->next;
		}

		std::stack<int> stk_ret;
		int carry = 0;
		int sum = 0;
		while (!stk_1.empty() && !stk_2.empty()) {
			int add_1 = stk_1.top();
			int add_2 = stk_2.top();
			sum = (add_1 + add_2 + carry) % 10;
			carry = (add_1 + add_2 + carry) / 10;
			stk_ret.emplace(sum);
			stk_1.pop();
			stk_2.pop();
		}
		while (!stk_1.empty()) {
			int tp = stk_1.top();
			sum = (tp + carry) % 10;
			carry = (tp + carry) / 10;
			stk_ret.emplace(sum);
			stk_1.pop();
		}
		while (!stk_2.empty()) {
			int tp = stk_2.top();
			sum = (tp + carry) % 10;
			carry = (tp + carry) / 10;
			stk_ret.emplace(sum);
			stk_2.pop();
		}
		if (carry != 0) {
			stk_ret.emplace(carry);
		}

		ListNode* pre = new ListNode(-1);
		ListNode* cur = pre;
		while (!stk_ret.empty()) {
			int tp = stk_ret.top();
			ListNode* tmp_node = new ListNode(tp);
			cur->next = tmp_node;
			cur = cur->next;
			stk_ret.pop();
		}
		return pre->next;
	}
};