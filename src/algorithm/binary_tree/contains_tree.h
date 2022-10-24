#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// NC98 判断t1树中是否有与t2树完全相同的子树
// https://www.nowcoder.com/practice/4eaccec5ee8f4fe8a4309463b807a542?tpId=117&tqId=37776&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 *
	 * @param root1 TreeNode类
	 * @param root2 TreeNode类
	 * @return bool布尔型
	 */
	bool isContains(TreeNode* root1, TreeNode* root2) {
		// write code here
		if (root1 == nullptr && root2 == nullptr) {
			return true;
		}
		if (root1 == nullptr || root2 == nullptr) {
			return false;
		}

		if (root1->val != root2->val) {
			return isContains(root1->left, root2) || isContains(root1->right, root2);
		}

		return isContains(root1->left, root2->left) && isContains(root1->right, root2->right);
	}
};