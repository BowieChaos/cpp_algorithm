#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

class PreOrder {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param root TreeNode类
	 * @return int整型vector
	 */

	vector<int> preorderTraversal(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}

		stack<TreeNode*> stk;
		auto cur_node = root;
		while (cur_node != nullptr || !stk.empty()) {
			if (cur_node != nullptr) {
				ret_vec.emplace_back(cur_node->val);
                stk.emplace(cur_node);
                cur_node = cur_node->left;
			} else {
                cur_node = stk.top();
                stk.pop();
                cur_node = cur_node->right;
			}
		}
		return ret_vec;
	}

	vector<int> preorderTraversal_1(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}

		stack<TreeNode*> stk;
		stk.emplace(root);

		while (!stk.empty()) {
			auto tmp = stk.top();
			ret_vec.emplace_back(tmp->val);
			stk.pop();
			if (tmp->left != nullptr) {
				stk.emplace(tmp->left);
			}
			if (tmp->right != nullptr) {
				stk.emplace(tmp->right);
			}
		}
		return ret_vec;
	}

	vector<int> preorderTraversal_recursion(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}
		pre_recursion(root, ret_vec);
		return ret_vec;
	}

	void pre_recursion(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		vec.emplace_back(root->val);
		pre_recursion(root->left, vec);
		pre_recursion(root->right, vec);
	}
};