#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	 *
	 * @param root TreeNode类
	 * @return int整型
	 */
	int maxDepth(TreeNode* root) {
		// write code here
		if (root == nullptr) {
			return 0;
		}
		return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};