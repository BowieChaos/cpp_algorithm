#pragma once

#include "../../model/b_tree.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class PathSum {
public:
	/**
	 *
	 * @param root TreeNode类
	 * @param sum int整型
	 * @return bool布尔型
	 */
	bool hasPathSum(TreeNode* root, int sum) {
		// write code here
		if (root == nullptr) {
			return false;
		}

		if (root->left == nullptr && root->right == nullptr &&
		    root->val == sum) {
			return true;
		}

		return pathSumCore(root->left, sum, root->val) ||
		       pathSumCore(root->right, sum, root->val);
	}

	bool pathSumCore(TreeNode* node, int sum, int cur_val) {
		if (node == nullptr) {
			return false;
		}

		if (node->left == nullptr && node->right == nullptr &&
		    sum == cur_val + node->val) {
			return true;
		}

		return pathSumCore(node->left, sum, cur_val + node->val) ||
		       pathSumCore(node->right, sum, cur_val + node->val);
	}
};