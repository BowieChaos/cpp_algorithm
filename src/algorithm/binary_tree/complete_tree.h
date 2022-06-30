#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/8daa4dff9e36409abba2adbe413d6fae?tpId=295&tqId=2299105&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class CompleteTree {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param root TreeNode类
	 * @return bool布尔型
	 */
	bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            auto tp = que.front();
            que.pop();
            if (tp == nullptr) {

                while(!que.empty()) {
                    auto tp = que.front();
                    que.pop();
                    if (tp != nullptr) {
                        return false;
                    }
                }
                break;
            }
            que.push(tp->left);
            que.push(tp->right);
        }
        return true;
    }

	bool isCompleteTree_1(TreeNode* root) {
		vector<vector<TreeNode*>> vec_nodes = this->levelOrder(root);
		if (vec_nodes.empty()) {
			return false;
		}
		if (vec_nodes.size() == 1) {
			return true;
		}

		int len = vec_nodes.size();

		for (int i = 0, count = 1; i < len - 1; i++, count = count * 2) {
			if (count != vec_nodes[i].size()) {
				return false;
			}
		}

		auto& vec_last = vec_nodes[len - 1];
		auto& vec_last_two = vec_nodes[len - 2];
		int index = 0;
		while (index < vec_last.size()) {
			int parent_index = index / 2;
			if (index % 2 == 0) {
				if (vec_last_two[parent_index]->left != vec_last[index]) {
					return false;
				}
			} else {
				if (vec_last_two[parent_index]->right != vec_last[index]) {
					return false;
				}
			}
			index++;
		}

		return true;
	}

	vector<vector<TreeNode*>> levelOrder(TreeNode* root) {
		// write code here
		vector<vector<TreeNode*>> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}

		queue<TreeNode*> que_left;
		queue<TreeNode*> que_right;
		que_left.emplace(root);

		while (!que_left.empty()) {
			vector<TreeNode*> tmp_vec;
			while (!que_left.empty()) {
				TreeNode* tmp_node = que_left.front();
				tmp_vec.emplace_back(tmp_node);
				que_left.pop();
				if (tmp_node->left != nullptr) {
					que_right.push(tmp_node->left);
				}
				if (tmp_node->right != nullptr) {
					que_right.push(tmp_node->right);
				}
			}
			ret_vec.emplace_back(tmp_vec);
			swap(que_left, que_right);
		}
		return ret_vec;
	}
};