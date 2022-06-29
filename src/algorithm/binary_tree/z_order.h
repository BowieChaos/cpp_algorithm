#pragma once

#include "../../model/b_tree.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Zorder {
public:
	vector<vector<int>> Print(TreeNode* pRoot) {
		// write code here
		vector<vector<int>> ret_vec;
		if (pRoot == nullptr) {
			return ret_vec;
		}

		queue<TreeNode*> que_left;
		queue<TreeNode*> que_right;
		que_left.emplace(pRoot);

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
			swap(que_left, que_right);
		}
		for (size_t i = 0; i < ret_vec.size(); i++) {
			if (i % 2 == 0) {
				continue;
			}
			std::reverse(ret_vec[i].begin(), ret_vec[i].end());
		}
		return ret_vec;
	}
};