#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class LevelOrder {
public:
	/**
	 *
	 * @param root TreeNode类
	 * @return int整型vector<vector<>>
	 */
	vector<vector<int>> levelOrder(TreeNode* root) {
		// write code here
		vector<vector<int>> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}

		queue<TreeNode*> que_left;
		queue<TreeNode*> que_right;
		que_left.emplace(root);

		while (!que_left.empty()) {
			vector<int> tmp_vec;
			while (!que_left.empty()) {
				TreeNode* tmp_node = que_left.front();
				tmp_vec.emplace_back(tmp_node->val);
				que_left.pop();
				if (tmp_node->left != nullptr) {
					que_right.push(tmp_node->left);
				}
				if (tmp_node->right != nullptr) {
					que_right.push(tmp_node->right);
				}
			}
			ret_vec.emplace_back(tmp_vec);
			swap(que_left,que_right);
		}
		return ret_vec;
	}
};