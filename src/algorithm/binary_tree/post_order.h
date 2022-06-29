#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

class PostOrder {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param root TreeNode类
	 * @return int整型vector
	 */
	vector<int> postorderTraversal(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}
		stack<TreeNode*> stk;
		stk.emplace(root);
		TreeNode* pre_node = nullptr;
		while (!stk.empty()) {
			TreeNode* cur = stk.top();
			if ((cur->left == nullptr && cur->right == nullptr) ||
			    (pre_node != nullptr &&
			     (pre_node == cur->left || pre_node == cur->right))) {
				ret_vec.emplace_back(cur->val);
                stk.pop();
                pre_node = cur;
			} else {
				if (cur->right != nullptr) {
					stk.emplace(cur->right);
				}
				if (cur->left != nullptr) {
					stk.emplace(cur->left);
				}
			}
		}
		return ret_vec;
	}

	vector<int> postorderTraversal_recursion(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}
		post_recursion(root, ret_vec);
		return ret_vec;
	}

	void post_recursion(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		post_recursion(root->left, vec);
		post_recursion(root->right, vec);
		vec.emplace_back(root->val);
	}
};