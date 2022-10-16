#pragma once

#include "../../model/b_tree.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// NC9 二叉树中和为某一值的路径(一)
// https://www.nowcoder.com/practice/508378c0823c423baa723ce448cbfd0c?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

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