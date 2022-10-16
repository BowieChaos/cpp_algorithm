#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// NC6 二叉树中的最大路径和
// https://www.nowcoder.com/practice/da785ea0f64b442488c125b441a4ba4a?tpId=117&tqId=37716&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 *
	 * @param root TreeNode类
	 * @return int整型
	 */
	int ret = INT_MIN;
	int maxPathSum(TreeNode* root) {
		// write code here
		maxMathSumCore(root);
		return ret;
	}

	int maxMathSumCore(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int value = root->val;
		int maxL = maxMathSumCore(root->left);
		if (maxL > 0)
			value += maxL;
		int maxR = maxMathSumCore(root->right);
		if (maxR > 0)
			value += maxR;
		ret = max(ret, value);
		return (max(root->val, max(root->val + maxL, root->val + maxR)));
	}
};