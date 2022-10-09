#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// NC13 二叉树的最大深度
// https://www.nowcoder.com/practice/8a2b2bf6c19b4f23a9bdb9b233eefa73?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class MaxPath {
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