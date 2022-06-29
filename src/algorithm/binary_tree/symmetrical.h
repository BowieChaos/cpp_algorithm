#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;
// https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295

class Symmetrical {
public:
	bool isSymmetrical(TreeNode* pRoot) {
		if (pRoot == nullptr) {
			return true;
		}

		if (pRoot->left == nullptr || pRoot->right == nullptr) {
			if (pRoot->left != pRoot->right) {
				return false;
			} else {
				return true;
			}
		}
		return compareCore(pRoot->left, pRoot->right);
	}

	bool compareCore(TreeNode* left, TreeNode* right) {
		if (left == nullptr || right == nullptr) {
			if (left != right) {
				return false;
			} else {
				return true;
			}
		}
		if (left->val != right->val) {
			return false;
		}
		return compareCore(left->left, right->right) &&
		       compareCore(left->right, right->left);
	}
};