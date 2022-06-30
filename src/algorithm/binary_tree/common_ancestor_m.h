#pragma once

#include "../../model/b_tree.h"
#include <bits.h>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class CommonAncestor {
public:
	/**
	 *
	 * @param root TreeNode类
	 * @param o1 int整型
	 * @param o2 int整型
	 * @return int整型
	 */
	unordered_map<int, int> child_parent_map;
	unordered_set<int> path;
	int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
		// write code here
		construct_map(root);
        child_parent_map.emplace(root->val, -1);
        int target1 = o1;
        int target2 = o2;
		while (child_parent_map.find(target1) != child_parent_map.end()) {
            path.emplace(target1);
            target1 = child_parent_map[target1];
		}

        while (path.find(target2) == path.end()) {
            target2 = child_parent_map[target2];
        }
        return target2;
	}

	void construct_map(TreeNode* node) {
		if (node == nullptr) {
			return;
		}
		if (node->left != nullptr) {
			child_parent_map.emplace(
			    std::make_pair(node->left->val, node->val));
		}
		if (node->right != nullptr) {
			child_parent_map.emplace(
			    std::make_pair(node->right->val, node->val));
		}
		construct_map(node->left);
		construct_map(node->right);
		return;
	}

	int lowestCommonAncestor_recursion(TreeNode* root, int o1, int o2) {
		// write code here
		if (root == nullptr) {
			return -1;
		}
		return recursion_core(root, o1, o2)->val;
	}

	TreeNode* recursion_core(TreeNode* node, int o1, int o2) {
		if (node == nullptr || node->val == o1 || node->val == o2) {
			return node;
		}
		auto left = recursion_core(node->left, o1, o2);
		auto right = recursion_core(node->right, o1, o2);
		if (left == nullptr) {
			return right;
		}
		if (right == nullptr) {
			return left;
		}
		return node;
	}
};