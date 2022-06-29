#pragma once

#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x)
	    : val(x)
	    , left(nullptr)
	    , right(nullptr) {}
};

TreeNode* create_tree(std::vector<int>& vec) {
	TreeNode* root = nullptr;
	if (vec.empty()) {
		return root;
	}
	root = new TreeNode(vec[0]);
	std::queue<TreeNode*> que;
	que.emplace(root);
	for (size_t j = 1; j < vec.size();) {
		if (que.empty()) {
			break;
		}
		TreeNode* tmp_node = que.front();
		if (tmp_node == nullptr) {
            que.pop();
			continue;
		}
		if (vec[j] != -1) {
			tmp_node->left = new TreeNode(vec[j]);

		} else {
			tmp_node->left = nullptr;
		}
		que.emplace(tmp_node->left);
		if (j + 1 < vec.size()) {
			if (vec[j + 1] != -1) {
				tmp_node->right = new TreeNode(vec[j + 1]);
			} else {
				tmp_node->right = nullptr;
			}
            que.emplace(tmp_node->right);
		}
		que.pop();
		j = j + 2;
	}
	return root;
}

void print_tree_pre_order(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	std::cout << root->val << " ";
	print_tree_pre_order(root->left);
	print_tree_pre_order(root->right);
}

void print_tree_in_order(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	print_tree_in_order(root->left);
	std::cout << root->val << " ";
	print_tree_in_order(root->right);
}

void print_tree_post_order(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	print_tree_post_order(root->left);
	print_tree_post_order(root->right);
	std::cout << root->val << " ";
}