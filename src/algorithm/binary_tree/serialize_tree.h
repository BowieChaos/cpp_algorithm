#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Serial {
public:
	string ret_str;
	char* Serialize(TreeNode* root) {
		vector<int> vec_nodes = levelOrder(root);
		for (int vec_node : vec_nodes) {
			ret_str += to_string(vec_node);
			ret_str += ".";
		}
		return const_cast<char*>(ret_str.c_str());
	}
	TreeNode* Deserialize(char* str) {
		vector<int> vec_nodes;
		string s(str);
		string tmp;
		for (char i : s) {
			if (i == '.') {
				vec_nodes.emplace_back(stoi(tmp));
				tmp.clear();
				continue;
			}
			tmp.push_back(i);
		}

		return create_tree(vec_nodes);
	}

	vector<int> levelOrder(TreeNode* root) {
		// write code here
		vector<int> ret_vec;
		if (root == nullptr) {
			ret_vec.emplace_back(-1);
			return ret_vec;
		}

		queue<TreeNode*> que;
		que.emplace(root);
		while (!que.empty()) {
			TreeNode* tp = que.front();
			que.pop();
			if (tp == nullptr) {
				ret_vec.emplace_back(-1);
				continue;
			}
			ret_vec.emplace_back(tp->val);
			que.emplace(tp->left);
			que.emplace(tp->right);
		}
		return ret_vec;
	}

	TreeNode* create_tree(std::vector<int>& vec) {
		TreeNode* root = nullptr;
		if (vec.empty() || (vec.size() == 1 && vec[0] == -1)) {
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
};