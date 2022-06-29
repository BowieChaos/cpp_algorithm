#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;
// https://www.nowcoder.com/practice/7298353c24cc42e3bd5f0e0bd3d1d759?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295

class MergeTree {
public:
	/**
	 *
	 * @param t1 TreeNode类
	 * @param t2 TreeNode类
	 * @return TreeNode类
	 */
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		// write code here
		if (t1 == nullptr) {
			return t2;
		}
		if (t2 == nullptr) {
			return t1;
		}

		TreeNode* cur = new TreeNode(t1->val + t2->val);
		cur->left = mergeTrees(t1->left, t2->left);
        cur->right = mergeTrees(t1->right, t2->right);
        return cur;
	}

	TreeNode* mergeTrees_1(TreeNode* t1, TreeNode* t2) {
		// write code here
		if (t1 == t2 && t1 == nullptr) {
			return t1;
		}
		int val = 0;
		if (t1 != nullptr) {
			val += t1->val;
		}
		if (t2 != nullptr) {
			val += t2->val;
		}
		TreeNode* ret_node = new TreeNode(val);

		if (t1 != nullptr && t2 != nullptr) {
			ret_node->left = mergeTrees(t1->left, t2->left);
			ret_node->right = mergeTrees(t1->right, t2->right);
		} else {
			if (t1 == nullptr) {
				ret_node->left = mergeTrees(nullptr, t2->left);
				ret_node->right = mergeTrees(nullptr, t2->right);
			} else {
				ret_node->left = mergeTrees(t1->left, nullptr);
				ret_node->right = mergeTrees(t1->right, nullptr);
			}
		}
		return ret_node;
	}
};