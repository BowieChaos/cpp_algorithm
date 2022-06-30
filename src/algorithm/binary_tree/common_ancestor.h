#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/d9820119321945f588ed6a26f0a6991f?tpId=295&tqId=2299105&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class BSTCommonAncestor {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param root TreeNode类
	 * @param p int整型
	 * @param q int整型
	 * @return int整型
	 */
	int lowestCommonAncestor(TreeNode* root, int p, int q) {
		// write code here

		TreeNode* cur_node = root;
		while (cur_node != nullptr) {
			if (cur_node->val == p || cur_node->val == q) {
				return cur_node->val;
			} else if (cur_node->val > std::max(p, q)) {
				cur_node = cur_node->left;
			} else if (cur_node->val < std::min(p, q)) {
				cur_node = cur_node->right;
			} else {
                return cur_node->val;
            }
		}
        return -1;
	}
};