#pragma once

#include "../../model/b_tree.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// NC58 找到搜索二叉树中两个错误的节点
// https://www.nowcoder.com/practice/4582efa5ffe949cc80c136eeb78795d6?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	/**
	 *
	 * @param root TreeNode类 the root
	 * @return int整型vector
	 */
	vector<int> findError(TreeNode* root) {
		// write code here
		vector<int> ret;
		if (root == nullptr) {
			return ret;
		}
		vector<int> vals;
		TreeNode* cur = root;
		stack<TreeNode*> stk;
		while (cur != nullptr || !stk.empty()) {
			if (cur != nullptr) {
				stk.push(cur);
				cur = cur->left;
			} else {
				cur = stk.top();
				stk.pop();
				vals.emplace_back(cur->val);
				cur = cur->right;
			}
		}
		int left, right;
		for (int i = 0; i < vals.size() - 1; i++) {
			if (vals[i] > vals[i + 1]) {
				left = i;
				break;
			}
		}

		for (int j = vals.size() - 1; j > left; j--) {
			if (vals[j] < vals[j - 1]) {
				right = j;
				break;
			}
		}
		ret.emplace_back(vals[left]);
		ret.emplace_back(vals[right]);

		sort(ret.begin(), ret.end());
		return ret;
	}
};