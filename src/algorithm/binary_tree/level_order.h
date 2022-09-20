#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// NC80 把二叉树打印成多行
// NC15 求二叉树的层序遍历
// https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=117&tqId=37832&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=
class LevelOrder {
public:
	/**
	 *
	 * @param root TreeNode类
	 * @return int整型vector<vector<>>
	 */
	vector<vector<int>> levelOrder(TreeNode* root) {
		// write code here
		vector<vector<int>> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}

		queue<TreeNode*> que_left;
		queue<TreeNode*> que_right;
		que_left.emplace(root);

		while (!que_left.empty()) {
			vector<int> tmp_vec;
			while (!que_left.empty()) {
				TreeNode* tmp_node = que_left.front();
				tmp_vec.emplace_back(tmp_node->val);
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