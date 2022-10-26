#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// BM34 判断是不是二叉搜索树
// https://www.nowcoder.com/practice/a69242b39baf45dea217815c7dedb52b?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295

int pre = INT_MIN;

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param root TreeNode类
	 * @return bool布尔型
	 */
	bool isValidBST(TreeNode* root) {
		// write code here
		if (root == nullptr) {
			return true;
		}

		if (!isValidBST(root->left)) {
			return false;
		}

		if (root->val <= pre) {
			return false;
		}
		pre = root->val;
		return isValidBST(root->right);
	}
};