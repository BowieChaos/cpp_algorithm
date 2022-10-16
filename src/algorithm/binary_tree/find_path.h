#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

//  NC8 二叉树中和为某一值的路径(二)
//  https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=117&tqId=37718&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class Solution {
public:
	vector<int> vec_vals;
	vector<TreeNode*> vec_nodes;

	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> ret;
		if (root == nullptr) {
			return ret;
		}
		traverse(root, ret, 0, expectNumber);
		return ret;
	}

	void traverse(TreeNode* node, vector<vector<int>>& ret, int count,
	              int expectNum) {
		if (node == nullptr) {
			return;
		}
		vec_vals.emplace_back(node->val);
		if (node->left == nullptr && node->right == nullptr) {
			if (count + node->val == expectNum) {
				ret.emplace_back(vec_vals);
			}
            
		} else {
            if (node->left != nullptr) {
                traverse(node->left, ret, count+node->val, expectNum);
            }
            if (node->right != nullptr) {
                traverse(node->right, ret, count+node->val, expectNum);
            }
        }
        vec_vals.pop_back();

	}
};