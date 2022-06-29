#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

class InOrder {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param root TreeNode类
	 * @return int整型vector
	 */
	vector<int> inorderTraversal(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}
		stack<TreeNode*> stk;
		TreeNode* cur_node = root;
		while (cur_node != nullptr || !stk.empty()) {
			if (cur_node != nullptr) {
                stk.emplace(cur_node);
                cur_node = cur_node->left;
			} else {
                cur_node = stk.top();
                stk.pop();
                ret_vec.emplace_back(cur_node->val);
                cur_node = cur_node->right;
			}
		}
		return ret_vec;
	}

    vector<int> inorderTraversal_recursion(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}
		in_recursion(root, ret_vec);
		return ret_vec;
	}

	void in_recursion(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		in_recursion(root->left, vec);
        vec.emplace_back(root->val);
		in_recursion(root->right, vec);
	}
};