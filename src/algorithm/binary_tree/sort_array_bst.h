#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// NC11 将升序数组转化为平衡二叉搜索树
// https://www.nowcoder.com/practice/7e5b00f94b254da599a9472fe5ab283d?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	/**
	 *
	 * @param num int整型vector
	 * @return TreeNode类
	 */
	TreeNode* sortedArrayToBST(vector<int>& num) {
		// write code here
		if (num.empty()) {
			return nullptr;
		}
		TreeNode* root = createBST(num, 0, num.size() - 1);
		return root;
	}

	TreeNode* createBST(vector<int>& num, int left, int right) {
		if (left > right) {
			return nullptr;
		}
		int mid = (left + right) / 2;
		TreeNode* node = new TreeNode(num[mid]);
		node->left = createBST(num, left, mid - 1);
		node->right = createBST(num, mid + 1, right);
		return node;
	}
};